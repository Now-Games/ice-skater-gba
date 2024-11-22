#pragma once 

#include "game_scene.h"

namespace is
{
    class MultiLevelGameScene : public GameScene
    {
        private:
            bn::vector<int, 5> sceneLevels;

            void generateNextLevel(int sceneIndex, bn::point position);

        public:
            MultiLevelGameScene(MultiSceneDetails* details);

            SceneUpdateResult update() override;
    };
}