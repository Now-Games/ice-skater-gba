#pragma once

#include "bn_point.h"

namespace is
{
    struct SceneUpdateResult
    {
        int nextSceneIndex = -1;
        bn::point position;

        SceneUpdateResult() = default;
        SceneUpdateResult(int nextScene) { nextSceneIndex = nextScene; }
        SceneUpdateResult(int nextScene, bn::point pos) 
        {
            nextSceneIndex = nextScene;
            position = pos;
        }
    };

    class Scene
    {
        public:
            Scene();
            virtual ~Scene() = default;

            virtual SceneUpdateResult update();
    };
}