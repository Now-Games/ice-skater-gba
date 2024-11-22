#pragma once

#include "sprite_game_object.h"

namespace is
{
    class ShurikenGameObject : public SpriteGameObject
    {
        private:
            const int MOVE_SPEED = 2;
            const int ROTATE_SPEED = 10;
            Direction direction;
            bool triggered;
            bn::point nextPosition;

            bn::rect getColliderAhead();
            bool checkMoveAhead();
            void changeDirection();
            void move();

        public:
            ShurikenGameObject(GameScene& scene, bn::point pos, Direction dir);

            SceneUpdateResult update() override;
            void interact(Player& player) override;
    };
}