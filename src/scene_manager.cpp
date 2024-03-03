#include "scene_manager.h"
#include "title_scene.h"

#include "bn_log.h"
#include "bn_sram.h"
#include "bn_music_items.h"

SceneManager::SceneManager() : saveData(SaveData())
{
    BN_LOG("Scene Manager created");
    BN_LOG("Scene Info Size: ", sizeof(SceneInfo));
    BN_LOG("Scene Info Size: ", sizeof(ObstacleInfo));

    readSaveData();
    loadTitleScene();
}

void SceneManager::readSaveData()
{
    bn::sram::read(saveData);

    bn::array<char, 32> expected_format_tag;
    bn::istring_base expected_format_tag_istring(expected_format_tag._data);
    bn::ostringstream expected_format_tag_stream(expected_format_tag_istring);

    BN_LOG("Saved Scene: ", saveData.currentScene);

    if (saveData.format != expected_format_tag) {
        BN_LOG("RESETTING SAVE DATA");
        saveData = {
            expected_format_tag,
            0,
            0
        };
    }
}

void SceneManager::saveSaveData()
{
    bn::sram::write(saveData);
}

bool SceneManager::isPaused()
{
    return paused;
}

void SceneManager::loadTitleScene()
{
    currentScene.reset();
    currentEventScene.reset();
    currentMultiLevelScene.reset();
    pauseMenu.reset();

    //Load the title scene
    bn::music_items::music_box.play(0.5);
    titleScene = bn::unique_ptr(new TitleScene(saveData));
}

void SceneManager::loadFloorTitleScene()
{
    pauseMenu.reset();
    currentScene.reset();
    currentEventScene.reset();
    currentMultiLevelScene.reset();
    
    SceneInfo sceneInfo = getSceneDetails(saveData.currentScene);
    floorTitleScene = bn::unique_ptr(new FloorTitleScene(sceneInfo.sceneName));
    isShowingFloorTitle = true;
}

void SceneManager::loadScene()
{
    //clear the title scene
    floorTitleScene.reset();
    
    SceneInfo sceneInfo = getSceneDetails(saveData.currentScene);
    currentSceneDisplayed = sceneInfo.sceneType;
    
    //load the scene depending on which type of scene it is
    if (currentSceneDisplayed == SceneType::Event) 
    { 
        EventScene *eventScene = new EventScene(sceneInfo, getEventDetails(saveData.currentScene));
        currentEventScene = bn::unique_ptr(eventScene);
    }
    else if (currentSceneDisplayed == SceneType::Basic)
    {
        Scene *scene = new Scene(sceneInfo);
        currentScene = bn::unique_ptr(scene);
    }
    else if (currentSceneDisplayed == SceneType::MultiLevel)
    {
        MultiLevelScene *multiScene = new MultiLevelScene(getMultiLevelDetails(saveData.currentScene));
        currentMultiLevelScene = bn::unique_ptr(multiScene);
    }
}

void SceneManager::togglePause()
{
    paused = !paused;
    if (paused)
        pauseMenu = bn::unique_ptr(new PauseWindow());
    else
        pauseMenu.reset();
}

void SceneManager::update()
{
    if (isShowingTitle)
    {
        int scene = titleScene->update();
        if (scene >= 0) {
            bn::music_items::mystical_p.play(0.4);
            saveData.currentScene = scene;
            isShowingTitle = false;
            titleScene.reset();
            loadFloorTitleScene();
        }
        return;
    }
    
    SceneUpdateResult result = SceneUpdateResult::S_None;

    //if showing floor title screen, wait for A press
    if (isShowingFloorTitle)
    {
        result = floorTitleScene->update();
        if (result == S_Next)
        {
            isShowingFloorTitle = false;
            floorTitleScene.reset();
            loadScene();
        }

        return;
    }
    
    
    if (bn::keypad::start_pressed())
    {
        togglePause();
    }

    //if the game is paused, only update the pause menu
    if (paused)
    {
        PauseResult pauseResult = pauseMenu->update();
        if (pauseResult != PauseResult::P_None)
            togglePause();

        switch (pauseResult)
        {
            case PauseResult::P_Restart:
                result = SceneUpdateResult::S_Restart;
                loadFloorTitleScene();
                return;
            case PauseResult::P_Title:
                isShowingTitle = true;
                loadTitleScene();
                return;
            default:
                return;
        }
    }
        
    //depending on which scene is displayed, run that scene
    switch (currentSceneDisplayed)
    {
        case SceneType::Basic:
            result = currentScene->update();
            break;
        case SceneType::Event:
            result = currentEventScene->update();
            break;
        case SceneType::MultiLevel:
            result = currentMultiLevelScene->update();
            break;
        default:
            break;
    }
    
    if (result != SceneUpdateResult::S_None)
    {
        SceneInfo currentSceneInfo = getSceneDetails(saveData.currentScene);
        if (result == SceneUpdateResult::S_Next) 
        {
            saveData.furthestScene = saveData.currentScene;
            saveData.currentScene = currentSceneInfo.nextScene; //get the next scene
        }
        else if (result == SceneUpdateResult::S_Previous) 
        {
            saveData.currentScene = currentSceneInfo.previousScene;
        }
        saveSaveData();

        BN_LOG("Scene Index: ", saveData.currentScene);
        if (saveData.currentScene > -1)
            loadFloorTitleScene();
        else
            loadTitleScene();
    }
}
