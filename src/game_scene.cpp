#include "game_scene.h"

#include "scene_helper.h"
#include "game_constants.h"

#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_log.h"
#include "bn_regular_bg_items_floor_title_bg.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"
#include "fixed_32x64_sprite_font.h"
#include "common_variable_8x16_sprite_font.h"

namespace is
{
    GameScene::GameScene(GameSceneDetails* details) : Scene(details->levelName),
        player(Player(*this)),
        titleTextGenerator(bn::sprite_text_generator(fixed_32x64_sprite_font)),
        textGenerator(bn::sprite_text_generator(common::variable_8x16_sprite_font))
    {
        currentSceneIndex = details->sceneIndex;
        sceneBounds = bn::rect(0, 0, bn::display::width(), bn::display::height());

        player.setPosition(details->startPosition);

        background = bn::regular_bg_items::floor_title_bg.create_bg(0, 0);
        background->set_z_order(0);
        background->set_priority(0);

        titleTextGenerator.set_center_alignment();
        titleTextGenerator.set_bg_priority(0);
        titleTextGenerator.generate(0, -40, name, titleSprites);

        textGenerator.set_center_alignment();
        textGenerator.set_bg_priority(0);
        textGenerator.set_one_sprite_per_character(false);
        textGenerator.generate(0, 40, "Press A to continue", textSprites);

        sceneType = details->sceneType;
        
        initializeGameObjects(details->gameObjectDetails);

        //add the exit
        gameObjects.push_back(new RockWallHoleGameObject(*this, details->exitPosition, details->exitDirection, details->nextScene));
    }

    GameScene::~GameScene()
    {
        for (int i = 0; i < gameObjects.size(); i++)
        {
            delete gameObjects[i];
        }
        gameObjects.clear();
    }
    
    void GameScene::initializeGameObjects(bn::vector<GameObjectDetails, 40> objectDetails)
    {
        for (int i = 0; i < objectDetails.size(); i ++)
        {
            GameObject* object = getGameObject(*this, objectDetails[i]);
            // BN_LOG("Game Object Type: ", object);
            gameObjects.push_back(object);
        }
    }
    
    void GameScene::loadBackground()
    {
        if (sceneType == SceneType::Tutorial)
            background = bn::regular_bg_items::tutorial_scene.create_bg(0, 0);
        else if (sceneType == SceneType::Normal || 
            sceneType == SceneType::MultiLevel)
        {
            background = bn::regular_bg_items::stage_scene.create_bg(0, 0);
        }
        
        background->set_z_order(SCENE_BACKGROUND_LAYER);
        background->set_priority(SCENE_BACKGROUND_LAYER);
    }

    SceneUpdateResult GameScene::update()
    {
        if (currentState == SceneState::Title)
        {
            if (bn::keypad::a_pressed())
            {
                loadBackground();
                titleSprites.clear();
                textSprites.clear();
                currentState = SceneState::Play;
            }
        }
        else
        {
            player.update();

            for (int i = 0; i < gameObjects.size(); i ++)
            {
                SceneUpdateResult result = gameObjects[i]->update();
                if (result.nextSceneIndex != -1) 
                {
                    BN_LOG("Next Scene: ", result.nextSceneIndex);
                    return result;
                }
            }
        }
        return SceneUpdateResult();
    }

    GameObject* GameScene::checkCollisions(bn::rect collider)
    {
        GameObject *priority = nullptr;
        for (int i = 0; i < gameObjects.size(); i++)
        {
            //Transparent objects should be ignored
            //If a game object in the same spot has a higher Level of Transparency, then that takes priority
            if (gameObjects[i]->checkCollision(collider) && gameObjects[i]->getTransparency() != Transparency::Transparent)
            {
                if (priority == nullptr || gameObjects[i]->getTransparency() > priority->getTransparency())
                    priority = gameObjects[i];
            }
        }

        return priority;
    }
    
    Player* GameScene::checkPlayerCollision(bn::rect collider)
    {
        if (player.checkCollision(collider))
            return &player;

        return nullptr;
    }

    bn::rect GameScene::getSceneBounds()
    {
        return sceneBounds;
    }
    
    int GameScene::getCurrentSceneIndex()
    {
        return currentSceneIndex;
    }
}