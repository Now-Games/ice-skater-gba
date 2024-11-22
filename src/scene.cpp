#include "scene.h"

namespace is
{
    Scene::Scene(bn::string<12> ln) : name(ln)
    {
        currentState = SceneState::Title;
    }

    bn::string<10> Scene::getLevelName()
    {
        return name;
    }
    
    SceneState Scene::getCurrentState()
    {
        return currentState;
    }

    SceneUpdateResult Scene::update()
    {
        return SceneUpdateResult();
    }
}