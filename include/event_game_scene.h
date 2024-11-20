#pragma once

#include "game_scene.h"
#include "bn_sprite_text_generator.h"

namespace is
{
    class EventGameScene : public GameScene
    {
        private:
            bn::sprite_text_generator eventTextGenerator;
            bn::vector<bn::sprite_ptr, 64> eventTextSprites;

        public:
            EventGameScene(EventSceneDetails* details);
    };
}