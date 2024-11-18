#pragma once

#include "sprite_game_object.h"
#include "bn_sprite_animate_actions.h"

namespace is
{
    class SnowballGameObject : public SpriteGameObject
    {
        private:
            bn::sprite_animate_action<20> breakAnim;

        public:
            SnowballGameObject(GameScene& gs, bn::point pos);

            void interact() override;
    };
}