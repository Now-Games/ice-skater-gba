#include "scene.h"
#include "gameObjects/player.h"
#include "components/destructible_component.h"
#include "gameObjects/game_object_factory.h"
#include "bn_math.h"
#include "game_constants.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"

Scene::Scene(SceneInfo sceneInfo)
{
    gameObjects.push_back(bn::unique_ptr(new Player(this, sceneInfo.startPos, sceneInfo.startDirection)));
    BN_LOG("Player Starts: ", sceneInfo.startPos.x());
    
    //generate all gameObjects based on sceneInfo
    for (ObstacleInfo info : sceneInfo.obstalces)
    {
        if (info.type == GameObjectType::GOT_None)
            continue;

        GameObject* objPtr = createGameObject(this, info);
        BN_LOG("Object: ", objPtr->getObjectType());
        gameObjects.push_back(bn::unique_ptr(objPtr));
    }
    
    maxBounds = bn::fixed_point((SCREEN_WIDTH / 2) - BLOCK_SIZE, (SCREEN_HEIGHT / 2) - BLOCK_SIZE);
    minBounds = bn::fixed_point(-(SCREEN_WIDTH / 2) + BLOCK_SIZE, -(SCREEN_HEIGHT / 2) + BLOCK_SIZE);
    
    //load in the background
    switch(sceneInfo.sceneType) 
    {
        case SceneType::Basic:
        case SceneType::MultiLevel:
            background = bn::regular_bg_items::stage_scene.create_bg(0, 0);
            break;
        case SceneType::Event:
            background = bn::regular_bg_items::tutorial_scene.create_bg(0, 0);
            break;
        default:
            break;
    }

    background->set_z_order(6);
}

SceneUpdateResult Scene::update()
{    
    for (int i = 0; i < gameObjects.size(); i ++)
    {
        gameObjects[i]->update();
    }

    if (obstacleIndex != -1)
    {
        if (gameObjects[PLAYER_INDEX]->getPosition() == gameObjects[obstacleIndex]->getPosition())
        {
            switch (gameObjects[obstacleIndex]->getObjectType())
            {
                case GameObjectType::GOT_RockHole:
                    return SceneUpdateResult::S_Next;
                case GameObjectType::GOT_StairsUp:
                    return SceneUpdateResult::S_PreviousFloor;
                case GameObjectType::GOT_StairsDown:
                    return SceneUpdateResult::S_NextFloor;
                case GameObjectType::GOT_CrackedIce:
                {
                    DestructibleComponent *destComp = gameObjects[obstacleIndex]->getComponent<DestructibleComponent>();
                    if (destComp != nullptr)
                        destComp->destroy();
                        
                    // gameObjects[PLAYER_INDEX]->play_fall_animation();
                    return SceneUpdateResult::S_Restart;
                }
                default:
                    break;
            }
        }
    }
    
    return SceneUpdateResult::S_None;
}

bn::fixed_point Scene::getMaxBounds()
{
    return maxBounds;
}

bn::fixed_point Scene::getMinBounds()
{
    return minBounds;
}

void Scene::setMaxBounds(bn::fixed_point bounds)
{
    maxBounds = bounds;
}

void Scene::setMinBounds(bn::fixed_point bounds)
{
    minBounds = bounds;
}

void Scene::setPlayerPosition(bn::fixed_point rawPosition)
{
    gameObjects[PLAYER_INDEX]->setPosition(rawPosition);
}

bn::fixed_point Scene::getPlayerPosition()
{
    return gameObjects[PLAYER_INDEX]->getPosition();
}

bool Scene::isEmptySpace(ColliderComponent* other)
{
    bool hasCollision = false;
    for (int i = 0; i < gameObjects.size(); i ++)
    {
        if (!gameObjects[i]->isEnabled() || gameObjects[i]->isActive())
            continue;

        ColliderComponent *collComp = gameObjects[i]->getComponent<ColliderComponent>();
        if (collComp != nullptr)
        {
             hasCollision = collComp->isIntersecting(other->getBounds());
        }
    }

    return hasCollision;
}

int Scene::getNextObstacle(bn::fixed_point position, Direction direction)
{
    return 0;
}