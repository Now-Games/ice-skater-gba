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
        bn::point startPosition = bn::point(0, 0);
        bn::point exitPosition = bn::point(0, 0);
        int nextScene = 0;
        bn::vector<GameObjectDetails, 30> gameObjectDetails;

        GameSceneDetails() = default;
    };
}