#include "gameObjects/player.h"
#include "scene.h"
#include "bn_core.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_items_player_sheet.h"
#include "bn_sprite_items_player_fall_sheet.h"
#include "game_constants.h"

Player::Player(Scene *scene, bn::fixed_point pos, Direction dir) : 
    GameObject(scene, pos, GameObjectType::GOT_Player, bn::sprite_items::player_sheet)
{
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
    bn::fixed_point limits = bn::fixed_point();
    bn::fixed_point nextPosition = getPosition();
    bool inputPressed = false;

    if (bn::keypad::up_held())
    {
        newDirection = Direction::Up;
        limits = bn::fixed_point(position.x(), MIN_Y);
        nextPosition += bn::fixed_point(0, -BLOCK_SIZE * 2);
    }
    else if (bn::keypad::down_held())
    {
        newDirection = Direction::Down;
        limits = bn::fixed_point(position.x(), MAX_Y);
        nextPosition += bn::fixed_point(0, BLOCK_SIZE * 2);
    }
    else if (bn::keypad::left_held())
    {
        newDirection = Direction::Left;
        limits = bn::fixed_point(MIN_X, position.y());
        nextPosition += bn::fixed_point(-BLOCK_SIZE * 2, 0);
    }
    else if (bn::keypad::right_held())
    {
        newDirection = Direction::Right;
        limits = bn::fixed_point(MAX_X, position.y());
        nextPosition += bn::fixed_point(BLOCK_SIZE * 2, 0);
    }

    setDirection(newDirection);

    if (currentScene->isEmptySpace(this))
    {
        moveComponent->setTargetPosition(nextPosition);
    }
}

void Player::update()
{
    getInput();
    moveComponent->update();
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