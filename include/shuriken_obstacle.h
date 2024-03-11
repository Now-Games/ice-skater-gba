#pragma once

#include "obstacle.h"
#include "scene.h"

class Shuriken : public Obstacle
{
    private:
        int moveSpeed = 2;
        bn::unique_ptr<Scene> currentScene;

    public:
        Shuriken(ObstacleInfo info, Scene *scene);
        ~Shuriken() = default;
        void update();
};