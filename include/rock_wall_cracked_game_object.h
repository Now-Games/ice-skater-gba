#pragma once

#include "sprite_game_object.h"
#include "bn_sprite_animate_actions.h"

namespace is
{
    class RockWallCrackedGameObject : public SpriteGameObject
    {
        private:
            bn::sprite_animate_action<4> crumbleAnim;

        public:
            RockWallCrackedGameObject(GameScene& gs, bn::point pos, Direction dir);

            void interact(Player& player) override;
    };
}