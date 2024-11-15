#pragma once

#include "scene.h"

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

namespace is
{
    class LevelSelectScene : public Scene
    {
        private:
            bn::regular_bg_ptr background;
            bn::sprite_ptr pointer;
            bn::vector<bn::sprite_ptr, 20> levelButtons;
            int levelIndexes[5];
            int selectedLevel = 0;

        public:
            LevelSelectScene();

            SceneUpdateResult update() override;
    };
}