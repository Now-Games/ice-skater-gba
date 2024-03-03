#include "multi_level_scene.h"
#include "game_scenes.h"

MultiLevelScene::MultiLevelScene(MultiSceneInfo sceneInfo)
{
    sceneIndexes = sceneInfo.sceneIndexes;
    currentSceneLoaded = sceneInfo.mainScene;
    currentScene = bn::unique_ptr(new Scene(getSceneDetails(sceneIndexes[currentSceneLoaded])));
    BN_LOG("Current Scene Loaded: ", currentSceneLoaded);
}

void MultiLevelScene::loadNextFloor()
{
    currentSceneLoaded ++;
    SceneInfo sceneInfo = getSceneDetails(sceneIndexes[currentSceneLoaded]);
    bn::fixed_point playerPosition = currentScene->getPlayerPosition();
    
    currentScene.reset();
    currentScene = bn::unique_ptr(new Scene(sceneInfo));
    currentScene->setPlayerPosition(playerPosition);
}

void MultiLevelScene::loadPreviousFloor()
{
    currentSceneLoaded --;
    SceneInfo sceneInfo = getSceneDetails(sceneIndexes[currentSceneLoaded]);
    bn::fixed_point playerPosition = currentScene->getPlayerPosition();
    
    currentScene.reset();
    currentScene = bn::unique_ptr(new Scene(sceneInfo));
    currentScene->setPlayerPosition(playerPosition);
}

SceneUpdateResult MultiLevelScene::update()
{    
    SceneUpdateResult result = currentScene->update();
    switch (result)
    {
        case SceneUpdateResult::S_NextFloor:
            loadNextFloor();
            result = SceneUpdateResult::S_None;
            break;
        case SceneUpdateResult::S_PreviousFloor:
            loadPreviousFloor();
            result = SceneUpdateResult::S_None;
            break;
        case SceneUpdateResult::S_Restart:
            if (currentSceneLoaded < sceneIndexes.size() - 1) {
                loadNextFloor();
                result = SceneUpdateResult::S_None;
            }
            break;
        default:
            break;
    }
    
    return result;
}