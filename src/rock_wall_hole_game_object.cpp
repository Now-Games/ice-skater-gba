#include "rock_wall_hole_game_object.h"

#include "game_scene.h"
#include "bn_sprite_items_rock_wall_hole.h"

namespace is
{
    RockWallHoleGameObject::RockWallHoleGameObject(GameScene& gs, bn::point pos, Direction dir, int nextScene) : 
        SpriteGameObject(gs, bn::sprite_items::rock_wall_hole, pos)
    {
        sprite.set_tiles(bn::sprite_items::rock_wall_hole.tiles_item().create_tiles(dir));
        sprite.set_z_order(5);

        setTransparency(Transparency::Translucent);
        nextSceneIndex = nextScene;
        eventTriggered = false;
    }
    
    SceneUpdateResult RockWallHoleGameObject::update()
    {
        if (eventTriggered)
            return SceneUpdateResult(nextSceneIndex);
        else
            return SceneUpdateResult();
    }

    void RockWallHoleGameObject::interact(Player& player)
    {
        eventTriggered = true;
    }
}