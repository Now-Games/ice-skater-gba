#pragma once

#include "base_component.h"
#include "bn_unique_ptr.h"
#include "bn_sprite_item.h"
#include "bn_sprite_animate_actions.h"

class DestructibleComponent : public BaseComponent
{
    protected:
        bool autoDestroy = false;
        bn::optional<bn::sprite_animate_action<5>> destroyAnimation;

    public:
        DestructibleComponent() : BaseComponent() {}
        DestructibleComponent(GameObject*, bn::sprite_item);
        ~DestructibleComponent() = default;
        void destroy();
        ComponentType getType() const override
        {
            return ComponentType::CT_Destructible;
        }
};