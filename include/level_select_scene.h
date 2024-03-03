#pragma once

#include "save_data.h"
#include "bn_vector.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_menu_pointer.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"

struct LevelButton
{
    bn::sprite_ptr sprite;
    int sceneIndex = 0;
};

class LevelSelectScene
{
    private:
        const int maxRows = 4;
        const int maxCols = 7;
        bn::regular_bg_ptr background;
        bn::sprite_text_generator titleGenerator;
        // bn::sprite_text_generator floorNameGenerator;
        bn::vector<bn::sprite_ptr, 30> titleSprites;
        bn::vector<bn::sprite_ptr, 30> floorNameSprites;
        bn::vector<LevelButton, 64> scenes;
        bn::sprite_ptr pointer;
        int furthestUnlockedScene = 0;
        int currentScene = 0;
        void updatePointerPosition();
        void updateFloorName();

    public:
        LevelSelectScene(SaveData data);
        ~LevelSelectScene() = default;
        int update();
};