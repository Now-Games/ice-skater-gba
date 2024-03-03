#include "event_scene.h"
#include "bn_display.h"
#include "common_variable_8x16_sprite_font.h"

EventScene::EventScene(SceneInfo sceneInfo, EventSceneInfo eventDetails):
    scene(sceneInfo), textGenerator(bn::sprite_text_generator(common::variable_8x16_sprite_font))
{
    BN_LOG("Loading Event Scene");
    //leave space for the event text
    scene.setMaxBounds(bn::fixed_point(scene.getMaxBounds().x(), 
                                       scene.getMaxBounds().y() - 32));
    
    //display text
    textGenerator.set_center_alignment();
    textGenerator.generate(0, scene.getMaxBounds().y() + 26, eventDetails.eventMessage, textSprites);
    BN_LOG(eventDetails.eventMessage);
}

Scene* EventScene::getScene()
{
    return &scene;
}

SceneUpdateResult EventScene::update()
{
    return scene.update();
}