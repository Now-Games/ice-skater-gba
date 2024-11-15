#include "credits_scene.h"

#include "scene_helper.h"

#include "bn_keypad.h"
#include "bn_regular_bg_items_credits_bg.h"

namespace is
{
    CreditsScene::CreditsScene() :
        sceneBackground(bn::regular_bg_items::credits_bg.create_bg(0, 0))
    {
        
    }
    
    SceneUpdateResult CreditsScene::update()
    {
        if (bn::keypad::a_pressed() || bn::keypad::b_pressed())
        {
            return SceneUpdateResult(START_MENU_SCENE);
        }

        return SceneUpdateResult();
    }
}