#include "scene_manager.h"

#include "bn_keypad.h"
#include "scene_helper.h"
#include "start_menu_scene.h"
#include "credits_scene.h"
#include "game_scene.h"
#include "level_select_scene.h"
#include "save_data.h"

#include "bn_log.h"
#include "bn_music_items.h"

namespace is
{
    SceneManager::SceneManager() : uiManager(UIManager())
    {
        
    }

    void SceneManager::initialize()
    {
        bn::music_items::music_box.play();
        
        // Create the start scene
        currentScene = new StartMenuScene();
        currentSceneIndex = 0;
    }

    void SceneManager::update()
    {
        //Only press start if the current scene is a GameScene 
        if (currentSceneIndex > 2) 
        {
            if (bn::keypad::start_pressed())
            {
                //update the UI Manager
                if (uiManager.isShowing()) 
                    uiManager.closeUI();
                else 
                    uiManager.showUI();
            }
        }

        // if (currentScene != nullptr)
        //     BN_LOG("Current Scene: ", currentScene->getLevelName());

        SceneUpdateResult result;
        if (uiManager.isShowing()) 
            result = uiManager.update();
        else
            result = currentScene->update();

        if (result.nextSceneIndex == -1)
            return;

        BN_LOG("Deleting old scene");
        delete currentScene;
        
        BN_LOG("Old Scene Deleted");
        if (result.nextSceneIndex != START_MENU_SCENE && result.nextSceneIndex != CREDITS_SCENE && 
            !gameMusicPlaying)
        {
            bn::music_items::mystical_p.play();
            gameMusicPlaying = true;
        }

        BN_LOG("Next Scene: ", result.nextSceneIndex);
        currentScene = getScene(result.nextSceneIndex, result.position);
        currentSceneIndex = result.nextSceneIndex;

        if (result.nextSceneIndex != START_MENU_SCENE && result.nextSceneIndex != CREDITS_SCENE &&
            result.nextSceneIndex != LEVEL_SELECT_SCENE)
        {
            //Update Save data
            if (result.nextSceneIndex > saveData.furthestScene)
                saveData.furthestScene = result.nextSceneIndex;

            saveData.currentScene = result.nextSceneIndex;
            save();

            BN_LOG("Setting Current Scene: ", saveData.currentScene);
        }
    }

    Scene* SceneManager::getScene(int sceneIndex, bn::point position)
    {
        switch (sceneIndex)
        {
            case START_MENU_SCENE:
                BN_LOG("Generating Start Scene");
                return new StartMenuScene();
            case CREDITS_SCENE:
                BN_LOG("Generating Credits Scene");
                return new CreditsScene();
            case LEVEL_SELECT_SCENE:
                BN_LOG("Generating LevelSelect Scene");
                return new LevelSelectScene();
            default:
            {
                BN_LOG("Generating Game Scene: ", sceneIndex);
                GameSceneDetails details = getSceneDetails(sceneIndex);
                return new GameScene(details);
            }
        }
    }
}