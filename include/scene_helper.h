#pragma once

#include "game_object_details.h"
#include "game_scene_details.h"
#include "sprite_game_object.h"
#include "snowball_game_object.h"
#include "rock_wall_hole_game_object.h"
#include "rock_wall_game_object.h"
#include "rock_wall_cracked_game_object.h"
#include "cracked_ice_game_object.h"
#include "stairs_game_object.h"
#include "shuriken_game_object.h"
#include "game_constants.h"

#include "bn_array.h"
#include "bn_sprite_items_rock_wall.h"
#include "bn_sprite_items_rock_wall_hole.h"
#include "bn_sprite_items_ice_rock.h"
#include "bn_sprite_items_snow_tile.h"
#include "bn_sprite_items_snowball_sheet.h"

namespace is
{
    static GameObject* getGameObject(GameScene& gs, GameObjectDetails details)
    {
        switch (details.objectType)
        {
            case RockWall:
            {
                RockWallGameObject* sgo = new RockWallGameObject(gs, details.position, details.direction);
                sgo->setTransparency(Transparency::Opaque);
                return sgo;
            }
            case IceRock:
            {
                SpriteGameObject* sgo = new SpriteGameObject(gs, bn::sprite_items::ice_rock, details.position);
                sgo->setTransparency(Transparency::Opaque);
                return sgo;
            }
            case Snow:
            {
                SpriteGameObject* sgo = new SpriteGameObject(gs,
                        bn::sprite_items::snow_tile, details.position);
                sgo->setTransparency(Transparency::Translucent);
                return sgo;
            }
            case Snowball:
            {
                SnowballGameObject *sgo = new SnowballGameObject(gs, details.position);
                sgo->setTransparency(Transparency::Opaque);
                return sgo;
            }
            case RockWallHole:
            {
                RockWallHoleGameObject *sgo = new RockWallHoleGameObject(gs, details.position, details.direction, -1);
                sgo->setTransparency(Transparency::Translucent);
                return sgo;
            }
            case RockWallCracked:
            {
                RockWallCrackedGameObject *sgo = new RockWallCrackedGameObject(gs, details.position, details.direction);
                sgo->setTransparency(Transparency::Opaque);
                return sgo;
            }
            case CrackedIce:
            {
                CrackedIceGameObject *sgo = new CrackedIceGameObject(gs, details.position);
                sgo->setTransparency(Transparency::Translucent);
                return sgo;
            }
            case Stairs:
            {
                StairsGameObject *sgo = new StairsGameObject(gs, details.position, details.direction);
                sgo->setTransparency(Transparency::Translucent);
                return sgo;
            }
            case Shuriken:
            {
                ShurikenGameObject *sgo = new ShurikenGameObject(gs, details.position, details.direction);
                sgo->setTransparency(Transparency::Translucent);
                return sgo;
            }
            default:
                return new GameObject(gs, details.position);
            }
    }
    
