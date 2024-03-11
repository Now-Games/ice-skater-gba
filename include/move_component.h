#pragma once

#include "direction.h"
#include "game_object.h"
#include "bn_unique_ptr.h"
#include "bn_fixed_point.h"

class MoveComponent
{
    private:
        bn::unique_ptr<GameObject> parent;
        bn::fixed_point targetPosition;
        int speed = 4;
        bool moving = false;

        void move();

    public:
        MoveComponent(GameObject *p, int speed);
        ~MoveComponent() = default;
        bool isMoving();
        void setPosition(bn::fixed_point newPos);
        void update();
};