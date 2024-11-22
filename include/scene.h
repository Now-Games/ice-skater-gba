#pragma once

#include "scene_state.h"
#include "scene_update_results.h"
#include "bn_point.h"
#include "bn_string.h"

namespace is
{
    class Scene
    {
        protected:
            bn::string<12> name;
            SceneState currentState;

        public:
            Scene(bn::string<12> ln);
            virtual ~Scene() = default;

            SceneState getCurrentState();

            bn::string<10> getLevelName();
            virtual SceneUpdateResult update();
    };
}