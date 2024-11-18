#include "rock_wall_hole_game_object.h"

#include "game_scene.h"
#include "bn_sprite_items_rock_wall_hole.h"

namespace is
{
    RockWallHoleGameObject::RockWallHoleGameObject(GameScene& gs, bn::point pos, int nextScene) : 
        SpriteGameObject(gs, bn::sprite_items::rock_wall_hole, pos)
    {
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

    void RockWallHoleGameObject::interact()
    {
        eventTriggered = true;
    }
}