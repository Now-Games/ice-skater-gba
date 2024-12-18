#include "rock_wall_cracked_game_object.h"

#include "bn_core.h"
#include "bn_sprite_items_cracked_wall_sheet.h"

namespace is
{
    RockWallCrackedGameObject::RockWallCrackedGameObject(GameScene& gs, bn::point pos, Direction dir) : 
        SpriteGameObject(gs, bn::sprite_items::cracked_wall_sheet, pos),
        crumbleAnim(bn::create_sprite_animate_action_once(sprite, 7, bn::sprite_items::cracked_wall_sheet.tiles_item(), 
            (dir * 4) + 1, (dir * 4) + 2, (dir * 4) + 3, (dir * 4) + 4))
    {
        sprite.set_tiles(bn::sprite_items::cracked_wall_sheet.tiles_item().create_tiles((dir * 5)));
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