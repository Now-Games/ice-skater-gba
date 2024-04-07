#include "components/move_component.h"
#include "gameObjects/game_object.h"

MoveComponent::MoveComponent(GameObject *p, int spd) : BaseComponent(p)
{
    speed = spd;
    targetX = 0;
    targetY = 0;
}

bool MoveComponent::isMoving()
{
    return moving;
}

void MoveComponent::setMoving(bool b)
{
    moving = b;
}

void MoveComponent::setTargetPosition(int newX, int newY)
{
    targetX = newX;
    targetY = newY;
    if (targetX != parent->getX() && targetY != parent->getY())
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
    int dx = 0;
    int dy = 0;
    bool passedTarget = false;

    switch (parent->getDirection())
    {
        case Direction::Down:
            dy = speed;
            if (parent->getY() + speed > targetY)
                passedTarget = true;
            break;
        case Direction::Left:
            dx = -speed;
            if (parent->getX() - speed < targetX)
                passedTarget = true;
            break;
        case Direction::Right:
            dx = speed;
            if (parent->getX() + speed > targetX)
                passedTarget = true;
            break;
        case Direction::Up:
            dy = -speed;
            if (parent->getY() - speed < targetY)
                passedTarget = true;
            break;
        default:
            break;
    }
       
    if (passedTarget)
        parent->setPosition(targetX, targetY);
    else
        parent->setPosition(parent->getX() + dx, parent->getY() + dy);

    if (parent->getX() == targetX && parent->getY() == targetY)
        moving = false;
}