#pragma once

#include "bn_regular_bg_ptr.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"
#include "bn_string_view.h"
#include "bn_sprite_text_generator.h"

enum PauseResult
{
    P_None,
    P_Continue,
    P_Restart,
    P_LevelSelect,
    P_Title
};

class PauseWindow
{
    private:
        bn::optional<bn::regular_bg_ptr> background;
        int currentOption = 0;
        bn::vector<bn::sprite_ptr, 4> optionSprites;
        bn::sprite_ptr pointerSprite;
        void updatePointerPosition();

    public:
        PauseWindow();
        ~PauseWindow() = default;
        PauseResult update();
};