#ifndef SCENE_H
#define SCENE_H

#include "bn_unique_ptr.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "player.h"
#include "scene_info.h"
#include "obstacle.h"
#include "scene_update_result.h"

class Scene
{
    protected:
        bn::fixed_point startPosition;
        bn::optional<bn::regular_bg_ptr> background;
        bn::vector<Obstacle, 32> obstacles;
        bn::fixed_point maxBounds;
        bn::fixed_point minBounds;
        bn::optional<Player> player;
        int obstacleIndex = -1;
        
    public:
        explicit Scene(SceneInfo sceneInfo);
        virtual ~Scene() {};
        virtual SceneUpdateResult update();
        bn::fixed_point getMaxBounds();
        bn::fixed_point getMinBounds();
        void setMaxBounds(bn::fixed_point bounds);
        void setMinBounds(bn::fixed_point bounds);
        void setPlayerPosition(bn::fixed_point rawPosition);
        bn::fixed_point getPlayerPosition();
        int getNextObstacle(Direction direction);
        void getInput();
};

#endif // SCENE_H
