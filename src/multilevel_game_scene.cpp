#include "multilevel_game_scene.h"

#include "bn_log.h"
#include "scene_helper.h"

namespace is
{
    MultiLevelGameScene::MultiLevelGameScene(MultiSceneDetails* details) : 
        GameScene(details),
        sceneLevels(details->sceneFloors)
    {
        
    }
    
    SceneUpdateResult MultiLevelGameScene::update()
    {
        SceneUpdateResult result = GameScene::update();

        for (int i = 0; i < sceneLevels.size(); i ++)
        {
            if (sceneLevels[i] == result.nextSceneIndex) 
            {
                generateNextLevel(result.nextSceneIndex, result.position);
                return SceneUpdateResult();
            }
        }
        
        return result;
    }

    void MultiLevelGameScene::generateNextLevel(int sceneIndex, bn::point pos)
    {
        GameSceneDetails* details = getSceneDetails(sceneIndex);

        for (int i = 0; i < gameObjects.size(); i ++)
        {
            delete gameObjects[i];
        }
        gameObjects.clear();

        currentSceneIndex = details->sceneIndex;

        gameObjects.push_back(new RockWallHoleGameObject(*this, details->exitPosition, details->exitDirection, details->nextScene));
        initializeGameObjects(details->gameObjectDetails);
        
        player.setPosition(pos);
    }
}