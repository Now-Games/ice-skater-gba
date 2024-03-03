#ifndef PLAYER_H
#define PLAYER_H

#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "direction.h"

class Player
{
    private:
        int moveSpeed = 4;
        bool moving = false;
        bn::fixed_point position;
        bn::fixed_point moveLimit;
        bn::sprite_ptr sprite;
        Direction direction;
        bn::optional<bn::sprite_animate_action<20>> fallAnim;
         
        void move(Direction dir);
        
    public:
        Player(bn::fixed_point pos, Direction dir);
        ~Player() = default;
        bool isMoving();
        void setDirection(Direction dir);
        Direction getDirection();
        bn::fixed_point getPosition();
        void setPosition(bn::fixed_point position);
        void setMoveLimit(bn::fixed_point newPos);
        void update();
        void playFallingAnimation();
};

#endif // PLAYER_H
