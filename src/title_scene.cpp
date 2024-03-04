#include "title_scene.h"

#include "bn_core.h"
#include "bn_keypad.h"
#include "game_constants.h"
#include "bn_sprite_items_menu_pointer.h"
#include "bn_regular_bg_items_title_scene.h"
#include "common_variable_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"

TitleScene::TitleScene(SaveData saveData) : 
    menuGenerator(bn::sprite_text_generator(common::variable_8x16_sprite_font)),
    versionGenerator(bn::sprite_text_generator(common::variable_8x8_sprite_font)),
    menuPointer(bn::sprite_items::menu_pointer.create_sprite(0, 0)),
    background(bn::regular_bg_items::title_scene.create_bg(0,0))
{
    currentSelection = 0;
    lastPlayedScene = saveData.currentScene;

    menuOptions.push_back("New Game");
    if (saveData.furthestScene > 0)
        menuOptions.push_back("Continue");
    menuOptions.push_back("Credits");

    menuGenerator.set_center_alignment();
    for (int i = 0; i < menuOptions.size(); i ++) 
    {
        menuGenerator.generate(
            0,
            MENU_START_Y + (i * 16),
            menuOptions.at(i),
            menuSprites);
    }
    
    //Version
    versionGenerator.set_left_alignment();
    versionGenerator.generate(MIN_X, MAX_Y - 16, "v" + version, versionSprites);

    updatePointerPosition();
}

void TitleScene::updatePointerPosition()
{
    menuPointer.set_position(
        -(menuOptions.at(currentSelection).size() / 2 * 8) - 16, 
        MENU_START_Y + (currentSelection * 16)
    );
}

int TitleScene::update()
{
    //get input and set pointer to positions based on which options selected
    if (bn::keypad::up_pressed())
    {
        currentSelection--;
        if (currentSelection < 0)
            currentSelection = 0;
        updatePointerPosition();
    }
    else if (bn::keypad::down_pressed())
    {
        currentSelection++;
        if (currentSelection >= menuOptions.size())
            currentSelection = menuOptions.size() - 1;
        updatePointerPosition();
    }

    if (bn::keypad::a_pressed())
    {
        switch (currentSelection)
        {
            case 0:
                return 0;
            case 1:
                return lastPlayedScene;
            case 2: //Credits
                return -2;
            }
    }

    return -1;
}