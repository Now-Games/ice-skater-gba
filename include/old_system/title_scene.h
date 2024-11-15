#pragma once

#include "bn_vector.h"
#include "bn_unique_ptr.h"
#include "bn_string_view.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_ptr.h"
#include "save_data.h"

class TitleScene
{
    private:
        const int MENU_START_Y = 8;
        bn::sprite_text_generator menuGenerator;
        bn::sprite_text_generator versionGenerator;
        bn::vector<bn::sprite_ptr, 64> menuSprites;
        bn::vector<bn::sprite_ptr, 64> versionSprites;
        bn::vector<bn::string_view, 4> menuOptions;
        bn::sprite_ptr menuPointer;
        bn::regular_bg_ptr background;
        int currentSelection = 0;
        int lastPlayedScene = 0;
        void updatePointerPosition();

    public:
        TitleScene(SaveData saveData);
        ~TitleScene() = default;
        int update();
};