#pragma once 

#include "scene.h"

#include "bn_vector.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_ptr.h"

namespace is
{
    class StartMenuScene : public Scene
    {
        private:
            const int INPUT_DELAY = 10;
            const int SPACE_BETWEEN_OPTIONS = 24;
            bn::regular_bg_ptr background;
            bn::sprite_text_generator optionsTextGenerator;
            bn::sprite_text_generator versionTextGenerator;
            bn::vector<bn::sprite_ptr, 32> optionsSprites;
            bn::vector<bn::sprite_ptr, 6> versionSprites;
            int selectedOption = 0;
            bn::vector<bn::string<8>, 4> options;
            bn::sprite_ptr pointer;
            int timer = 0;

            void updatePointer();
            SceneUpdateResult getNextSceneDetails();

        public:
            StartMenuScene();

            SceneUpdateResult update() override;
    };
}