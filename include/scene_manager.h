#pragma once

#include "scene.h"

namespace is
{
    class SceneManager
    {
        private:
            Scene *currentScene;

        public:
            SceneManager();

            void initialize();
            void update();
    };
}