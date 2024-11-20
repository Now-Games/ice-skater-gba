#include "rock_wall_cracked_game_object.h"

#include "bn_core.h"
#include "bn_sprite_items_cracked_wall_sheet.h"

namespace is
{
    RockWallCrackedGameObject::RockWallCrackedGameObject(GameScene& gs, bn::point pos, Direction dir) : 
        SpriteGameObject(gs, bn::sprite_items::cracked_wall_sheet, pos),
        crumbleAnim(bn::create_sprite_animate_action_once(sprite, 7, bn::sprite_items::cracked_wall_sheet.tiles_item(), 1, 2, 3, 4))
    {
        
    }
    
    void RockWallCrackedGameObject::interact(Player& player)
    {
        while (!crumbleAnim.done())
        {
            crumbleAnim.update();
            bn::core::update();
        }

        setTransparency(Transparency::Transparent);
    }
}