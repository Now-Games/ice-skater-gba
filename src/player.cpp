#include "gameObjects/player.h"
#include "scene.h"
#include "bn_core.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_items_player_sheet.h"
#include "bn_sprite_items_player_fall_sheet.h"
#include "game_constants.h"

Player::Player(Scene *scene, int posX, int posY, Direction dir) : 
    GameObject(scene, posX, posY, GameObjectType::GOT_Player, bn::sprite_items::player_sheet)
{
    sprite->set_z_order(3);

    fallAnim = bn::create_sprite_animate_action_once(sprite.value(), 4, 
                       bn::sprite_items::player_fall_sheet.tiles_item(), 
                       1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17);

    setDirection(dir);

    moveComponent = bn::unique_ptr(new MoveComponent(this, 4));
    addComponent(moveComponent.get());
    addComponent(new ColliderComponent(this, 16, 16));
}

void Player::setDirection(Direction dir)
{
    if (direction == dir) {
        BN_LOG("Player is already facing this direction");
        return;
    }
    
    direction = dir;
    sprite->set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(direction));
}

void Player::getInput()
{
    Direction newDirection = direction;
    bool inputPressed = false;

    if (bn::keypad::up_pressed())
    {
        newDirection = Direction::Up;
        inputPressed = true;
    }
    else if (bn::keypad::down_pressed())
    {
        newDirection = Direction::Down;
        inputPressed = true;
    }
    else if (bn::keypad::left_pressed())
    {
        newDirection = Direction::Left;
        inputPressed = true;
    }
    else if (bn::keypad::right_pressed())
    {
        newDirection = Direction::Right;
        inputPressed = true;
    }

    if (!inputPressed)
        return;

    if (direction != newDirection)
        setDirection(newDirection);

    setNextTarget();
}

void Player::setNextTarget()
{
    int dx = 0;
    int dy = 0;

    switch (direction)
    {
        case Direction::Up:
            dy = -BLOCK_SIZE * 2;
            break;
        case Direction::Down:
            dy = BLOCK_SIZE * 2;
            break;
        case Direction::Left:
            dx = -BLOCK_SIZE * 2;
            break;
        case Direction::Right:
            dx = BLOCK_SIZE * 2;
            break;
        default:
            break;
    }

    if (!(dx == 0 && dy == 0) && currentScene->isEmptySpace(getComponent<ColliderComponent>(), dx, dy))
    {
        constantMoving = true;
        moveComponent->setTargetPosition(x + dx, y + dy);
    }
    else {
        constantMoving = false;
    }
}

void Player::update()
{
    if (!constantMoving)
        getInput();
    else 
    {
        moveComponent->update();
        if (!moveComponent->isMoving())
            setNextTarget();
    }
}

void Player::playFallingAnimation()
{
    while (!fallAnim->done())
    {
        BN_LOG("Player falling");
        fallAnim->update();
        bn::core::update();
    }
}