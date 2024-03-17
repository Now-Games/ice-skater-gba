#pragma once

#include "bn_sprite_animate_actions.h"

class IDestructible
{
    protected:
        bn::sprite_animate_action<5> destroyAnimation;

    public:
        IDestructible();
        virtual ~IDestructible() = default;
        virtual void destroy();
};