    static GameSceneDetails* getSceneDetails(int sceneIndex)
    {
        GameSceneDetails* details = nullptr;
        switch (sceneIndex)
        {
            case B1_SCENE:
                details = new EventSceneDetails(B1_SCENE, "Use the D-Pad to move");
                details->levelName = "B1";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(0, -72);
                details->nextScene = B2_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B2_SCENE:
                details = new EventSceneDetails(B2_SCENE, "Press A to interact with objects");
                details->levelName = "B2";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(0, -72);
                details->nextScene = B3_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(0, 8), Direction::Down});
                break;
            case B3_SCENE:
                details = new GameSceneDetails(B3_SCENE);
                details->levelName = "B3";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(0, -72);
                details->nextScene = B4_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -56), Direction::Down});
                break;
            case B4_SCENE:
                details = new GameSceneDetails(B4_SCENE);
                details->levelName = "B4";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(-64, -72);
                details->nextScene = B5_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-64, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                break;
            case B5_SCENE:
                details = new GameSceneDetails(B5_SCENE);
                details->levelName = "B5";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(112, 40);
                details->exitPosition = bn::point(-112, -24);
                details->exitDirection = Direction::Right;
                details->nextScene = B6_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -56), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -40), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 24), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 40), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 56), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 72), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-80, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-96, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(112, 40), Direction::Down});
                break;
            case B6_SCENE:
                details = new GameSceneDetails(B6_SCENE);
                details->levelName = "B6";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(-64, 72);
                details->exitPosition = bn::point(-32, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B7_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(112, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(-64, 72), Direction::Down});
                break;
            case B7_SCENE:
                details = new EventSceneDetails(B7_SCENE, "I wonder how deep this cave goes...");
                details->levelName = "B7";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B8_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B8_SCENE:
                details = new GameSceneDetails(B8_SCENE);
                details->levelName = "B8";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(112, 24);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B9_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(0, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(32, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-32, 72), Direction::Down});  
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(112, 24), Direction::Down});
                break;
            case B9_SCENE:
                details = new EventSceneDetails(B9_SCENE, "Some walls can be broken through with a bit of force");
                details->levelName = "B9";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(-64, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B10_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallHole, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B10_SCENE:
                details = new GameSceneDetails(B10_SCENE);
                details->levelName = "B10";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(-16, 72);
                details->exitPosition = bn::point(-32, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B11_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallHole, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(64, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-16, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(-16, 72), Direction::Down});
                break;
            case B11_SCENE:
                details = new EventSceneDetails(B11_SCENE, "I have to hurry...");
                details->levelName = "B11";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B12_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B12_SCENE:
                details = new GameSceneDetails(B12_SCENE);
                details->levelName = "B12";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(16, 72);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B13_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-32, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(0, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-64, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-16, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(32, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-16, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-80, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-16, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-32, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(80, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-80, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(-32, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(112, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(16, 72), Direction::Down});
                break;
            case B13_SCENE:
                details = new EventSceneDetails(B13_SCENE, "That ice looks quite fragile...");
                details->levelName = "B13";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(112, -8);
                details->exitPosition = bn::point(-112, 40);
                details->exitDirection = Direction::Right;
                details->nextScene = B14_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -56), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -40), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -24), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 24), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::CrackedIce, bn::point(-96, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(112, -8), Direction::Down});
                break;
            case B14_SCENE:
                details = new GameSceneDetails(B14_SCENE);
                details->levelName = "B14";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(112, 72);
                details->exitPosition = bn::point(-112, -8);
                details->exitDirection = Direction::Right;
                details->nextScene = B15_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -56), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -40), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -24), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 24), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 40), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 56), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, 72), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(-112, -8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(-112, 8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::CrackedIce, bn::point(-96, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(112, 72), Direction::Down});
                break;
            case B15_SCENE:
                details = new GameSceneDetails(B15_SCENE);
                details->levelName = "B15";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(-32, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B16_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::CrackedIce, bn::point(-32, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                break;
            case B16_SCENE:
                details = new GameSceneDetails(B16_SCENE);
                details->levelName = "B16";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(-64, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B17_SCENE_1;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(112, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::CrackedIce, bn::point(-64, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::CrackedIce, bn::point(64, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                break;
            case B17_SCENE_1:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B17_SCENE_1);
                floors.push_back(B17_SCENE_2);
                details = new MultiSceneDetails(B17_SCENE_1, floors);
                details->levelName = "B17";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(-64, 72);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B18_SCENE_2;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(112, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(0, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(96, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(-64, 72), Direction::Down});
                break;
            }
            case B17_SCENE_2:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B17_SCENE_1);
                floors.push_back(B17_SCENE_2);
                details = new MultiSceneDetails(B17_SCENE_2, floors);
                details->levelName = "B17";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(164, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B18_SCENE_2;
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(0, 8), Direction::Up});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(96, -40), Direction::Up});
                break;
            }
            case B18_SCENE_1:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B18_SCENE_1);
                floors.push_back(B18_SCENE_2);
                details = new MultiSceneDetails(B18_SCENE_1, floors);
                details->levelName = "B18";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B19_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWallCracked, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(-80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(80, -40), Direction::Down});
                break;
            }
            case B18_SCENE_2:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B18_SCENE_1);
                floors.push_back(B18_SCENE_2);
                details = new MultiSceneDetails(B18_SCENE_2, floors);
                details->levelName = "B18";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(164, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B19_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(112, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(-80, -40), Direction::Up});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(80, -40), Direction::Up});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                break;
            }
            case B19_SCENE:
                details = new EventSceneDetails(B19_SCENE, "I hope I can find it in time...");
                details->levelName = "B19";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B20_SCENE_2;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B20_SCENE_1:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B20_SCENE_1);
                floors.push_back(B20_SCENE_2);
                floors.push_back(B20_SCENE_3);
                details = new MultiSceneDetails(B20_SCENE_1, floors);
                details->levelName = "B20";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(164, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B21_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(112, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(0, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(-80, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(0, -24), Direction::Down});
                break;
            }
            case B20_SCENE_2:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B20_SCENE_1);
                floors.push_back(B20_SCENE_2);
                floors.push_back(B20_SCENE_3);
                details = new MultiSceneDetails(B20_SCENE_2, floors);
                details->levelName = "B20";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B21_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-96, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(64, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(-80, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(80, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(0, -24), Direction::Up});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(-80, -8), Direction::Up});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                break;
            }
            case B20_SCENE_3:
            {
                bn::vector<int, 5> floors;
                floors.push_back(B20_SCENE_1);
                floors.push_back(B20_SCENE_2);
                floors.push_back(B20_SCENE_3);
                details = new MultiSceneDetails(B20_SCENE_3, floors);
                details->levelName = "B20";
                details->sceneType = SceneType::MultiLevel;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(164, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B21_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-64, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(-80, -40), Direction::Up});
                details->gameObjectDetails.push_back({GameObjectType::Stairs, bn::point(80, -8), Direction::Up});
                break;
            }
            case B21_SCENE:
                details = new EventSceneDetails(B21_SCENE, "I dont know what that is, but I better avoid it...");
                details->levelName = "B21";
                details->sceneType = SceneType::Tutorial;
                details->startPosition = bn::point(0, 40);
                details->exitPosition = bn::point(80, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = B22_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(0, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Shuriken, bn::point(-112, -56), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B22_SCENE:
                details = new GameSceneDetails(B22_SCENE);
                details->levelName = "B22";
                details->sceneType = SceneType::Normal;
                details->startPosition = bn::point(0, 72);
                details->exitPosition = bn::point(0, -72);
                details->exitDirection = Direction::Down;
                details->nextScene = CREDITS_SCENE;
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -56), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(48, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, -24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-16, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-32, -8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(96, 8), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(32, 24), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-112, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-48, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, 40), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(80, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(-80, 72), Direction::Down});
                details->gameObjectDetails.push_back({GameObjectType::Shuriken, bn::point(48, -56), Direction::Left});
                details->gameObjectDetails.push_back({GameObjectType::Shuriken, bn::point(-80, 8), Direction::Right});
                details->gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                break;
            default:
                break;
        }

        return details;
    }
}