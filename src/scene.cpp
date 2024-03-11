#include "scene.h"
#include "player.h"
#include "shuriken_obstacle.h"
#include "bn_math.h"
#include "game_constants.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"

Scene::Scene(SceneInfo sceneInfo)
{
    obstacles.push_back(Player(this, sceneInfo.startPos, sceneInfo.startDirection));
    BN_LOG("Player Starts: ", sceneInfo.startPos.x());
    
    //generate all obstacles based on sceneInfo
    // for (ObstacleInfo info : sceneInfo.obstalces)
    // {
        // if (info.type == ObstacleType::OT_Shuriken)
        //     obstacles.push_back(Shuriken(info, this));
        // else
        //     obstacles.push_back(Obstacle(info));
    // }
    
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
        obstacles[i].update();
    }

    Player *player = dynamic_cast<Player*>(&obstacles[PLAYER_INDEX]);
    if (obstacleIndex != -1)
    {
        if (player->getPosition() == obstacles[obstacleIndex].getPosition())
        {
            switch (obstacles[obstacleIndex].getObjectType())
            {
                case GameObjectType::GOT_RockHole:
                    return SceneUpdateResult::S_Next;
                case GameObjectType::GOT_StairsUp:
                    return SceneUpdateResult::S_PreviousFloor;
                case GameObjectType::GOT_StairsDown:
                    return SceneUpdateResult::S_NextFloor;
                default:
                    break;
            }
        }
    }

    // if (!player)
    //     return SceneUpdateResult::S_None;
    
    // if (!player->isMoving())
    //     getInput();
    
    // player->update();
    
    // if (!player->isMoving())
    // {
    //     //get object type
    //     if (obstacleIndex != -1)
    //     {
    //         if (obstacles[obstacleIndex].getType() == ObstacleType::RockHole)
    //             return SceneUpdateResult::S_Next;
    //         else if (obstacles[obstacleIndex].getType() == ObstacleType::StairsUp)
    //             return SceneUpdateResult::S_PreviousFloor;
    //         else if (obstacles[obstacleIndex].getType() == ObstacleType::StairsDown)
    //             return SceneUpdateResult::S_NextFloor;
    //         else if (obstacles[obstacleIndex].getType() == ObstacleType::CrackedIce)
    //         {
    //             obstacles[obstacleIndex].setDestroy();
    //             player->playFallingAnimation();
    //             return SceneUpdateResult::S_Restart;
    //         }
            
    //         if (bn::keypad::a_pressed() && 
    //             (obstacles[obstacleIndex].getType() == ObstacleType::CrackedWall || 
    //             obstacles[obstacleIndex].getType() == ObstacleType::Snowball))
    //         {
    //             obstacles[obstacleIndex].setDestroy();
    //         }
    //     }
    // }
    
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
    obstacles[PLAYER_INDEX].setPosition(rawPosition);
}

bn::fixed_point Scene::getPlayerPosition()
{
    return obstacles[PLAYER_INDEX].getPosition();
}

int Scene::getNextObstacle(bn::fixed_point position, Direction direction)
{
    int index = -1;
    bn::fixed minDist = UINT16_MAX;
    for (int i = 0; i < obstacles.size(); i ++)
    {
        if (!obstacles[i].isEnabled() || !obstacles[i].isActive() || 
                obstacles[i].getPosition() == position)
        {
            continue;
        }
            
        bn::fixed dist = 0;
        switch (direction) {
            case Direction::Up:
                if (obstacles[i].getPosition().x() != position.x() || 
                        obstacles[i].getPosition().y() > position.y()) 
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().y() - position.y());
                break;
            case Direction::Down:
                if (obstacles[i].getPosition().x() != position.x() || 
                        obstacles[i].getPosition().y() < position.y()) 
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().y() - position.y());
                break;
            case Direction::Left:
                if (obstacles[i].getPosition().y() != position.y() || 
                        obstacles[i].getPosition().x() > position.x()) 
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().x() - position.x());
                break;
            case Direction::Right:
                if (obstacles[i].getPosition().y() != position.y() || 
                        obstacles[i].getPosition().x() < position.x())
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().x() - position.x());
                break;
            default:
                break;
        }
    
        if (dist <= minDist) {
            minDist = dist;
            index = i;
        }
    }
    
    BN_LOG("Closest Obstacle: ", index);
    return index;
}