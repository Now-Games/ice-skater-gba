#pragma once

#include "scene_manager.h"

namespace is
{
    class Game
    {
        private:
            SceneManager sm;

        public:
            Game();

            void update();
    };
}