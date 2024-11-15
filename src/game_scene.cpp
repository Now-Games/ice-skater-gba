#include "game_scene.h"

namespace is
{
    GameScene::GameScene() : 
        player(Player(*this))
    {
        
    }
    
    SceneUpdateResult GameScene::update()
    {
        player.update();

        for (int i = 0; i < obstacles.size(); i ++)
        {
            obstacles[i]->update();
        }
    }
    
    GameObject* GameScene::checkCollisions(bn::rect collider)
    {
        for (int i = 0; i < obstacles.size(); i ++)
        {
            if (obstacles[i]->checkCollision(collider))
                return obstacles[i];
        }

        return nullptr;
    }
}