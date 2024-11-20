#include "rock_wall_game_object.h"

#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_items_rock_wall.h"

namespace is
{
    RockWallGameObject::RockWallGameObject(GameScene& gs, bn::point pos, Direction dir) : 
        SpriteGameObject(gs, bn::sprite_items::rock_wall, pos)
    {
        sprite.set_tiles(bn::sprite_items::rock_wall.tiles_item().create_tiles(dir));
    }
}