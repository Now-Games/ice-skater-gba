#pragma once

#include "sprite_game_object.h"

namespace is
{
    class RockWallGameObject : public SpriteGameObject
    {
        public:
            RockWallGameObject(GameScene& gs, bn::point pos, Direction dir);

    };
}