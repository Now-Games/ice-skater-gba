#pragma once

#include "bn_point.h"
#include "bn_rect.h"

namespace is
{
    enum Direction
    {
        Down,
        Right,
        Left,
        Up
    };

    class GameScene;
    class GameObject
    {
        protected:
            bn::point position;
            bn::rect collider;
            Direction currentDirection;
            GameScene &scene;

        public:
            GameObject(GameScene& gs, bn::point pos);
            virtual ~GameObject() = default;

            bn::rect getCollider() { return collider; }
            Direction getDirection() { return currentDirection; }
            
            virtual void setDirection(Direction dir) { currentDirection = dir; }

            virtual void update();
            virtual void interact();
            bool checkCollision(bn::rect other);
    };
}