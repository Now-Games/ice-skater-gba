#pragma once

#include "game_object.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"

namespace is
{
    class SpriteGameObject : public GameObject
    {
        protected:
            bn::sprite_ptr sprite;

        public:
            SpriteGameObject(GameScene& gs, bn::sprite_item si, bn::point pos);

            void setPosition(bn::point pos) override;
            SceneUpdateResult update() override;
    };
}