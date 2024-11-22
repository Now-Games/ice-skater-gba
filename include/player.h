#pragma once

#include "sprite_game_object.h"
#include "bn_sprite_animate_actions.h"

namespace is
{
    class Player : public SpriteGameObject
    {
        private:
            const int INPUT_DELAY = 5;
            bool isMoving = false;
            Direction currentDirection;
            bn::sprite_animate_action<20> fallAnim;
            bn::sprite_animate_action<12> deathAnim;
            bn::point nextPosition;
            int inputTimer = 0;

            bn::rect getColliderAhead();
            void checkMoveAhead();
            void move();

        public:
            Player(GameScene& gs);

            Direction getDirection() { return currentDirection; }
            void setDirection(Direction dir);

            void fall();
            void dead();
            SceneUpdateResult update() override;
    };
}