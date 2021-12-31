#include "is_player.h"

namespace is {
player::player(bn::fixed x, bn::fixed y, direction _dir) : _position(x, y)
{
    player_facing = _dir;
    isMoving = false;
    _move_limit = bn::fixed_point(max_x, max_y);
    _sprite = bn::sprite_items::player_sheet.create_sprite(_position.x(), _position.y());
    _sprite->set_z_order(0);
}

player::~player()
{

}

void player::set_player_direction(direction _dir)
{
    player_facing = _dir;
    set_sprite_direction();
}

void player::set_position(bn::fixed_point position) {
    _position = position;
    _sprite.value().set_x(_position.x());
    _sprite.value().set_y(_position.y());
}

direction player::get_direction() {
    return player_facing;
}

bn::fixed_point player::get_position() {
    return _position;
}

bn::fixed_point player::get_move_limit() {
    return _move_limit;
}

void player::set_move_limit(bn::fixed x, bn::fixed y) {
    _move_limit = bn::fixed_point(x, y);
}

void player::set_sprite_direction()
{
    switch (player_facing) {
    case LEFT:
        _sprite->set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(2));
        break;
    case RIGHT:
        _sprite->set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(3));
        break;
    case UP:
        _sprite->set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(0));
        break;
    case DOWN:
        _sprite->set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(1));
        break;
    default:
        break;
    }
}

void player::play_fall_anim()
{
    _sprite->set_tiles(bn::sprite_items::player_fall_sheet.tiles_item().create_tiles(0));
    _fall_animation = bn::create_sprite_animate_action_once(_sprite.value(), 4,
                            bn::sprite_items::player_fall_sheet.tiles_item(), 1, 2, 3, 4, 5, 6, 7, 8, 9,
                                                            10, 11, 12, 13, 14, 15, 16, 17, 17, 17, 17);
    while (!_fall_animation->done()) {
        _fall_animation->update();
        bn::core::update();
    }
}

void player::move(bn::fixed dx, bn::fixed dy)
{
    bn::fixed new_x = _sprite.value().x() + dx;
    bn::fixed new_y = _sprite.value().y() + dy;

    if (new_x <= max_x-8 && new_x >= min_x+8 && new_y <= max_y-8 && new_y >= min_y+8) {
        if ((player_facing == direction::LEFT && new_x >= _move_limit.x()) ||
                (player_facing == direction::RIGHT && new_x <= _move_limit.x()) ||
                (player_facing == direction::UP && new_y >= _move_limit.y()) ||
                (player_facing == direction::DOWN && new_y <= _move_limit.y())) {
            _sprite.value().set_x(new_x);
            _sprite.value().set_y(new_y);
            _position.set_x(_sprite.value().x());
            _position.set_y(_sprite.value().y());
        }
    }
    else {
        BN_LOG("Player Position x: ", _position.x());
        BN_LOG("Player Position y: ", _position.y());
        isMoving = false;
    }
}

void player::update()
{
    if (initialDraw) {
        set_sprite_direction();
        initialDraw = false;
    }

    if (!isMoving) {
        if (bn::keypad::left_pressed()) {
            BN_LOG("Player moving Left");
            player_facing = direction::LEFT;
            isMoving = true;
        }
        else if (bn::keypad::right_pressed()) {
            BN_LOG("Player moving Right");
            player_facing = direction::RIGHT;
            isMoving = true;
        }
        else if (bn::keypad::up_pressed()) {
            BN_LOG("Player moving Up");
            player_facing = direction::UP;
            isMoving = true;
        }
        else if (bn::keypad::down_pressed()) {
            BN_LOG("Player moving Down");
            player_facing = direction::DOWN;
            isMoving = true;
        }

        if (bn::keypad::any_pressed()) {
            set_sprite_direction();
        }
    }
    else {
        if (_position.x() != _move_limit.x() || _position.y() != _move_limit.y()) {
            switch(player_facing) {
            case LEFT:
                move(-4, 0);
                break;
            case RIGHT:
                move(4, 0);
                break;
            case UP:
                move(0, -4);
                break;
            case DOWN:
                move(0, 4);
                break;
            default:
                move(0, 0);
                break;
            }
        }
        else {
            BN_LOG("Player Position x: ", _position.x());
            BN_LOG("Player Position y: ", _position.y());
            isMoving = false;
//            _move_limit = bn::fixed_point(max_x, max_y);
        }
    }
}
}
