#include "is_obstacle.h"

namespace is
{

obstacle::obstacle(bn::fixed_point pos, obstacle_type type, bool destructible, direction _direction) :
    _position(pos)
{
    _type = type;
    _can_destroy = destructible;
    _sprite = helper::get_sprite_item(type).create_sprite(pos.x(), pos.y());

    switch(type) {
    case SNOWBALL:
    {
        _sprite->set_tiles(bn::sprite_items::snowball_sheet.tiles_item().create_tiles(0));
        _death_anim = bn::create_sprite_animate_action_once(_sprite.value(), 5,
                                bn::sprite_items::snowball_sheet.tiles_item(), 1, 2, 3, 4, 5);
        break;
    }
    case CRACKED_WALL:
    {
        int start = 0;
        switch (_direction) {
        case LEFT:
            start = 8;
            break;
        case RIGHT:
            start = 4;
            break;
        case UP:
            start = 12;
            break;
        default: break;
        }
        _sprite->set_tiles(bn::sprite_items::cracked_wall_sheet.tiles_item().create_tiles(start));
        _death_anim = bn::create_sprite_animate_action_once(_sprite.value(), 5,
                                bn::sprite_items::cracked_wall_sheet.tiles_item(),
                                start+1, start+2, start+3, start+4, start+4);
        break;
    }
    default:
    {
        switch(_direction) {
        case LEFT:
            _sprite->set_tiles(helper::get_sprite_item(_type).tiles_item().create_tiles((2)));
            break;
        case RIGHT:
            _sprite->set_tiles(helper::get_sprite_item(_type).tiles_item().create_tiles((1)));
            break;
        case UP:
            _sprite->set_tiles(helper::get_sprite_item(_type).tiles_item().create_tiles((3)));
            break;
        }

        break;
    }
    }

    _sprite->set_z_order(1);
}

obstacle::~obstacle()
{

}

bn::fixed obstacle::get_collision_edge(direction _direction)
{
    if (!is_destroyed) {
        switch(_direction) {
        case LEFT:
            if (_type == ROCK_WALL_HOLE || _type == SNOW)
                return _position.x();
            else
                return _position.x() + 16;
        case RIGHT:
            if (_type == ROCK_WALL_HOLE || _type == SNOW)
                return _position.x();
            else
                return _position.x() - 16;
        case UP:
            if (_type == ROCK_WALL_HOLE || _type == SNOW)
                return _position.y();
            else
                return _position.y() + 16;
        case DOWN:
            if (_type == ROCK_WALL_HOLE || _type == SNOW)
                return _position.y();
            else
                return _position.y() - 16;
        default:
            return 0;
        }
    }
    else {
        if (_direction == LEFT) return min_x;
        else if (_direction == RIGHT) return max_x;
        else if (_direction == UP) return min_y;
        else if (_direction == DOWN) return max_y;
        else return 0;
    }
}

bool obstacle::can_destroy()
{
    return _can_destroy;
}

bn::fixed_point obstacle::get_position()
{
    return _position;
}

bool obstacle::get_destroyed()
{
    return is_destroyed;
}

void obstacle::set_destroy()
{
    is_destroyed = true;
    BN_LOG("Obstacle destroyed!");

    while(!_death_anim->done()) {
        _death_anim->update();
        bn::core::update();
    }
}

void obstacle::update()
{

}

}
