#include "scene.h"
#include "bn_math.h"
#include "game_constants.h"
#include "bn_regular_bg_items_stage_scene.h"
#include "bn_regular_bg_items_tutorial_scene.h"

Scene::Scene(SceneInfo sceneInfo)
{
    player = Player(sceneInfo.startPos, sceneInfo.startDirection);
    BN_LOG("Player Starts: ", sceneInfo.startPos.x());
    
    //generate all obstacles based on sceneInfo
    for (ObstacleInfo info : sceneInfo.obstalces)
    {
        if (info.type != ObstacleType::OT_None)
            obstacles.push_back(Obstacle(info));
    }
    
    maxBounds = bn::fixed_point((SCREEN_WIDTH / 2) - 8, (SCREEN_HEIGHT / 2) - 8);
    minBounds = bn::fixed_point(-(SCREEN_WIDTH / 2) + 8, -(SCREEN_HEIGHT / 2) + 8);
    
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

void Scene::getInput()
{
    if (bn::keypad::up_pressed()) 
    {
        obstacleIndex = getNextObstacle(Direction::Up);
        player->setDirection(Direction::Up);
        if (obstacleIndex == -1) //Set Player moveLimit to max Bounds
            player->setMoveLimit(bn::fixed_point(player->getPosition().x(), minBounds.y()));
        else 
            player->setMoveLimit(obstacles[obstacleIndex].getStopPosition(Direction::Down));
    }
    else if (bn::keypad::left_pressed())
    {
        obstacleIndex = getNextObstacle(Direction::Left);
        player->setDirection(Direction::Left);
        if (obstacleIndex == -1) //Set Player moveLimit to max Bounds
            player->setMoveLimit(bn::fixed_point(minBounds.x(), player->getPosition().y()));
        else 
            player->setMoveLimit(obstacles[obstacleIndex].getStopPosition(Direction::Right));
    }
    else if (bn::keypad::right_pressed())
    {
        obstacleIndex = getNextObstacle(Direction::Right);
        player->setDirection(Direction::Right);
        if (obstacleIndex == -1) //Set Player moveLimit to max Bounds
            player->setMoveLimit(bn::fixed_point(maxBounds.x(), player->getPosition().y()));
        else 
            player->setMoveLimit(obstacles[obstacleIndex].getStopPosition(Direction::Left)); //get the stop position from the opposite direction of the obstacle from travel
    }
    else if (bn::keypad::down_pressed())
    {
        obstacleIndex = getNextObstacle(Direction::Down);
        player->setDirection(Direction::Down);
        if (obstacleIndex == -1) //Set Player moveLimit to max Bounds
            player->setMoveLimit(bn::fixed_point(player->getPosition().x(), maxBounds.y()));
        else 
            player->setMoveLimit(obstacles[obstacleIndex].getStopPosition(Direction::Up));
    }
}

SceneUpdateResult Scene::update()
{    
    if (!player)
        return SceneUpdateResult::S_None;
    
    if (!player->isMoving())
        getInput();
    
    player->update();
    
    if (!player->isMoving())
    {
        //get object type
        if (obstacleIndex != -1)
        {
            if (obstacles[obstacleIndex].getType() == ObstacleType::RockHole)
                return SceneUpdateResult::S_Next;
            else if (obstacles[obstacleIndex].getType() == ObstacleType::StairsUp)
                return SceneUpdateResult::S_PreviousFloor;
            else if (obstacles[obstacleIndex].getType() == ObstacleType::StairsDown)
                return SceneUpdateResult::S_NextFloor;
            else if (obstacles[obstacleIndex].getType() == ObstacleType::CrackedIce)
            {
                obstacles[obstacleIndex].setDestroy();
                player->playFallingAnimation();
                return SceneUpdateResult::S_Restart;
            }
            
            if (bn::keypad::a_pressed() && (obstacles[obstacleIndex].getType() == ObstacleType::CrackedWall || 
                                            obstacles[obstacleIndex].getType() == ObstacleType::Snowball))
            {
                obstacles[obstacleIndex].setDestroy();
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
    if (player.has_value())
        player->setPosition(rawPosition);
}

bn::fixed_point Scene::getPlayerPosition()
{
    if (player.has_value())
        return player->getPosition();
    else
        return bn::fixed_point();
}

int Scene::getNextObstacle(Direction direction)
{
    int index = -1;
    bn::fixed minDist = INT16_MAX;
    for (int i = 0; i < obstacles.size(); i ++)
    {
        if (obstacles[i].isTransparent() || obstacles[i].isDestroyed() || 
                obstacles[i].getPosition() == player->getPosition())
        {
            continue;
        }
            
        bn::fixed dist = 0;
        switch (direction) {
            case Direction::Up:
                if (obstacles[i].getPosition().x() != player->getPosition().x() || 
                        obstacles[i].getPosition().y() > player->getPosition().y()) 
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().y() - player->getPosition().y());
                break;
            case Direction::Down:
                if (obstacles[i].getPosition().x() != player->getPosition().x() || 
                        obstacles[i].getPosition().y() < player->getPosition().y()) 
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().y() - player->getPosition().y());
                break;
            case Direction::Left:
                if (obstacles[i].getPosition().y() != player->getPosition().y() || 
                        obstacles[i].getPosition().x() > player->getPosition().x()) 
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().x() - player->getPosition().x());
                break;
            case Direction::Right:
                if (obstacles[i].getPosition().y() != player->getPosition().y() || 
                        obstacles[i].getPosition().x() < player->getPosition().x())
                {
                    continue;
                }
                
                dist = bn::abs(obstacles[i].getPosition().x() - player->getPosition().x());
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