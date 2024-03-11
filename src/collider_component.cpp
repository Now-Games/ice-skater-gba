#include "collider_component.h"

ColliderComponent::ColliderComponent(GameObject *p, int width, int height)
{
    parent = bn::unique_ptr(p);
    bn::fixed_point position = parent->getPosition();
    bounds = bn::rect(bn::point(position.x().data(), position.y().data()), bn::size(width, height));
}

bn::rect ColliderComponent::getBounds()
{
    return bounds;
}

bn::fixed_point ColliderComponent::getCollisionPoint()
{
    return collisionPoint;
}

bool ColliderComponent::isIntersecting(ColliderComponent *other)
{
    return bounds.intersects(other->getBounds());
}