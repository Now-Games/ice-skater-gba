#pragma once

#include "sprite_game_object.h"
#include "bn_sprite_animate_actions.h"

namespace is
{
    class Player : public SpriteGameObject
    {
        private:
            const int8_t moveSpeed = 2;
            bool isMoving = false;
            Direction currentDirection;
            bn::sprite_animate_action<20> fallAnim;

            void getInput();
            void move();

        public:
            Player(GameScene& gs);

            Direction getDirection() { return currentDirection; }
            virtual void setDirection(Direction dir) { currentDirection = dir; }
            
            void update() override;
    };
}