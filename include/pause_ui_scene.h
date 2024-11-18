#pragma once

#include "ui_scene.h"

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"

namespace is
{
    class PauseUIScene : public UIScene
    {
        private:
            const int INPUT_DELAY = 10;
            bn::regular_bg_ptr background;
            bn::sprite_text_generator textGenerator;
            bn::sprite_ptr pointer;
            bn::vector<bn::sprite_ptr, 4> options;
            bn::vector<bn::sprite_ptr, 30> optionTextSprites;
            int selectedOption = 0;
            int timer = 0;

            void updatePointer();
            void updateText();

        public:
            PauseUIScene();

            UIUpdateResults update() override;
    };
}