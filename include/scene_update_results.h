#pragma once

#include "bn_point.h"

namespace is
{
    struct SceneUpdateResult
    {
        int nextSceneIndex = -1;
        bn::point position;
        bool died = false;

        SceneUpdateResult() = default;
        SceneUpdateResult(bool dead) { died = dead; }
        SceneUpdateResult(int nextScene) { nextSceneIndex = nextScene; }
        SceneUpdateResult(int nextScene, bn::point pos) 
        {
            nextSceneIndex = nextScene;
            position = pos;
        }
    };
}