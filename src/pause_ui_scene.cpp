#include "pause_ui_scene.h"
#include "game_constants.h"
#include "save_data.h"

#include "bn_keypad.h"
#include "common_variable_8x8_sprite_font.h"
#include "bn_sprite_items_menu_pointer.h"
#include "bn_regular_bg_items_pause_scene.h"
#include "bn_sprite_items_home_icon.h"
#include "bn_sprite_items_play_icon.h"
#include "bn_sprite_items_restart_icon.h"
#include "bn_sprite_items_level_select_icon.h"

namespace is
{
    PauseUIScene::PauseUIScene() : UIScene(),
        background(bn::regular_bg_items::pause_scene.create_bg(0, 0)),
        pointer(bn::sprite_items::menu_pointer.create_sprite(-64, 4)),
        textGenerator(common::variable_8x8_sprite_font)
    {
        textGenerator.set_center_alignment();
        textGenerator.set_bg_priority(UI_BACKGROUND_LAYER);
        textGenerator.set_z_order(UI_SPRITE_Z);

        options.push_back(bn::sprite_items::play_icon.create_sprite(-48, 4));
        options.push_back(bn::sprite_items::restart_icon.create_sprite(-16, 4));
        options.push_back(bn::sprite_items::level_select_icon.create_sprite(16, 4));
        options.push_back(bn::sprite_items::home_icon.create_sprite(48, 4));

        for (int i = 0; i < options.size(); i ++)
        {
            options[i].set_z_order(UI_SPRITE_Z);
            options[i].set_bg_priority(UI_BACKGROUND_LAYER);
        }

        pointer.set_z_order(UI_SPRITE_Z);
        pointer.set_bg_priority(UI_BACKGROUND_LAYER);
        
        background.set_priority(UI_BACKGROUND_LAYER);

        updateText();
        updatePointer();
    }

    UIUpdateResults PauseUIScene::update()
    {
        if (bn::keypad::a_pressed())
        {
            UIActions selectedAction = static_cast<UIActions>(selectedOption + 1);
            return UIUpdateResults(selectedAction);
        }

        if (timer < INPUT_DELAY)
        {
            timer++;
            return UIUpdateResults();
        }

        bool pointerUpdated = false;
        if (bn::keypad::left_held())
        {
            pointerUpdated = true;
            selectedOption--;
            if (selectedOption < 0)
                selectedOption = options.size() - 1;
        }
        else if (bn::keypad::right_held())
        {
            pointerUpdated = true;
            selectedOption++;
            if (selectedOption >= options.size())
                selectedOption = 0;
        }

        if (pointerUpdated) 
        {
            timer = 0;
            updateText();
            updatePointer();
        }

        return UIUpdateResults();
    }
    
    void PauseUIScene::updatePointer()
    {
        pointer.set_position(-64 + (selectedOption * 32), 4);
    }
    
    void PauseUIScene::updateText()
    {
        optionTextSprites.clear();
        if (selectedOption == 0)
            textGenerator.generate(0, -20, "Continue", optionTextSprites);
        else if (selectedOption == 1)
            textGenerator.generate(0, -20, "Restart Level", optionTextSprites);
        else if (selectedOption == 2)
            textGenerator.generate(0, -20, "Level Select", optionTextSprites);
        else
            textGenerator.generate(0, -20, "Title Screen", optionTextSprites);
    }
}