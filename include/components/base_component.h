#pragma once

#include "bn_unique_ptr.h"

enum ComponentType
{
    CT_Base,
    CT_Collider,
    CT_Destructible,
    CT_Movement
};

class GameObject;
class BaseComponent
{
    protected:
        bn::unique_ptr<GameObject> parent;

    public:
        BaseComponent() = default;
        BaseComponent(GameObject*);
        virtual ~BaseComponent() = default;
        GameObject* getParent();

        virtual ComponentType getType() const 
        { 
            return ComponentType::CT_Base; 
        }
};