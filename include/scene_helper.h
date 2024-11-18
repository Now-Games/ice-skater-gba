#pragma once

#include "game_object_details.h"
#include "game_scene_details.h"
#include "sprite_game_object.h"
#include "snowball_game_object.h"
#include "rock_wall_hole_game_object.h"
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
                SpriteGameObject* sgo = new SpriteGameObject(gs, bn::sprite_items::rock_wall, details.position);
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
            default:
                return new GameObject(gs, details.position);
            }
    }
    
    static GameSceneDetails getSceneDetails(int sceneIndex)
    {
        GameSceneDetails details = GameSceneDetails();
        switch (sceneIndex)
        {
            case B1_SCENE:
                details.levelName = "B1";
                details.sceneType = SceneType::Tutorial;
                details.startPosition = bn::point(0, 40);
                details.exitPosition = bn::point(0, -72);
                details.nextScene = B2_SCENE;
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                break;
            case B2_SCENE:
                details.levelName = "B2";
                details.sceneType = SceneType::Tutorial;
                details.startPosition = bn::point(0, 40);
                details.exitPosition = bn::point(0, -72);
                details.nextScene = B3_SCENE;
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 40), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::Snowball, bn::point(0, 8), Direction::Down});
                break;
            case B3_SCENE:
                details.levelName = "B3";
                details.sceneType = SceneType::Normal;
                details.startPosition = bn::point(0, 40);
                details.exitPosition = bn::point(0, -72);
                details.nextScene = B4_SCENE;
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-112, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-96, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-80, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-64, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-48, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-32, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(-16, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(16, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(32, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(48, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(64, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(80, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(96, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::RockWall, bn::point(112, -72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::Snow, bn::point(0, 72), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(0, -8), Direction::Down});
                details.gameObjectDetails.push_back({GameObjectType::IceRock, bn::point(16, -56), Direction::Down});
            default:
                break;
        }

        return details;
    }
}