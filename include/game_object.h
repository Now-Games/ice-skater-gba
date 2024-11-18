#pragma once

#include "scene_update_results.h"
#include "direction.h"
#include "bn_point.h"
#include "bn_rect.h"

namespace is
{
    // Determines the player's interaction on collision
    enum Transparency
    {
        Transparent,
        Translucent,
        Opaque
    };

    enum CollisionState
    {
        Enter,
        Exit
    };

    class GameScene;
    class GameObject
    {
        protected:
            GameScene &scene;
            bn::point position;
            bn::rect collider;
            Transparency collisionTransparency;
            CollisionState currentCollisionState;

        public:
            GameObject(GameScene& gs, bn::point pos);
            virtual ~GameObject() = default;

            bn::point getPosition();
            bn::rect getCollider();
            Transparency getTransparency();
            CollisionState getCollisionState();
            virtual void setPosition(bn::point pos);
            void setTransparency(Transparency ct);
            void setCollisionState(CollisionState state);

            virtual SceneUpdateResult update();
            virtual void interact();
            bool checkCollision(bn::rect other);
    };
}