#include "sprite_game_object.h"

#include "game_constants.h"

#include "bn_log.h"

namespace is
{
    SpriteGameObject::SpriteGameObject(GameScene& gs, bn::sprite_item si, bn::point pos) : 
        GameObject(gs, pos),
        sprite(si.create_sprite(pos))
    {
        sprite.set_z_order(OBSTACLE_LAYER);
    }
    
    void SpriteGameObject::setPosition(bn::point pos)
    {
        GameObject::setPosition(pos);
        sprite.set_position(pos);
    }
    
    void SpriteGameObject::update()
    {
        // BN_LOG("Updating sprite game object");
    }
}