#pragma once

#include "sprite_game_object.h"
#include "bn_sprite_animate_actions.h"

namespace is
{
    class CrackedIceGameObject : public SpriteGameObject
    {
        private:
            bn::sprite_animate_action<4> breakAnim;
            bool triggered = false;

        public:
            CrackedIceGameObject(GameScene &gs, bn::point pos);

            SceneUpdateResult update() override;
            void interact(Player &player) override;
    };
}