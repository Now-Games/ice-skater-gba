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
#include "level_select_scene.h"
#include "credits_scene.h"

enum GameState
{
    GS_Title,
    GS_LevelSelect,
    GS_Credits,
    GS_FloorTitle,
    GS_Floor,
    GS_Paused
};

class SceneManager
{
    private:
        SceneType currentSceneDisplayed = SceneType::Basic;
        bn::unique_ptr<PauseWindow> pauseMenu;
        bn::unique_ptr<TitleScene> titleScene;
        bn::unique_ptr<LevelSelectScene> levelSelectScene;
        bn::unique_ptr<Scene> currentScene;
        bn::unique_ptr<EventScene> currentEventScene;
        bn::unique_ptr<MultiLevelScene> currentMultiLevelScene;
        bn::unique_ptr<FloorTitleScene> floorTitleScene;
        bn::unique_ptr<CreditsScene> creditsScene;
        GameState currentGameState = GameState::GS_Title;
        SaveData saveData;
        void readSaveData();
        void saveSaveData();
        void loadTitleScene();
        void loadCreditsScene();
        void loadLevelSelectScene();
        void loadFloorTitleScene();
        void loadScene();
        void loadPauseMenu();

        void updateTitleScene();
        void updateCreditsScene();
        void updateLevelSelectScene();
        void updateFloorTitleScene();
        void updateFloorScene();
        void updatePauseMenu();

    public:
        SceneManager();
        ~SceneManager();
        void update();
};

#endif // SCENE_MANAGER_H
