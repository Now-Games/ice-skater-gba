#pragma once

#include "scene_update_results.h"
#include "bn_point.h"
#include "bn_string.h"

namespace is
{
    class Scene
    {
        private:
            bn::string<10> name;

        public:
            Scene(bn::string<10> ln);
            virtual ~Scene() = default;

            bn::string<10> getLevelName();
            virtual SceneUpdateResult update();
    };
}