#include "final_scene.h"

#include "direction.h"
#include "game_constants.h"

#include "bn_log.h"
#include "bn_colors.h"
#include "bn_keypad.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_items_player_sheet.h"
#include "bn_regular_bg_items_final_scene_bg.h"
#include "common_variable_8x16_sprite_font.h"

namespace is
{
    FinalScene::FinalScene() : Scene("B30"),
        background(bn::regular_bg_items::final_scene_bg.create_bg(0, 0)),
        player(bn::sprite_items::player_sheet.create_sprite(0, 0)),
        backgroundPalette(background.palette()),
        playerPalette(player.palette()),
        dialogTextGenerator(common::variable_8x16_sprite_font)
    {
        dialogTextGenerator.set_center_alignment();

        player.set_tiles(bn::sprite_items::player_sheet.tiles_item().create_tiles(Direction::Up));
        player.set_position(0, 96);

        currentState = CutsceneState::PlayerRunning;

        dialog.push_back("At last...");
        dialog.push_back("I found it...");
        dialog.push_back("With this... I can save her.");
        dialog.push_back("Thank you");

        runStopPosition = bn::point(0, 64);
        walkStopPosition = bn::point(0, 24);
    }

    SceneUpdateResult FinalScene::update()
    {
        switch (currentState)
        {
            case CutsceneState::PlayerRunning:
                //Move the player until it reaches the desired position
                player.set_position(
                    player.position().x(),
                    player.position().y() - PLAYER_RUN_SPEED);
                
                if (player.position() == runStopPosition)
                    currentState = CutsceneState::PlayerStopped;
                
                break;
            case CutsceneState::PlayerStopped:
                timer++;
                if (timer >= PLAYER_STOP_TIME)
                    currentState = CutsceneState::PlayerWalk;
                
                break;
            case CutsceneState::PlayerWalk:
                player.set_position(
                    player.position().x(),
                    player.position().y() - PLAYER_WALK_SPEED);
                
                if (player.position() == walkStopPosition) {
                    currentState = CutsceneState::LightFadeIn;
                    playerPalette.set_fade(bn::colors::white, 0);
                    backgroundPalette.set_fade(bn::colors::white, 0);
                }
                    
                break;
            case CutsceneState::LightFadeIn:
            {
                bn::fixed playerIntensity = playerPalette.fade_intensity();
                bn::fixed bgIntensity = backgroundPalette.fade_intensity();
                if (bgIntensity == 1 && playerIntensity == 1) {
                    currentState = CutsceneState::LightFadeOut;
                    playerPalette.set_fade(bn::colors::black, 0);
                    backgroundPalette.set_fade(bn::colors::black, 0);
                }

                playerPalette.set_fade_intensity(bn::min(playerIntensity + 0.01, bn::fixed(1)));
                backgroundPalette.set_fade_intensity(bn::min(bgIntensity + 0.01, bn::fixed(1)));
                break;
            }
            case CutsceneState::LightFadeOut:
            {
                bn::fixed playerIntensity = playerPalette.fade_intensity();
                bn::fixed bgIntensity = backgroundPalette.fade_intensity();
                if (bgIntensity == 1 && playerIntensity == 1) {
                    currentDialog = 0;
                    timer = 0;
                    currentState = CutsceneState::Dialog;
                }

                playerPalette.set_fade_intensity(bn::min(playerIntensity + 0.01, bn::fixed(1)));
                backgroundPalette.set_fade_intensity(bn::min(bgIntensity + 0.01, bn::fixed(1)));
                break;
            }
            case CutsceneState::Dialog:
            {
                if (!isDialogFinished) 
                {
                    if (timer < DIALOG_DELAY_BETWEEN_TEXT)
                        timer++;
                    else
                    {
                        textPosition++;
                        generateDialogText();
                        if (textPosition >= dialog[currentDialog].size()) {
                            BN_LOG("Dialog is finished loading: ", textPosition);
                            isDialogFinished = true;
                        }
                        timer = 0;
                    }
                }

                if (bn::keypad::any_pressed())
                {
                    if (textPosition < dialog[currentDialog].size()) 
                    {
                        textPosition = dialog[currentDialog].size();
                        generateDialogText();
                        isDialogFinished = true;
                    }
                    else 
                    {
                        timer = 0;
                        textPosition = 0;
                        currentDialog++;
                        if (currentDialog < dialog.size()) 
                        {
                            generateDialogText();
                            isDialogFinished = false;
                        }
                        else
                        {
                            return SceneUpdateResult(CREDITS_SCENE);
                        }
                    }
                }
                break;
            }
            default:
                break;
        }
        
        return SceneUpdateResult();
    }
    
    void FinalScene::generateDialogText()
    {
        dialogText.clear();

        bn::string<64> currentText = dialog[currentDialog].substr(0, bn::min(
            textPosition, dialog[currentDialog].size()
        ));
        dialogTextGenerator.generate(0, 0, currentText, dialogText);
    }
}