#pragma once

#include "scene.h"
#include "player.h"
#include "game_scene_details.h"

#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"

namespace is
{
    class GameScene : public Scene
    {
        private:
            bn::vector<GameObject*, 30> obstacles;
            bn::optional<bn::regular_bg_ptr> background;
            Player player;

        public:
            GameScene(GameSceneDetails details);

            SceneUpdateResult update() override;
            GameObject *checkCollisions(bn::rect collider);
    };
}