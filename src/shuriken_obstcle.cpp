#include "shuriken_obstacle.h"

Shuriken::Shuriken(ObstacleInfo info, Scene *scene) : 
    Obstacle(info)
{
    currentScene = bn::unique_ptr(scene);
}

void Shuriken::update()
{
    //Move the Shuriken side to side between objects or the limits of the screen

}