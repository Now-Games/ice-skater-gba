#pragma once

#include "base_component.h"
#include "bn_rect.h"
#include "bn_fixed_point.h"
#include "bn_unique_ptr.h"

class ColliderComponent : public BaseComponent
{
    private:
        bn::size bounds;
        bn::fixed_point collisionPoint;
        bool trigger = false;

    public:
        ColliderComponent() : BaseComponent() {}
        ColliderComponent(GameObject *p, int width, int height, bool trigger = false);
        ~ColliderComponent() = default;
        bn::rect getBounds();
        bn::fixed_point getCollisionPoint();
        bool isIntersecting(bn::rect other);
        bool isTrigger();
        ComponentType getType() const override
        {
            return ComponentType::CT_Collider;
        }
};