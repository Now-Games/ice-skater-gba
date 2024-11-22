#include "stairs_game_object.h"

#include "save_data.h"
#include "game_scene.h"
#include "bn_sprite_items_stairs_sheet.h"

namespace is
{
    StairsGameObject::StairsGameObject(GameScene& gs, bn::point pos, Direction dir) : 
        SpriteGameObject(gs, bn::sprite_items::stairs_sheet, pos)
    {
        sprite.set_tiles(bn::sprite_items::stairs_sheet.tiles_item().create_tiles(dir));
        direction = dir;
    }

    SceneUpdateResult StairsGameObject::update()
    {
        if (eventTriggered) 
        {
            if (direction == Direction::Down)
                return SceneUpdateResult(scene.getCurrentSceneIndex() + 1, position);
            else if (direction == Direction::Up)
                return SceneUpdateResult(scene.getCurrentSceneIndex() - 1, position);
        }

        return SceneUpdateResult();
    }

    void StairsGameObject::interact(Player& player)
    {
        eventTriggered = true;
    }
}