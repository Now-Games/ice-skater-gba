#pragma once

#include "bn_regular_bg_ptr.h"

class CreditsScene
{
    private:
        bn::regular_bg_ptr background;

    public:
        CreditsScene();
        ~CreditsScene() = default;
        int update();
};