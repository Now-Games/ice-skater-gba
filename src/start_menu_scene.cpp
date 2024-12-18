#include "start_menu_scene.h"
#include "save_data.h"
#include "game_constants.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "common_fixed_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"
#include "bn_sprite_items_menu_pointer.h"
#include "bn_regular_bg_items_title_scene.h"
#include "bn_music_items.h"

namespace is
{
    StartMenuScene::StartMenuScene() : Scene("StartMenu"),
        background(bn::regular_bg_items::title_scene.create_bg(0, 0)),
        optionsTextGenerator(common::fixed_8x16_sprite_font),
        versionTextGenerator(common::variable_8x8_sprite_font),
        pointer(bn::sprite_items::menu_pointer.create_sprite(0, 0))
    {
        if (saveData.currentScene == 0)
        {
            options.push_back("New Game");
            options.push_back("Credits");
            selectedOption = 0;
        }
        else
        {
            options.push_back("New Game");
            options.push_back("Continue");
            options.push_back("Credits");
            selectedOption = 1;
        }

        optionsTextGenerator.set_center_alignment();
        versionTextGenerator.set_right_alignment();

        for (int i = 0; i < options.size(); i ++)
        {
            optionsTextGenerator.generate(0, 20 + (i * SPACE_BETWEEN_OPTIONS), options[i], optionsSprites);
        }
        versionTextGenerator.generate(bn::display::width() / 2, 
                                      (bn::display::height() / 2) - 4, 
                                      GAME_VERSION, versionSprites);

        updatePointer();
    }

    SceneUpdateResult StartMenuScene::update()
    {
        if (timer < INPUT_DELAY)
            timer++;

        if (bn::keypad::a_pressed())
        {
            SceneUpdateResult result = getNextSceneDetails();
            return result;
        }

        if (timer < INPUT_DELAY)
            return SceneUpdateResult();

        bool selectionUpdated = false;
        if (bn::keypad::up_held())
        {
            selectionUpdated = true;
            selectedOption--;
            if (selectedOption < 0)
                selectedOption = options.size() - 1;
        }
        else if (bn::keypad::down_held())
        {
            selectionUpdated = true;
            selectedOption++;
            if (selectedOption >= options.size())
                selectedOption = 0;
        }
        
        if (selectionUpdated)
        {
            timer = 0;
            updatePointer();
        }

        return SceneUpdateResult();
    }
    
    SceneUpdateResult StartMenuScene::getNextSceneDetails()
    {
        switch (selectedOption)
        {
            case 0:
                return SceneUpdateResult(B1_SCENE);
            case 1:
                if (saveData.currentScene == 0)
                    return SceneUpdateResult(CREDITS_SCENE);
                else
                    return SceneUpdateResult(LEVEL_SELECT_SCENE);
            case 2:
                return SceneUpdateResult(CREDITS_SCENE);
            default:
                return SceneUpdateResult();
        }
    }
    
    void StartMenuScene::updatePointer()
    {
        pointer.set_position(-40, 20 + (selectedOption * SPACE_BETWEEN_OPTIONS));
    }
}