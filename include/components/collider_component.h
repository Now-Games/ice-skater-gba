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

    public:
        ColliderComponent() : BaseComponent() {}
        ColliderComponent(GameObject *p, int width, int height);
        ~ColliderComponent() = default;
        bn::rect getBounds();
        bn::fixed_point getCollisionPoint();
        bool isIntersecting(ColliderComponent *other);
        ComponentType getType() const override
        {
            return ComponentType::CT_Collider;
        }
};