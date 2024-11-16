#include "game_scene.h"

#include "scene_helper.h"

#include "bn_log.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"

namespace is
{
    GameScene::GameScene(GameSceneDetails details) : Scene(),
        player(Player(*this))
    {
        if (details.sceneType == SceneType::Tutorial)
            background = bn::regular_bg_items::tutorial_scene.create_bg(0, 0);
        else if (details.sceneType == SceneType::Normal)
            background = bn::regular_bg_items::stage_scene.create_bg(0, 0);

        for (int i = 0; i < details.gameObjectDetails.size(); i ++)
        {
            GameObject* object = getGameObject(*this, details.gameObjectDetails[i]);
            // BN_LOG("Game Object Type: ", object);
            obstacles.push_back(object);
        }
    }

    SceneUpdateResult GameScene::update()
    {
        player.update();

        for (int i = 0; i < obstacles.size(); i ++)
        {
            obstacles[i]->update();
        }

        return SceneUpdateResult();
    }

    GameObject* GameScene::checkCollisions(bn::rect collider)
    {
        for (int i = 0; i < obstacles.size(); i ++)
        {
            // if (collider == obstacles[i]->getCollider())
            //     continue;
                
            if (obstacles[i]->checkCollision(collider))
                return obstacles[i];
        }

        return nullptr;
    }
}