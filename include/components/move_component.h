#pragma once

#include "direction.h"
#include "base_component.h"
#include "bn_unique_ptr.h"
#include "bn_fixed_point.h"

class MoveComponent : public BaseComponent
{
    private:
        bn::fixed_point targetPosition;
        int speed = 4;
        bool moving = false;

        void move();

    public:
        MoveComponent() : BaseComponent() {}
        MoveComponent(GameObject *, int);
        ~MoveComponent() = default;
        bool isMoving();
        void setMoving(bool);
        void setTargetPosition(bn::fixed_point);
        void update();
        ComponentType getType() const override
        {
            return ComponentType::CT_Movement;
        }
};