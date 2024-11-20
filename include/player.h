#pragma once

#include "sprite_game_object.h"
#include "bn_sprite_animate_actions.h"

namespace is
{
    class Player : public SpriteGameObject
    {
        private:
            bool isMoving = false;
            Direction currentDirection;
            bn::sprite_animate_action<20> fallAnim;
            bn::point nextPosition;

            bn::rect getColliderAhead();
            void checkMoveAhead();
            void move();

        public:
            Player(GameScene& gs);

            Direction getDirection() { return currentDirection; }
            void setDirection(Direction dir);

            void fall();
            SceneUpdateResult update() override;
    };
}