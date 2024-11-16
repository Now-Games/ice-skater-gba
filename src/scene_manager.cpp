#include "scene_manager.h"

#include "scene_helper.h"
#include "start_menu_scene.h"
#include "credits_scene.h"
#include "game_scene.h"
#include "level_select_scene.h"

#include "bn_log.h"
#include "bn_music_items.h"

namespace is
{
    SceneManager::SceneManager()
    {
        
    }
    
    void SceneManager::initialize()
    {
        bn::music_items::music_box.play();
        
        // Create the start scene
        currentScene = new StartMenuScene();
    }

    void SceneManager::update()
    {
        SceneUpdateResult result = currentScene->update();
        if (result.nextSceneIndex == -1)
            return;

        delete currentScene;
        if (result.nextSceneIndex != START_MENU_SCENE && result.nextSceneIndex != CREDITS_SCENE)
            bn::music_items::mystical_p.play();

        BN_LOG("Next Scene: ", result.nextSceneIndex);
        currentScene = getScene(result.nextSceneIndex, result.position);
    }
    
    Scene* SceneManager::getScene(int sceneIndex, bn::point position)
    {
        switch (sceneIndex)
        {
            case START_MENU_SCENE:
                return new StartMenuScene();
            case CREDITS_SCENE:
                return new CreditsScene();
            case LEVEL_SELECT_SCENE:
                return new LevelSelectScene();
            default:
            {
                GameSceneDetails details = getSceneDetails(sceneIndex);
                return new GameScene(details);
            }
        }
    }
}