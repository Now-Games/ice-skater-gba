#pragma once

#include "scene.h"
#include "bn_point.h"

namespace is
{
    class SceneManager
    {
        private:
            Scene *currentScene;

            Scene *getScene(int index, bn::point pos);

        public:
            SceneManager();

            void initialize();
            void update();
    };
}