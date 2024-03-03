#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "bn_unique_ptr.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "game_state.h"
#include "event_scene.h"
#include "multi_level_scene.h"
#include "game_scenes.h"
#include "floor_title_scene.h"
#include "title_scene.h"
#include "pause_window.h"

class SceneManager
{
    private:
        bool paused = false;
        SceneType currentSceneDisplayed = SceneType::Basic;
        bn::unique_ptr<PauseWindow> pauseMenu;
       bn::unique_ptr<TitleScene> titleScene;
//        bn::unique_ptr<LevelSelectScene> levelSelectScene;
        bn::unique_ptr<Scene> currentScene;
        bn::unique_ptr<EventScene> currentEventScene;
        bn::unique_ptr<MultiLevelScene> currentMultiLevelScene;
        bn::unique_ptr<FloorTitleScene> floorTitleScene;
        bool isShowingFloorTitle = false;
        bool isShowingTitle = true;
        SaveData saveData;
        void readSaveData();
        void saveSaveData();
        void loadTitleScene();
        void loadFloorTitleScene();
        void loadScene();
        void togglePause();

    public:
        SceneManager();
        ~SceneManager();
        void update();
        bool isPaused();
};

#endif // SCENE_MANAGER_H
