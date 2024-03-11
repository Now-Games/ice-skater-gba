#pragma once

#include "game_object.h"
#include "bn_rect.h"
#include "bn_fixed_point.h"
#include "bn_unique_ptr.h"

class ColliderComponent
{
    private:
        bn::unique_ptr<GameObject> parent;
        bn::rect bounds;
        bn::fixed_point collisionPoint;

    public:
        ColliderComponent(GameObject *p, int width, int height);
        ~ColliderComponent() = default;
        bn::rect getBounds();
        bn::fixed_point getCollisionPoint();
        bool isIntersecting(ColliderComponent *other);
};