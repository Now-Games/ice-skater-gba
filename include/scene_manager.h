#pragma once

#include "scene.h"
#include "bn_point.h"
#include "ui_manager.h"

namespace is
{
    class SceneManager
    {
        private:
            Scene *currentScene;
            UIManager uiManager;
            bool gameMusicPlaying = false;
            bool creditsMusicPlaying = false;
            int currentSceneIndex = 0;

            Scene *getScene(int index, bn::point pos);
            void playMusic(int index);

        public:
            SceneManager();

            void initialize();
            void update();
    };
}