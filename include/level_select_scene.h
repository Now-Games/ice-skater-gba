#pragma once

#include "scene.h"

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"

namespace is
{
    class LevelSelectScene : public Scene
    {
        private:
            const int INPUT_DELAY = 10;
            const int columns = 8;
            const int rows = 4;
            bn::regular_bg_ptr background;
            bn::sprite_ptr pointer;
            bn::vector<bn::sprite_ptr, 20> levelButtons;
            bn::sprite_text_generator titleTextGenerator;
            bn::sprite_text_generator levelTextGenerator;
            bn::vector<bn::sprite_ptr, 12> titleTextSprites;
            bn::vector<bn::sprite_ptr, 3> levelTextSprites;
            bn::vector<int, 30> levelIndexes;
            int selectedLevel;
            int timer = 0;

            void initializeSceneList();
            void updatePointer();
            void updateLevelText();

        public:
            LevelSelectScene();

            SceneUpdateResult update() override;
    };
}