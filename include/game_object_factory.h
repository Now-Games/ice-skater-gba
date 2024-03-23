#pragma once

#include "game_object.h"
#include "scene_info.h"
#include "collider_component.h"
#include "destructible_component.h"
#include "move_component.h"

#include "bn_sprite_items_rock_wall.h"
#include "bn_sprite_items_ice_rock.h"
#include "bn_sprite_items_cracked_ice_sheet.h"
#include "bn_sprite_items_cracked_wall_sheet.h"

static GameObject createGameObject(ObstacleInfo info)
{
    switch (info.type)
    {
        case GameObjectType::GOT_IceRock:
        {
            GameObject newObject = GameObject(info.position, bn::sprite_items::ice_rock);
            newObject.addComponent(new ColliderComponent(&newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_RockWall:
        {
            GameObject newObject = GameObject(info.position, bn::sprite_items::rock_wall);
            newObject.addComponent(new ColliderComponent(&newObject, 16, 16));
            return newObject;
        }
        default:
            return;
    }
}