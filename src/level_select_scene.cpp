#include "level_select_scene.h"

#include "save_data.h"
#include "game_constants.h"
#include "scene_helper.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_regular_bg_items_level_select_bg.h"
#include "bn_sprite_items_menu_pointer.h"
#include "common_variable_16x16_sprite_font.h"
#include "common_fixed_8x8_sprite_font.h"
#include "bn_sprite_items_level_button.h"

namespace is
{
    LevelSelectScene::LevelSelectScene() : Scene("LevelSelect"),
        background(bn::regular_bg_items::level_select_bg.create_bg(0, 0)),
        pointer(bn::sprite_items::menu_pointer.create_sprite(0, 0)),
        titleTextGenerator(bn::sprite_text_generator(common::variable_16x16_sprite_font)),
        levelTextGenerator(bn::sprite_text_generator(common::fixed_8x8_sprite_font))
    {
        titleTextGenerator.set_center_alignment();
        levelTextGenerator.set_center_alignment();

        titleTextGenerator.generate(0, -(bn::display::height() / 2) + 12,
                                    "Level Select", titleTextSprites);

        initializeSceneList();
        for (int i = 0; i < levelIndexes.size(); i++)
        {
            if (levelIndexes[i] > saveData.furthestScene)
                break;

            bn::sprite_ptr button = bn::sprite_items::level_button.create_sprite(0, 0);
            button.set_position(
                -(bn::display::width() / 2) + 20 + ((i % columns) * 40),
                -36 + ((i / columns) * 24)
            );

            levelButtons.push_back(button);
        }

        selectedLevel = 0;
        for (int i = 0; i < levelIndexes.size(); i++)
        {
            if (levelIndexes[i] == saveData.currentScene) 
            {
                selectedLevel = i;
                break;
            }
        }

        updatePointer();
        updateLevelText();
    }

    SceneUpdateResult LevelSelectScene::update()
    {
        if (bn::keypad::a_pressed())
        {
            //The level has been selected
            SceneUpdateResult result = SceneUpdateResult(levelIndexes[selectedLevel]);
            return result;
        }
        
        if (timer < INPUT_DELAY) 
        {
            timer++;
            return SceneUpdateResult();
        }

        bool pointerUpdated = false;
        if (bn::keypad::up_held())
        {
            pointerUpdated = true;
            selectedLevel -= columns;
            if (selectedLevel < 0)
                selectedLevel = 0;
        }
        else if (bn::keypad::down_held())
        {
            pointerUpdated = true;
            selectedLevel += columns;
            if (selectedLevel >= levelButtons.size())
                selectedLevel = levelButtons.size() - 1;
        }
        else if (bn::keypad::left_held())
        {
            pointerUpdated = true;
            selectedLevel --;
            if (selectedLevel < 0)
                selectedLevel = 0;
        }
        else if (bn::keypad::right_held())
        {
            pointerUpdated = true;
            selectedLevel ++;
            if (selectedLevel >= levelButtons.size())
                selectedLevel = levelButtons.size() - 1;
        }
        
        if (pointerUpdated) 
        {
            timer = 0;
            updatePointer();
            updateLevelText();
        }

        return SceneUpdateResult();
    }
    
    void LevelSelectScene::updatePointer()
    {
        pointer.set_position(bn::point(
            -(bn::display::width() / 2) + 8 + ((selectedLevel % columns) * 40),
            -36 + ((selectedLevel / columns) * 24)));
    }
    
    void LevelSelectScene::updateLevelText()
    {
        levelTextSprites.clear();
        GameSceneDetails* sceneDetails = getSceneDetails(levelIndexes[selectedLevel]);
        levelTextGenerator.generate(0, -(bn::display::height() / 2) + 24,
                                    sceneDetails->levelName, levelTextSprites);
    }
    
    void LevelSelectScene::initializeSceneList()
    {
        levelIndexes.push_back(B1_SCENE);
        levelIndexes.push_back(B2_SCENE);
        levelIndexes.push_back(B3_SCENE);
        levelIndexes.push_back(B4_SCENE);
        levelIndexes.push_back(B5_SCENE);
        levelIndexes.push_back(B6_SCENE);
        levelIndexes.push_back(B7_SCENE);
        levelIndexes.push_back(B8_SCENE);
        levelIndexes.push_back(B9_SCENE);
        levelIndexes.push_back(B10_SCENE);
        levelIndexes.push_back(B11_SCENE);
        levelIndexes.push_back(B12_SCENE);
        levelIndexes.push_back(B13_SCENE);
        levelIndexes.push_back(B14_SCENE);
        levelIndexes.push_back(B15_SCENE);
        levelIndexes.push_back(B16_SCENE);
        levelIndexes.push_back(B17_SCENE_1);
        levelIndexes.push_back(B18_SCENE_2);
        levelIndexes.push_back(B19_SCENE);
        levelIndexes.push_back(B20_SCENE_2);
        levelIndexes.push_back(B21_SCENE);
        levelIndexes.push_back(B22_SCENE);
        levelIndexes.push_back(B23_SCENE);
        levelIndexes.push_back(B24_SCENE_1);
        levelIndexes.push_back(B25_SCENE);
        levelIndexes.push_back(B26_SCENE);
        levelIndexes.push_back(B27_SCENE);
        levelIndexes.push_back(B28_SCENE_1);
        levelIndexes.push_back(B29_SCENE);
        levelIndexes.push_back(B30_SCENE);
    }
}