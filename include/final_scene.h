#pragma once

#include "scene.h"

#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_bg_palette_ptr.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_sprite_text_generator.h"

namespace is
{
    enum CutsceneState
    {
        PlayerRunning,
        PlayerStopped,
        PlayerWalk,
        LightFadeIn,
        LightFadeOut,
        Dialog
    };

    class FinalScene : public Scene
    {
        private:
            const int PLAYER_RUN_SPEED = 4;
            const int PLAYER_STOP_TIME = 80;
            const int PLAYER_WALK_SPEED = 1;
            const int DIALOG_DELAY_BETWEEN_TEXT = 10;
            CutsceneState currentState;
            bn::regular_bg_ptr background;
            bn::sprite_ptr player;
            bn::point runStopPosition;
            int timer = 0;
            int currentDialog = 0;
            int textPosition = 0;
            bool isDialogFinished = false;
            bn::point walkStopPosition;
            bn::bg_palette_ptr backgroundPalette;
            bn::sprite_palette_ptr playerPalette;
            bn::vector<bn::sprite_ptr, 32> dialogText;
            bn::sprite_text_generator dialogTextGenerator;
            bn::vector<bn::string<64>, 4> dialog;

            void generateDialogText();

        public:
            FinalScene();

            SceneUpdateResult update() override;
    };
}