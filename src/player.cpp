#include "player.h"
#include "bn_core.h"
#include "bn_log.h"
#include "bn_keypad.h"
#include "bn_sprite_items_player_sheet.h"
#include "bn_sprite_items_player_fall_sheet.h"

Player::Player(bn::fixed_point pos, Direction dir) : 
    sprite(bn::sprite_items::player_sheet.create_sprite(pos * 8)),
    position(pos * 8)
{
    sprite.set_z_order(4);
    fallAnim = bn::create_sprite_animate_action_once(sprite, 4, 
                       bn::sprite_items::player_fall_sheet.tiles_item(), 
                       1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17);
    
    setDirection(dir);
}

void Player::setDirection(Direction dir)
{
    if (direction == dir) {
        BN_LOG("Player is already facing this direction");
        return;
    }
    
    direction = dir;
    sprite.set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(direction));
}

Direction Player::getDirection()
{
    return direction;
}

bn::fixed_point Player::getPosition()
{
    return position;
}

void Player::setPosition(bn::fixed_point pos)
{
    this->position = pos;
    sprite.set_position(pos);
}

void Player::setMoveLimit(bn::fixed_point newPos)
{
    if (moveLimit == newPos)
        return;
    
    moving = true;
    moveLimit = newPos;
    BN_LOG("Move Limit X: ", moveLimit.x());
    BN_LOG("Move Limit Y: ", moveLimit.y());
}

bool Player::isMoving()
{
    return moving;
}

void Player::move(Direction dir)
{
    bn::fixed_point delta;
    switch (dir)
    {
        case Direction::Up:
            delta = bn::fixed_point(0, -moveSpeed);
            break;
        case Direction::Down:
            delta = bn::fixed_point(0, moveSpeed);
            break;
        case Direction::Left:
            delta = bn::fixed_point(-moveSpeed, 0);
            break;
        case Direction::Right:
            delta = bn::fixed_point(moveSpeed, 0);
        default:
            break;
    }
    
    position += delta;
    if ((dir == Direction::Right && position.x() > moveLimit.x()) ||
            (dir == Direction::Left && position.x() < moveLimit.x()) ||
            (dir == Direction::Down && position.y() > moveLimit.y()) ||
            (dir == Direction::Up && position.y() < moveLimit.y()))
    {
        position = moveLimit;
        moving = false;
        BN_LOG("Player move is finished");
    }
    
    sprite.set_position(position);
}

void Player::update()
{
    if (!moving)
        return;
    
    move(direction);
}

void Player::playFallingAnimation()
{
    while (!fallAnim->done())
    {
        fallAnim->update();
        bn::core::update();
    }
}