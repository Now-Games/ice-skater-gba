#pragma once

#include "game_object.h"

namespace is
{
    class Player : public GameObject
    {
        private:
            const int8_t moveSpeed = 2;
            bool isMoving = false;

            void getInput();
            void move();

        public:
            Player(GameScene& gs);

            void update() override;
    };
}