#pragma once

#include "components/base_component.h"
#include "direction.h"
#include "bn_unique_ptr.h"
#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_item.h"
#include "bn_vector.h"

enum GameObjectType
{
    GOT_None,
    GOT_Player,
    GOT_IceRock,
    GOT_RockWall,
    GOT_RockHole,
    GOT_CrackedWall,
    GOT_CrackedIce,
    GOT_Snowball,
    GOT_SnowPatch,
    GOT_StairsUp,
    GOT_StairsDown,
    GOT_Shuriken
};

class Scene;
class GameObject
{
    protected:
        bn::unique_ptr<Scene> currentScene;
        GameObjectType type = GameObjectType::GOT_None;
        bn::fixed_point position;
        Direction direction = Direction::Down;
        bn::optional<bn::sprite_ptr> sprite;
        bn::vector<BaseComponent*, 5> components;
        bool active = true;
        bool enabled = true;

    public:
        GameObject(Scene*, bn::fixed_point, GameObjectType);
        GameObject(Scene*, bn::fixed_point, GameObjectType, bn::sprite_item);
        virtual ~GameObject();
        bn::sprite_ptr getSprite();
        bn::fixed_point getPosition();
        Direction getDirection();
        GameObjectType getObjectType();
        bool isEnabled();
        bool isActive();
        void setEnabled(bool e);
        void setActive(bool a);
        virtual void setPosition(bn::fixed_point newPos);
        virtual void setDirection(Direction newDir);
        virtual void update() {};

        template<typename T>
        void addComponent(T* component)
        {
            components.push_back(component);
        }

        template<typename T>
        T* getComponent()
        {
            for (BaseComponent* baseComponent : components)
            {
                T instance = T{};
                if (baseComponent->getType() != instance.getType())
                    continue;

                T* component = static_cast<T*>(baseComponent);
                if (component != nullptr)
                    return component;
            }

            return nullptr;
        }
};