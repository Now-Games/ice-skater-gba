#include "credits_scene.h"

#include "bn_keypad.h"
#include "bn_regular_bg_items_credits_bg.h"

CreditsScene::CreditsScene() : 
    background(bn::regular_bg_items::credits_bg.create_bg(0, 0))
{
    
}

int CreditsScene::update()
{
    if (bn::keypad::a_pressed())
    {
        return -1;
    }

    return 0;
}