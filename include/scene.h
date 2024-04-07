#pragma once

#include "gameObjects/game_object.h"
#include "bn_unique_ptr.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "scene_info.h"
#include "scene_update_result.h"

class ColliderComponent;
class Scene
{
    protected:
        bn::fixed_point startPosition;
        bn::optional<bn::regular_bg_ptr> background;
        bn::vector<bn::unique_ptr<GameObject>, 32> gameObjects;
        bn::fixed_point maxBounds;
        bn::fixed_point minBounds;
        int obstacleIndex = -1;
        
    public:
        explicit Scene(SceneInfo sceneInfo);
        virtual ~Scene() {};
        virtual SceneUpdateResult update();
        bn::fixed_point getMaxBounds();
        bn::fixed_point getMinBounds();
        void setMaxBounds(bn::fixed_point bounds);
        void setMinBounds(bn::fixed_point bounds);
        void setPlayerPosition(bn::point position);
        bn::point getPlayerPosition();
        bool isEmptySpace(ColliderComponent*, int, int);
        int getNextObstacle(bn::fixed_point position, Direction direction);
};
