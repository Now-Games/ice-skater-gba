#include "game_object.h"
#include "game_scene.h"

#include "bn_log.h"

namespace is
{
    GameObject::GameObject(GameScene& gs, bn::point pos) : 
        position(pos), 
        collider(bn::rect()),
        scene(gs)
    {
        
    }
    
    void GameObject::update()
    {
        BN_LOG("Updating empty game object");
    }
    
    bool GameObject::checkCollision(bn::rect other)
    {
        return other.intersects(collider);
    }
}