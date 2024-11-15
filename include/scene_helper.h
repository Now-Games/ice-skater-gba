#pragma once

#include "scene.h"
#include "start_menu_scene.h"
#include "credits_scene.h"
#include "game_constants.h"

namespace is
{
    static Scene* getScene(int sceneIndex, bn::point position)
    {
        switch (sceneIndex)
        {
            case START_MENU_SCENE:
                return new StartMenuScene();
            case CREDITS_SCENE:
                return new CreditsScene();
            case LEVEL_SELECT_SCENE:
                return new Scene();
            default:
                return new StartMenuScene();
        }
    }
}