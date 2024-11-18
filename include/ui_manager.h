#pragma once

#include "scene_update_results.h"
#include "ui_scene.h"

namespace is
{
    class UIManager
    {
        private:
            UIScene* scene;
            bool isVisible;

        public:
            UIManager();

            SceneUpdateResult update();

            bool isShowing();
            void showUI();
            void closeUI();
    };
}