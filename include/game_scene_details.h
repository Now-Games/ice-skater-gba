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
        Direction exitDirection = Direction::Down;
        int nextScene = 0;
        bn::vector<GameObjectDetails, 40> gameObjectDetails;

        GameSceneDetails() = default;
    };
    
    struct EventSceneDetails : public GameSceneDetails
    {
        bn::string<64> eventText;
        
        EventSceneDetails(bn::string<64> text) : GameSceneDetails()
        {
            eventText = text;
        }
    };
    
    struct MultiSceneDetails : public GameSceneDetails
    {
        bn::vector<int, 5> sceneFloors;
        
        MultiSceneDetails(bn::vector<int, 5> floors) : GameSceneDetails()
        {
            sceneFloors = floors;
        }
    };
}