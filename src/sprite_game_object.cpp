#include "sprite_game_object.h"

#include "game_constants.h"
#include "game_scene.h"

#include "bn_log.h"

namespace is
{
    SpriteGameObject::SpriteGameObject(GameScene& gs, bn::sprite_item si, bn::point pos) : 
        GameObject(gs, pos),
        sprite(si.create_sprite(pos))
    {
        sprite.set_z_order(OBSTACLE_SPRITE_Z);
        sprite.set_bg_priority(SCENE_BACKGROUND_LAYER);
    }

    void SpriteGameObject::setPosition(bn::point pos)
    {
        GameObject::setPosition(pos);
        sprite.set_position(pos);
    }
    
    SceneUpdateResult SpriteGameObject::update()
    {
        // BN_LOG("Updating sprite game object");
        return SceneUpdateResult();
    }
}