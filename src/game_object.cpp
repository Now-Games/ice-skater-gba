#include "gameObjects/game_object.h"
#include "scene.h"

#include "game_constants.h"

GameObject::GameObject(Scene* scene, bn::fixed_point tilePosition, GameObjectType gameObjectType)
{
    currentScene = bn::unique_ptr(scene);
    type = gameObjectType;
    position = tilePosition * BLOCK_SIZE;
}

GameObject::GameObject(Scene* scene, bn::fixed_point tilePosition, GameObjectType gameObjectType, bn::sprite_item spriteItem)
{
    currentScene = bn::unique_ptr(scene);
    position = tilePosition * BLOCK_SIZE;
    type = gameObjectType;
    sprite = spriteItem.create_sprite(position.x(), position.y());
    sprite->set_z_order(4);
}

GameObject::~GameObject()
{
    for (int i = 0; i < components.size(); i ++)
    {
        delete components[i];
    }
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