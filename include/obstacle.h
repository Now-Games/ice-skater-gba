#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_affine_mat_ptr.h"
#include "scene_info.h"

class Obstacle
{
    private:
        ObstacleType type;
        bool transparent = false; //determines if the player can pass through it
        bool destructible = false;
        bool destroyed = false;
        Direction direction = Direction::Down;
        bn::fixed_point rawPosition;
        bn::optional<bn::sprite_affine_mat_ptr> affineMaterial;
        bn::optional<bn::sprite_ptr> sprite;
        bn::optional<bn::sprite_animate_action<5>> spritesheet;
        
        void loadSprite(ObstacleType type);
        
    public:
        Obstacle(ObstacleInfo info);
        virtual ~Obstacle() = default;
        void setDestroy();
        bn::fixed_point getPosition();
        ObstacleType getType();
        Direction getDirection();
        bool isTransparent();
        bool isDestroyed();
        bn::fixed_point getStopPosition(Direction dir);
};

#endif // OBSTACLE_H
