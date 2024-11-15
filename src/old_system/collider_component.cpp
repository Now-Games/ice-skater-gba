#include "components/collider_component.h"
#include "gameObjects/game_object.h"

ColliderComponent::ColliderComponent(GameObject *p, int width, int height, bool t) : 
    BaseComponent(p)
{
    trigger = t;
    bounds = bn::size(width, height);
}

bn::rect ColliderComponent::getBounds()
{
    bn::point position = parent->getPoint();
    return bn::rect(position, bounds);
}

bn::fixed_point ColliderComponent::getCollisionPoint()
{
    return collisionPoint;
}

bool ColliderComponent::isIntersecting(bn::rect other)
{
    return getBounds().intersects(other);
}

bool ColliderComponent::isTrigger()
{
    return trigger;
}