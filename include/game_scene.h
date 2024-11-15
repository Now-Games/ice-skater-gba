#pragma once

#include "scene.h"
#include "player.h"

#include "bn_vector.h"

namespace is
{
    class GameScene : public Scene
    {
        private:
            bn::vector<GameObject*, 24> obstacles;
            Player player;

        public:
            GameScene();

            SceneUpdateResult update() override;
            GameObject *checkCollisions(bn::rect collider);
    };
}