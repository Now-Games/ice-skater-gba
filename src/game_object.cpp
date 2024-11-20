#include "game_object.h"
#include "game_scene.h"

#include "bn_log.h"

namespace is
{
    GameObject::GameObject(GameScene& gs, bn::point pos) : 
        scene(gs)
    {
        collider = bn::rect(bn::point(), bn::size(16, 16));
        setPosition(pos);

        currentCollisionState = CollisionState::Exit;
    }

    SceneUpdateResult GameObject::update()
    {
        // BN_LOG("Updating empty game object");
        return SceneUpdateResult();
    }

    bn::point GameObject::getPosition()
    {
        return position;
    }

    bn::rect GameObject::getCollider()
    {
        return collider;
    }
    
    Transparency GameObject::getTransparency()
    {
        return collisionTransparency;
    }
    
    CollisionState GameObject::getCollisionState()
    {
        return currentCollisionState;
    }

    void GameObject::setPosition(bn::point pos)
    {
        position = pos;
        collider.set_position(pos);
    }
    
    void GameObject::setTransparency(Transparency ct)
    {
        collisionTransparency = ct;
    }
    
    void GameObject::setCollisionState(CollisionState state)
    {
        currentCollisionState = state;
    }

    void GameObject::interact(Player& player)
    {
        //Do something here
    }

    bool GameObject::checkCollision(bn::rect other)
    {
        bool collision = collider.intersects(other);
        return collision;
    }
}