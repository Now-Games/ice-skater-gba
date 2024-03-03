#ifndef MULTI_LEVEL_SCENE_H
#define MULTI_LEVEL_SCENE_H

#include "scene.h"
#include "scene_info.h"
#include "scene_update_result.h"

class MultiLevelScene
{
    private:
        int currentSceneLoaded = 0;
        bn::array<int, 3> sceneIndexes;
        bn::unique_ptr<Scene> currentScene;
        void loadNextFloor();
        void loadPreviousFloor();
        
    public:
        MultiLevelScene(MultiSceneInfo sceneIndexes);
        ~MultiLevelScene() = default;
        SceneUpdateResult update();
};

#endif // MULTI_LEVEL_SCENE_H
