#pragma once

#include "direction.h"
#include "base_component.h"
#include "bn_unique_ptr.h"
#include "bn_fixed_point.h"

class MoveComponent : public BaseComponent
{
    private:
        int targetX = 0;
        int targetY = 0;
        int speed = 4;
        bool moving = false;

        void move();

    public:
        MoveComponent() : BaseComponent() {}
        MoveComponent(GameObject *, int);
        ~MoveComponent() = default;
        bool isMoving();
        void setMoving(bool);
        void setTargetPosition(int, int);
        void update();
        ComponentType getType() const override
        {
            return ComponentType::CT_Movement;
        }
};