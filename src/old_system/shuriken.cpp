#include "gameObjects/shuriken.h"
#include "components/collider_component.h"
#include "game_constants.h"

Shuriken::Shuriken(Scene* scene, int posX, int posY, bn::sprite_item spritesheet) : GameObject(scene, posX, posY, GameObjectType::GOT_Shuriken, spritesheet)
{
    
}

void Shuriken::changeDirection()
{
    int dx = 0;
    int dy = 0;
    //set Direction to the opposite
    switch (direction)
    {
        case Direction::Up:
            setDirection(Direction::Down);
            dy = -BLOCK_SIZE * 2;
            break;
        case Direction::Down:
            setDirection(Direction::Up);
            dy = BLOCK_SIZE * 2;
            break;
        case Direction::Left:
            setDirection(Direction::Right);
            dx = -BLOCK_SIZE * 2;
            break;
        case Direction::Right:
            setDirection(Direction::Left);
            dx = BLOCK_SIZE * 2;
            break;
        default:
            break;
    }

    //Check the closest obstacle in the scene to hit and set the move limit
    if (currentScene->isEmptySpace(getComponent<ColliderComponent>(), dx, dy)) 
    {
        //TODO: set the move position to the next spot
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