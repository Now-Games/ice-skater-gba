#pragma once

#include "sprite_game_object.h"

namespace is
{
    class RockWallHoleGameObject : public SpriteGameObject
    {
        private:
            int nextSceneIndex = -1;
            bool eventTriggered;

        public:
            RockWallHoleGameObject(GameScene& gs, bn::point pos, Direction dir, int nextScene);

            SceneUpdateResult update() override;
            void interact(Player& player) override;
    };
}