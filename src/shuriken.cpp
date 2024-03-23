#include "gameObjects/shuriken.h"

Shuriken::Shuriken(Scene* scene, bn::fixed_point pos, bn::sprite_item spritesheet) : GameObject(scene, pos, GameObjectType::GOT_Shuriken, spritesheet)
{
    
}

void Shuriken::changeDirection()
{
    //set Direction to the opposite
    switch (direction)
    {
        case Direction::Up:
            setDirection(Direction::Down);
            break;
        case Direction::Down:
            setDirection(Direction::Up);
            break;
        case Direction::Left:
            setDirection(Direction::Right);
            break;
        case Direction::Right:
            setDirection(Direction::Left);
            break;
        default:
            break;
    }

    //Check the closest obstacle in the scene to hit and set the move limit
    int obstacleIndex = currentScene->getNextObstacle(position, direction);
    if (obstacleIndex == -1) {
        //TODO: Set moveComponent limit to the limits of the scene
    }
    else {
        //TODO: Set moveComponent limit to the obstacle's stopping position
    }
}

void Shuriken::update()
{
    if (moveComponent == nullptr)
        moveComponent = bn::unique_ptr(getComponent<MoveComponent>());

    moveComponent->update();
    if (!moveComponent->isMoving())
        changeDirection();
}