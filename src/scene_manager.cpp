#include "scene_manager.h"

#include "bn_keypad.h"
#include "scene_helper.h"
#include "start_menu_scene.h"
#include "credits_scene.h"
#include "final_scene.h"
#include "game_scene.h"
#include "level_select_scene.h"
#include "event_game_scene.h"
#include "multilevel_game_scene.h"
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
        creditsMusicPlaying = true;

        // Create the start scene
        currentScene = new StartMenuScene();
        currentSceneIndex = 0;
    }

    void SceneManager::update()
    {
        //Only press start if the current scene is a GameScene 
        if (currentScene != nullptr && currentScene->getCurrentState() != SceneState::Title) 
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

        SceneUpdateResult result;
        if (uiManager.isShowing()) 
            result = uiManager.update();
        else
            result = currentScene->update();

        if (result.died)
            result.nextSceneIndex = saveData.currentScene;
        else if (result.nextSceneIndex == -1)
            return;

        BN_LOG("Deleting old scene");
        delete currentScene;
        
        BN_LOG("Old Scene Deleted");
        playMusic(result.nextSceneIndex);

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
    
    void SceneManager::playMusic(int sceneIndex)
    {
        if (sceneIndex == B30_SCENE || sceneIndex == CREDITS_SCENE || sceneIndex == START_MENU_SCENE) 
        {
            if (!creditsMusicPlaying) 
            {
                bn::music_items::music_box.play();
                creditsMusicPlaying = true;
                gameMusicPlaying = false;
            }
        }
        else if (!gameMusicPlaying) 
        {
            bn::music_items::mystical_p.play();
            gameMusicPlaying = true;
            creditsMusicPlaying = false;
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
            case B30_SCENE:
                return new FinalScene();
            default:
            {
                BN_LOG("Generating Game Scene: ", sceneIndex);
                GameSceneDetails* details = getSceneDetails(sceneIndex);
                if (details->sceneType == SceneType::Normal)
                    return new GameScene(details);
                else if (details->sceneType == SceneType::Tutorial)
                    return new EventGameScene(static_cast<EventSceneDetails*>(details));
                else
                    return new MultiLevelGameScene(static_cast<MultiSceneDetails*>(details));
            }
        }
    }
}