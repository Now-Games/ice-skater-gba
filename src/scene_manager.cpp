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

void SceneManager::loadTitleScene()
{
    currentGameState = GameState::GS_Title;

    //Load the title scene
    bn::music_items::music_box.play(0.5);
    titleScene = bn::unique_ptr(new TitleScene(saveData));
}

void SceneManager::loadCreditsScene()
{
    currentGameState = GameState::GS_Credits;

    creditsScene = bn::unique_ptr(new CreditsScene());
}

void SceneManager::loadLevelSelectScene()
{
    currentGameState = GameState::GS_LevelSelect;
    levelSelectScene = bn::unique_ptr(new LevelSelectScene(saveData));
}

void SceneManager::loadFloorTitleScene()
{
    currentGameState = GameState::GS_FloorTitle;

    SceneInfo sceneInfo = getSceneDetails(saveData.currentScene);
    floorTitleScene = bn::unique_ptr(new FloorTitleScene(sceneInfo.sceneName));
}

void SceneManager::loadScene()
{
    currentGameState = GameState::GS_Floor;
    
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

void SceneManager::loadPauseMenu()
{
    currentGameState = GameState::GS_Paused;
    pauseMenu = bn::unique_ptr(new PauseWindow());
}

void SceneManager::updateTitleScene()
{
    int scene = titleScene->update();
    if (scene >= 0) {
        bn::music_items::mystical_p.play(0.4);
        saveData.currentScene = scene;
        saveSaveData();
        titleScene.reset();
        loadFloorTitleScene();
    }
    else if (scene == -2)
    {
        titleScene.reset();
        loadCreditsScene();
    }
}

void SceneManager::updateCreditsScene()
{
    creditsScene->update();
    if (bn::keypad::b_pressed() || bn::keypad::a_pressed())
    {
        creditsScene.reset();
        loadTitleScene();
    }
}

void SceneManager::updateLevelSelectScene()
{
    int scene = levelSelectScene->update();
    if (scene >= 0)
    {
        saveData.currentScene = scene;
        levelSelectScene.reset();
        saveSaveData();
        loadFloorTitleScene();
    }
}

void SceneManager::updateFloorTitleScene()
{
    SceneUpdateResult result = floorTitleScene->update();
    if (result == S_Next)
    {
        floorTitleScene.reset();
        loadScene();
    }
}

void SceneManager::updateFloorScene()
{
    SceneUpdateResult result = SceneUpdateResult::S_None;
    
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
            if (currentSceneInfo.nextScene != -1) 
            {
                saveData.furthestScene = currentSceneInfo.nextScene;
                saveData.currentScene = currentSceneInfo.nextScene; //get the next scene
            }
        }
        else if (result == SceneUpdateResult::S_Previous) 
        {
            saveData.currentScene = currentSceneInfo.previousScene;
        }
        saveSaveData();

        BN_LOG("Scene Index: ", saveData.currentScene);
        currentScene.reset();
        currentEventScene.reset();
        currentMultiLevelScene.reset();
        
        if (saveData.currentScene > -1)
            loadFloorTitleScene();
        else
            loadTitleScene();
    }
}

void SceneManager::updatePauseMenu()
{
    PauseResult result = pauseMenu->update();
    if (result != P_None) {
        pauseMenu.reset();
        if (result != P_Continue)
        {
            currentScene.reset();
            currentEventScene.reset();
            currentMultiLevelScene.reset();
        }
    }
    
    switch (result)
    {
        case PauseResult::P_Continue:
            currentGameState = GameState::GS_Floor;
            break;
        case PauseResult::P_Restart:
            loadFloorTitleScene();
            break;
        case PauseResult::P_LevelSelect:
            loadLevelSelectScene();
            break;
        case PauseResult::P_Title:
            loadTitleScene();
            break;
        default:
            break;
    }
}

void SceneManager::update()
{
    switch (currentGameState)
    {
        case GameState::GS_Title:
            updateTitleScene();
            return;
        case GameState::GS_LevelSelect:
            updateLevelSelectScene();
            return;
        case GameState::GS_Credits:
            updateCreditsScene();
            return;
        case GameState::GS_FloorTitle:
            updateFloorTitleScene();
            return;
        case GameState::GS_Floor:
            updateFloorScene();
            if (bn::keypad::start_pressed())
            {
                loadPauseMenu();
            }
            return;
        case GameState::GS_Paused:
            updatePauseMenu();
            return;
        default:
            return;
    }
}
