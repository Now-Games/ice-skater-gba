#include "gameObjects/game_object.h"
#include "scene.h"

#include "game_constants.h"

GameObject::GameObject(Scene* scene, int tileX, int tileY, GameObjectType gameObjectType)
{
    currentScene = bn::unique_ptr(scene);
    type = gameObjectType;
    x = tileX * BLOCK_SIZE;
    y = tileY * BLOCK_SIZE;
}

GameObject::GameObject(Scene* scene, int tileX, int tileY, GameObjectType gameObjectType, bn::sprite_item spriteItem)
{
    currentScene = bn::unique_ptr(scene);
    x = tileX * BLOCK_SIZE;
    y = tileY * BLOCK_SIZE;
    type = gameObjectType;
    sprite = spriteItem.create_sprite(x, y);
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

bn::fixed_point GameObject::getFixedPoint()
{
    return bn::fixed_point(x, y);
}

bn::point GameObject::getPoint()
{
    return bn::point(x, y);
}

int GameObject::getX()
{
    return x;
}

int GameObject::getY()
{
    return y;
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

void GameObject::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
    if (sprite.has_value())
        sprite->set_position(getFixedPoint());
}