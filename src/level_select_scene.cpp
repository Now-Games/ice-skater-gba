#include "level_select_scene.h"

#include "save_data.h"
#include "game_constants.h"

#include "bn_regular_bg_items_level_select_bg.h"
#include "bn_sprite_items_menu_pointer.h"

namespace is
{
    LevelSelectScene::LevelSelectScene() : Scene(),
        background(bn::regular_bg_items::level_select_bg.create_bg(0, 0)),
        pointer(bn::sprite_items::menu_pointer.create_sprite(0, 0)),
        levelIndexes({ B1_SCENE, B2_SCENE, 0, 0, 0 })
    {
        for (int i = 0; i < sizeof(levelIndexes); i ++)
        {
            if (levelIndexes[i] == SAVE_DATA.currentScene) 
            {
                selectedLevel = i;
                break;
            }
        }
    }

    SceneUpdateResult LevelSelectScene::update()
    {
        return SceneUpdateResult();
    }
}