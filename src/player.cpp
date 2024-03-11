#include "player.h"
#include "bn_core.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_items_player_sheet.h"
#include "bn_sprite_items_player_fall_sheet.h"
#include "game_constants.h"

Player::Player(Scene *scene, bn::fixed_point pos, Direction dir) : 
    GameObject(pos, bn::sprite_items::player_sheet),
    moveComponent(this, 4),
    colliderComponent(this, 16, 16)
{
    fallAnim = bn::create_sprite_animate_action_once(sprite.value(), 4, 
                       bn::sprite_items::player_fall_sheet.tiles_item(), 
                       1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17);

    currentScene = bn::unique_ptr(scene);
    setDirection(dir);
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

MoveComponent* Player::getMoveComponent()
{
    return &moveComponent;
}

ColliderComponent* Player::getColliderComponent()
{
    return &colliderComponent;
}

void Player::getInput()
{
    Direction newDirection = direction;
    bn::fixed_point limits = bn::fixed_point();

    if (bn::keypad::up_pressed())
    {
        newDirection = Direction::Up;
        limits = bn::fixed_point(position.x(), MIN_Y);
    }
    else if (bn::keypad::down_pressed())
    {
        newDirection = Direction::Down;
        limits = bn::fixed_point(position.x(), MAX_Y);
    }
    else if (bn::keypad::left_pressed())
    {
        newDirection = Direction::Left;
        limits = bn::fixed_point(MIN_X, position.y());
    }
    else if (bn::keypad::right_pressed())
    {
        newDirection = Direction::Right;
        limits = bn::fixed_point(MAX_X, position.y());
    }

    setDirection(newDirection);
    int obstacleIndex = currentScene->getNextObstacle(position, newDirection);
    if (obstacleIndex == -1)
        moveComponent.setPosition(limits); //Set the move position limit to the obstacle's stopping position based on direction
    else
        BN_LOG("Stop at the Object's stopping point");
}

void Player::update()
{
    getInput();
    moveComponent.update();
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