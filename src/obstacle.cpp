#include "obstacle.h"
#include "game_constants.h"
#include "bn_core.h"
#include "bn_log.h"
#include "bn_sprite_items_stairs_sheet.h"

Obstacle::Obstacle(ObstacleInfo info)
{
    type = info.type;
    rawPosition = info.position * BLOCK_SIZE;
    direction = info.direction;
    
    loadSprite(info.type);
}

void Obstacle::loadSprite(ObstacleType type)
{
    switch(type)
    {
        case ObstacleType::IceRock:
            sprite = bn::sprite_items::ice_rock.create_sprite(rawPosition);
            destructible = false;
            sprite->set_tiles(bn::sprite_items::ice_rock.tiles_item().create_tiles(direction));
            break;
        case ObstacleType::RockWall:
            destructible = false;
            sprite = bn::sprite_items::rock_wall.create_sprite(rawPosition);
            sprite->set_tiles(bn::sprite_items::rock_wall.tiles_item().create_tiles(direction));
            break;
        case ObstacleType::SnowPatch:
            destructible = false;
            sprite = bn::sprite_items::snow_tile.create_sprite(rawPosition);
            sprite->set_tiles(bn::sprite_items::snow_tile.tiles_item().create_tiles(direction));
            break;
        case ObstacleType::Snowball:
            destructible = true;
            sprite = bn::sprite_items::snowball_sheet.create_sprite(rawPosition);
            sprite->set_tiles(bn::sprite_items::snowball_sheet.tiles_item().create_tiles(0));
            spritesheet = bn::create_sprite_animate_action_once(sprite.value(), 5, 
                                bn::sprite_items::snowball_sheet.tiles_item(), 1, 2, 3, 4, 5);
            break;
        case ObstacleType::RockHole:
            destructible = false;
            sprite = bn::sprite_items::rock_wall_hole.create_sprite(rawPosition);
            sprite->set_tiles(bn::sprite_items::rock_wall_hole.tiles_item().create_tiles(direction));
            break;
        case ObstacleType::CrackedWall:
        {
            destructible = true;
            sprite = bn::sprite_items::cracked_wall_sheet.create_sprite(rawPosition);
            int start = direction * 5;
            sprite->set_tiles(bn::sprite_items::cracked_wall_sheet.tiles_item().create_tiles(start));
            spritesheet = bn::create_sprite_animate_action_once(sprite.value(), 7, 
                                bn::sprite_items::cracked_wall_sheet.tiles_item(), 
                                start+1, start+2, start+3, start+4, start+4);
            break;
        }
        case ObstacleType::CrackedIce:
            destructible = true;
            sprite = bn::sprite_items::cracked_ice_sheet.create_sprite(rawPosition);
            sprite->set_tiles(bn::sprite_items::cracked_ice_sheet.tiles_item().create_tiles(0));
            spritesheet = bn::create_sprite_animate_action_once(sprite.value(), 5, 
                                bn::sprite_items::cracked_ice_sheet.tiles_item(), 1, 2, 3, 4, 4);
            break;
        case ObstacleType::StairsDown:
        case ObstacleType::StairsUp:
            destructible = false;
            sprite = bn::sprite_items::stairs_sheet.create_sprite(rawPosition);
            sprite->set_tiles(bn::sprite_items::stairs_sheet.tiles_item().create_tiles(direction));
            break;
        default:
            break;
    }
    
    sprite->set_z_order(7);
}

void Obstacle::setDestroy()
{
    transparent = true;
    destroyed = true;
    BN_LOG("Obstacle destroyed!");

    while(!spritesheet->done()) {
        spritesheet->update();
        bn::core::update();
    }
}

bn::fixed_point Obstacle::getPosition()
{
    return rawPosition;
}

ObstacleType Obstacle::getType()
{
    return type;
}

Direction Obstacle::getDirection()
{
    return direction;
}

bool Obstacle::isTransparent()
{
    return transparent;
}

bool Obstacle::isDestroyed()
{
    return destroyed;
}

bn::fixed_point Obstacle::getStopPosition(Direction dir)
{
    if (type == ObstacleType::RockHole || type == ObstacleType::SnowPatch || 
        type == ObstacleType::StairsDown ||
        type == ObstacleType::StairsUp || type == ObstacleType::CrackedIce)
    {
        return rawPosition;
    }
    else {    
        switch (dir) {
            case Direction::Up:
                return rawPosition + bn::fixed_point(0, -16);
            case Direction::Down:
                return rawPosition + bn::fixed_point(0, 16);
            case Direction::Left:
                return rawPosition + bn::fixed_point(-16, 0);
            case Direction::Right:
                return rawPosition + bn::fixed_point(16, 0);
            default:
                return rawPosition;
        }
    }
}