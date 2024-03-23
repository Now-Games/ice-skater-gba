#pragma once

#include "game_object.h"
#include "scene_info.h"
#include "components/collider_component.h"
#include "components/destructible_component.h"
#include "components/move_component.h"
#include "shuriken.h"

#include "bn_sprite_items_rock_wall.h"
#include "bn_sprite_items_ice_rock.h"
#include "bn_sprite_items_cracked_ice_sheet.h"
#include "bn_sprite_items_cracked_wall_sheet.h"
#include "bn_sprite_items_stairs_up.h"
#include "bn_sprite_items_stairs_down.h"
#include "bn_sprite_items_shuriken.h"

static GameObject* createGameObject(Scene* currentScene, ObstacleInfo info)
{
    switch (info.type)
    {
        case GameObjectType::GOT_IceRock:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::ice_rock);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_RockWall:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::rock_wall);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_RockHole:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::rock_wall_hole);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_SnowPatch:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::snow_tile);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_StairsUp:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::stairs_up);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_StairsDown:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::stairs_down);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            return newObject;
        }
        case GameObjectType::GOT_Snowball:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::snowball_sheet);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            newObject->addComponent(new DestructibleComponent(newObject, bn::sprite_items::snowball_sheet));
            return newObject;
        }
        case GameObjectType::GOT_CrackedWall:
        {
            GameObject* newObject = new GameObject(currentScene, info.position, info.type, bn::sprite_items::cracked_wall_sheet);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            newObject->addComponent(new DestructibleComponent(newObject, bn::sprite_items::cracked_wall_sheet));
            return newObject;
        }
        case GameObjectType::GOT_Shuriken:
        {
            Shuriken *newObject = new Shuriken(currentScene, info.position, bn::sprite_items::shuriken);
            newObject->addComponent(new ColliderComponent(newObject, 16, 16));
            newObject->addComponent(new MoveComponent(newObject, 2));
            return newObject;
        }
        default:
            return nullptr;
    }
}