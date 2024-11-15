#include "scene_manager.h"
#include "scene_helper.h"
#include "start_menu_scene.h"

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

        currentScene = getScene(result.nextSceneIndex, result.position);
    }
}