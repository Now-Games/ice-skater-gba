#pragma once

#include "bn_point.h"

namespace is
{
    struct SceneUpdateResult
    {
        int nextSceneIndex = -1;
        bn::point position;
        bool isScenePaused = false;

        SceneUpdateResult() = default;
        SceneUpdateResult(int nextScene) { nextSceneIndex = nextScene; }
        SceneUpdateResult(int nextScene, bn::point pos) 
        {
            nextSceneIndex = nextScene;
            position = pos;
        }
    };
}