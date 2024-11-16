#pragma once 

#include "bn_string.h"
#include "bn_vector.h"
#include "game_object_details.h"

namespace is
{
    enum SceneType
    {
        Normal,
        Tutorial,
        MultiLevel
    };
    
    struct GameSceneDetails
    {
        bn::string<3> levelName = "";
        SceneType sceneType = SceneType::Normal;
        bn::vector<GameObjectDetails, 30> gameObjectDetails;

        GameSceneDetails() = default;
        GameSceneDetails(bn::string<3> name) { levelName = name; }
        GameSceneDetails(bn::string<3> name, SceneType type)
        {
            levelName = name;
            sceneType = type;
        }
    };
}