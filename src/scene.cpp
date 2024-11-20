#include "scene.h"

namespace is
{
    Scene::Scene(bn::string<12> ln) : name(ln)
    {
        
    }
    
    bn::string<10> Scene::getLevelName()
    {
        return name;
    }

    SceneUpdateResult Scene::update()
    {
        return SceneUpdateResult();
    }
}