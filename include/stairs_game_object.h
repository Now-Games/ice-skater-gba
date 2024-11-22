#pragma once

#include "sprite_game_object.h"

namespace is
{
    class StairsGameObject : public SpriteGameObject
    {
        private:
            Direction direction;
            bool eventTriggered = false;

        public:
            StairsGameObject(GameScene &gs, bn::point pos, Direction dir);

            SceneUpdateResult update() override;
            void interact(Player& player) override;
    };
}