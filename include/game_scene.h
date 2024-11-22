#pragma once

#include "scene.h"
#include "player.h"
#include "game_scene_details.h"
#include "rock_wall_hole_game_object.h"

#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"

namespace is
{
    class GameScene : public Scene
    {
        protected:
            int currentSceneIndex = 0;
            SceneType sceneType;
            bn::rect sceneBounds;
            bn::vector<GameObject *, 40> gameObjects;
            bn::optional<bn::regular_bg_ptr> background;
            bn::vector<bn::sprite_ptr, 3> titleSprites;
            bn::vector<bn::sprite_ptr, 19> textSprites;
            bn::sprite_text_generator titleTextGenerator;
            bn::sprite_text_generator textGenerator;
            Player player;

            void initializeGameObjects(bn::vector<GameObjectDetails, 40> objectDetails);
            void loadBackground();

        public:
            GameScene(GameSceneDetails* details);
            ~GameScene() override;

            bn::rect getSceneBounds();
            int getCurrentSceneIndex();

            SceneUpdateResult update() override;
            virtual GameObject *checkCollisions(bn::rect collider);
            Player* checkPlayerCollision(bn::rect collider);
    };
}