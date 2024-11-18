#include "game_scene.h"

#include "scene_helper.h"
#include "game_constants.h"
#include "bn_keypad.h"

#include "bn_log.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"

namespace is
{
    GameScene::GameScene(GameSceneDetails details) : Scene(details.levelName),
        player(Player(*this)),
        exit(RockWallHoleGameObject(*this, details.exitPosition, details.nextScene))
    {
        player.setPosition(details.startPosition);

        if (details.sceneType == SceneType::Tutorial)
            background = bn::regular_bg_items::tutorial_scene.create_bg(0, 0);
        else if (details.sceneType == SceneType::Normal)
            background = bn::regular_bg_items::stage_scene.create_bg(0, 0);

        background->set_z_order(SCENE_BACKGROUND_LAYER);

        for (int i = 0; i < details.gameObjectDetails.size(); i ++)
        {
            GameObject* object = getGameObject(*this, details.gameObjectDetails[i]);
            // BN_LOG("Game Object Type: ", object);
            obstacles.push_back(object);
        }
    }
    
    GameScene::~GameScene()
    {
        for (int i = 0; i < obstacles.size(); i++)
        {
            delete obstacles[i];
        }
        obstacles.clear();
    }

    SceneUpdateResult GameScene::update()
    {
        player.update();

        for (int i = 0; i < obstacles.size(); i ++)
        {
            obstacles[i]->update();
        }

        SceneUpdateResult result = exit.update();
        if (result.nextSceneIndex != -1) 
        {
            BN_LOG("Next Scene: ", result.nextSceneIndex);
            return result;
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
        
        if (exit.checkCollision(collider))
            return &exit;

        return nullptr;
    }
}