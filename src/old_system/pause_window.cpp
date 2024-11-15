#include "pause_window.h"

#include "common_fixed_8x16_sprite_font.h"

#include "bn_sprite_items_home_icon.h"
#include "bn_sprite_items_play_icon.h"
#include "bn_sprite_items_restart_icon.h"
#include "bn_sprite_items_level_select_icon.h"
#include "bn_sprite_items_menu_pointer.h"
#include "bn_regular_bg_items_pause_scene.h"
#include "bn_keypad.h"

PauseWindow::PauseWindow() : pointerSprite(bn::sprite_items::menu_pointer.create_sprite(0, 4))
{
    //Generate the option sprites
    optionSprites.push_back(bn::sprite_items::play_icon.create_sprite(-48, 4));
    optionSprites.push_back(bn::sprite_items::restart_icon.create_sprite(-16, 4));
    optionSprites.push_back(bn::sprite_items::level_select_icon.create_sprite(16, 4));
    optionSprites.push_back(bn::sprite_items::home_icon.create_sprite(48, 4));

    for (int i = 0; i < optionSprites.size(); i ++)
    {
        optionSprites.at(i).set_bg_priority(1);
    }

    // Set pointer priority higher than background
    pointerSprite.set_bg_priority(1);

    // Set the pointer sprite to the first option
    updatePointerPosition();
    
    //Create the background
    background = bn::regular_bg_items::pause_scene.create_bg(0, 0);
    background->set_priority(2);
}

void PauseWindow::updatePointerPosition()
{
    pointerSprite.set_x(-64 + (currentOption * 32));
}

PauseResult PauseWindow::update()
{
    if (bn::keypad::left_pressed())
    {
        //move pointer left
        currentOption --;
        if (currentOption < 0)
            currentOption = optionSprites.size() - 1;

        updatePointerPosition();
    }
    else if (bn::keypad::right_pressed())
    {
        //move pointer right
        currentOption ++;
        if (currentOption >= optionSprites.size())
            currentOption = 0;
            
        updatePointerPosition();
    }
    
    if (bn::keypad::a_pressed())
    {
        switch (currentOption)
        {
            case 0:
                return PauseResult::P_Continue;
            case 1:
                return PauseResult::P_Restart;
            case 2:
                return PauseResult::P_LevelSelect;
            case 3:
                return PauseResult::P_Title;
        }
    }

    return PauseResult::P_None;
}