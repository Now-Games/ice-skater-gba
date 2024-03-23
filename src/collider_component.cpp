#include "components/collider_component.h"
#include "gameObjects/game_object.h"

ColliderComponent::ColliderComponent(GameObject *p, int width, int height) : 
    BaseComponent(p)
{
    bounds = bn::size(width, height);
}

bn::rect ColliderComponent::getBounds()
{
    bn::fixed_point position = parent->getPosition();
    return bn::rect(bn::point(position.x().data(), position.y().data()), bounds);
}

bn::fixed_point ColliderComponent::getCollisionPoint()
{
    return collisionPoint;
}

bool ColliderComponent::isIntersecting(ColliderComponent *other)
{
    bn::fixed_point position = parent->getPosition();
    return bn::rect(bn::point(position.x().data(), position.y().data()), bounds).intersects(other->getBounds());
}