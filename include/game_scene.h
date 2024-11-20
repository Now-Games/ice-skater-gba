#pragma once

#include "scene.h"
#include "player.h"
#include "game_scene_details.h"
#include "rock_wall_hole_game_object.h"

#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"

namespace is
{
    class GameScene : public Scene
    {
        protected:
            bn::rect sceneBounds;
            bn::vector<GameObject *, 40> obstacles;
            bn::optional<bn::regular_bg_ptr> background;
            Player player;

        public:
            GameScene(GameSceneDetails* details);
            ~GameScene() override;

            bn::rect getSceneBounds();

            SceneUpdateResult update() override;
            virtual GameObject *checkCollisions(bn::rect collider);
    };
}