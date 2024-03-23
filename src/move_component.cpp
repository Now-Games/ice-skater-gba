#include "move_component.h"
#include "game_object.h"

MoveComponent::MoveComponent(GameObject *p, int spd) : BaseComponent(p)
{
    speed = spd;
    targetPosition = parent->getPosition();
}

bool MoveComponent::isMoving()
{
    return moving;
}

void MoveComponent::setPosition(bn::fixed_point newPos)
{
    targetPosition = newPos;
    if (targetPosition != parent->getPosition())
        moving = true;
}

void MoveComponent::update()
{
    if (!moving)
        return;

    move();
}

void MoveComponent::move()
{
    bn::fixed_point dPos = bn::fixed_point();
    bool passedTarget = false;

    switch (parent->getDirection())
    {
        case Direction::Down:
            dPos = bn::fixed_point(0, speed);
            if (parent->getPosition().y() + speed > targetPosition.y())
                passedTarget = true;
            break;
        case Direction::Left:
            dPos = bn::fixed_point(-speed, 0);
            if (parent->getPosition().x() - speed < targetPosition.x())
                passedTarget = true;
            break;
        case Direction::Right:
            dPos = bn::fixed_point(speed, 0);
            if (parent->getPosition().x() + speed > targetPosition.x())
                passedTarget = true;
            break;
        case Direction::Up:
            dPos = bn::fixed_point(0, -speed);
            if (parent->getPosition().x() - speed < targetPosition.x())
                passedTarget = true;
            break;
        default:
            break;
    }

    if (passedTarget)
        parent->setPosition(targetPosition);
    else
        parent->setPosition(parent->getPosition() + dPos);
    
    if (parent->getPosition() == targetPosition)
        moving = false;
}