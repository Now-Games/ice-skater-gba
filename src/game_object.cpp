#include "game_object.h"

#include "game_constants.h"

GameObject::GameObject(bn::fixed_point tilePosition)
{
    position = tilePosition * BLOCK_SIZE;
}

GameObject::GameObject(bn::fixed_point tilePosition, bn::sprite_item spriteItem)
{
    position = tilePosition * BLOCK_SIZE;
    sprite = spriteItem.create_sprite(position.x(), position.y());
    sprite->set_z_order(4);
}

bn::sprite_ptr GameObject::getSprite()
{
    return sprite.value();
}

bn::fixed_point GameObject::getPosition()
{
    return position;
}

Direction GameObject::getDirection()
{
    return direction;
}

GameObjectType GameObject::getObjectType()
{
    return type;
}

bool GameObject::isActive()
{
    return active;
}

bool GameObject::isEnabled()
{
    return enabled;
}

void GameObject::setActive(bool a)
{
    active = a;
}

void GameObject::setEnabled(bool e)
{
    enabled = e;
}

void GameObject::setDirection(Direction dir)
{
    direction = dir;
}

void GameObject::setPosition(bn::fixed_point newPos)
{
    position = newPos;
    if (sprite.has_value())
        sprite->set_position(position);
}