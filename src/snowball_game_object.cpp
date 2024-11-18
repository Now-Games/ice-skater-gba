#include "snowball_game_object.h"

#include "bn_core.h"
#include "bn_sprite_items_snowball_sheet.h"

namespace is
{
    SnowballGameObject::SnowballGameObject(GameScene& gs, bn::point pos) : 
        SpriteGameObject(gs, bn::sprite_items::snowball_sheet, pos),
        breakAnim(bn::create_sprite_animate_action_once(sprite, 7, bn::sprite_items::snowball_sheet.tiles_item(), 1, 2, 3, 4, 5))
    {
        
    }

    void SnowballGameObject::interact()
    {
        while (!breakAnim.done())
        {
            breakAnim.update();
            bn::core::update();
        }

        setTransparency(Transparency::Transparent);
    }
}