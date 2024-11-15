#pragma once

#include "scene.h"

#include "bn_regular_bg_ptr.h"

namespace is
{
    class CreditsScene : public Scene
    {
        private:
            bn::regular_bg_ptr sceneBackground;

        public:
            CreditsScene();

            SceneUpdateResult update() override;
    };
}