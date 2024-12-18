#include "cracked_ice_game_object.h"

#include "player.h"

#include "bn_core.h"
#include "bn_sprite_items_cracked_ice_sheet.h"

namespace is
{
    CrackedIceGameObject::CrackedIceGameObject(GameScene& gs, bn::point pos) : 
        SpriteGameObject(gs, bn::sprite_items::cracked_ice_sheet, pos),
        breakAnim(bn::create_sprite_animate_action_once(sprite, 7, bn::sprite_items::cracked_ice_sheet.tiles_item(), 1, 2, 3, 4))
    {
        
    }
    
    SceneUpdateResult CrackedIceGameObject::update()
    {
        if (triggered)
            return SceneUpdateResult(true);

        return SceneUpdateResult();
    }

    void CrackedIceGameObject::interact(Player& player)
    {
        while (!breakAnim.done())
        {
            breakAnim.update();
            bn::core::update();
        }

        player.fall();
        triggered = true;
    }
}