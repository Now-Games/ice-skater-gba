#pragma once

#include "ui_update_results.h"

namespace is
{
    class UIScene
    {
        public:
            UIScene();
            virtual ~UIScene() = default;

            virtual UIUpdateResults update();
    };
}