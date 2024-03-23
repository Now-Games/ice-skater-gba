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
    obstacles.push_back(bn::unique_ptr(new Player(this, sceneInfo.startPos, sceneInfo.startDirection)));
    BN_LOG("Player Starts: ", sceneInfo.startPos.x());
    
    //generate all obstacles based on sceneInfo
    for (ObstacleInfo info : sceneInfo.obstalces)
    {
        if (info.type == GameObjectType::GOT_None)
            continue;

        GameObject* objPtr = createGameObject(this, info);
        BN_LOG("Object: ", objPtr->getObjectType());
        obstacles.push_back(bn::unique_ptr(objPtr));
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
    for (int i = 0; i < obstacles.size(); i ++)
    {
        obstacles[i]->update();
    }

    if (obstacleIndex != -1)
    {
        if (obstacles[PLAYER_INDEX]->getPosition() == obstacles[obstacleIndex]->getPosition())
        {
            switch (obstacles[obstacleIndex]->getObjectType())
            {
                case GameObjectType::GOT_RockHole:
                    return SceneUpdateResult::S_Next;
                case GameObjectType::GOT_StairsUp:
                    return SceneUpdateResult::S_PreviousFloor;
                case GameObjectType::GOT_StairsDown:
                    return SceneUpdateResult::S_NextFloor;
                case GameObjectType::GOT_CrackedIce:
                {
                    DestructibleComponent *destComp = obstacles[obstacleIndex]->getComponent<DestructibleComponent>();
                    if (destComp != nullptr)
                        destComp->destroy();
                        
                    // obstacles[PLAYER_INDEX]->play_fall_animation();
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
    obstacles[PLAYER_INDEX]->setPosition(rawPosition);
}

bn::fixed_point Scene::getPlayerPosition()
{
    return obstacles[PLAYER_INDEX]->getPosition();
}

bool Scene::isEmptySpace(GameObject* other)
{
    ColliderComponent* otherColl = other->getComponent<ColliderComponent>();
    bool hasCollision = false;
    for (int i = 0; i < obstacles.size(); i ++)
    {
        if (!obstacles[i]->isEnabled() || obstacles[i]->isActive())
            continue;

        ColliderComponent *collComp = obstacles[i]->getComponent<ColliderComponent>();
        if (collComp != nullptr)
        {
             hasCollision = collComp->isIntersecting(otherColl);
        }
    }

    return hasCollision;
}

int Scene::getNextObstacle(bn::fixed_point position, Direction direction)
{
    return 0;
    // int index = -1;
    // bn::fixed minDist = UINT16_MAX;
    // for (int i = 0; i < obstacles.size(); i ++)
    // {
    //     if (!obstacles[i]->isEnabled() || !obstacles[i]->isActive() || 
    //             obstacles[i]->getPosition() == position)
    //     {
    //         continue;
    //     }
            
    //     bn::fixed dist = 0;
    //     switch (direction) {
    //         case Direction::Up:
    //             if (obstacles[i]->getPosition().x() != position.x() || 
    //                     obstacles[i]->getPosition().y() > position.y()) 
    //             {
    //                 continue;
    //             }
                
    //             dist = bn::abs(obstacles[i]->getPosition().y() - position.y());
    //             break;
    //         case Direction::Down:
    //             if (obstacles[i]->getPosition().x() != position.x() || 
    //                     obstacles[i]->getPosition().y() < position.y()) 
    //             {
    //                 continue;
    //             }
                
    //             dist = bn::abs(obstacles[i]->getPosition().y() - position.y());
    //             break;
    //         case Direction::Left:
    //             if (obstacles[i]->getPosition().y() != position.y() || 
    //                     obstacles[i]->getPosition().x() > position.x()) 
    //             {
    //                 continue;
    //             }
                
    //             dist = bn::abs(obstacles[i]->getPosition().x() - position.x());
    //             break;
    //         case Direction::Right:
    //             if (obstacles[i]->getPosition().y() != position.y() || 
    //                     obstacles[i]->getPosition().x() < position.x())
    //             {
    //                 continue;
    //             }
                
    //             dist = bn::abs(obstacles[i]->getPosition().x() - position.x());
    //             break;
    //         default:
    //             break;
    //     }
    
    //     if (dist <= minDist) {
    //         minDist = dist;
    //         index = i;
    //     }
    // }
    
    // BN_LOG("Closest Obstacle: ", index);
    // return index;
}