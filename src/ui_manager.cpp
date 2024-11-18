#include "ui_manager.h"

#include "scene_update_results.h"
#include "ui_update_results.h"
#include "save_data.h"
#include "game_constants.h"

#include "bn_log.h"
#include "bn_keypad.h"
#include "pause_ui_scene.h"

namespace is
{
    UIManager::UIManager()
    {
        isVisible = false;
    }

    SceneUpdateResult UIManager::update()
    {
        if (scene != nullptr)
        {
            UIUpdateResults results = scene->update();
            switch (results.action)
            {
                case UIActions::Continue:
                    closeUI();
                    break;
                case UIActions::Restart:
                    closeUI();
                    BN_LOG("Restarting Level: ", saveData.currentScene);
                    return SceneUpdateResult(saveData.currentScene);
                case UIActions::LevelSelect:
                    closeUI();
                    BN_LOG("Loading Level Select Scene");
                    return SceneUpdateResult(LEVEL_SELECT_SCENE);
                case UIActions::Title:
                    closeUI();
                    BN_LOG("Loading Start Screen");
                    return SceneUpdateResult(START_MENU_SCENE);
                default:
                    break;
            }
        }

        return SceneUpdateResult();
    }
    
    bool UIManager::isShowing()
    {
        return isVisible;
    }

    void UIManager::showUI()
    {
        scene = new PauseUIScene();
        isVisible = true;
    }

    void UIManager::closeUI()
    {
        delete scene;
        isVisible = false;
    }
}