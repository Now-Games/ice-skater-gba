#include "event_scene.h"
#include "bn_display.h"
#include "common_variable_8x16_sprite_font.h"

EventScene::EventScene(SceneInfo sceneInfo, EventSceneInfo eventDetails):
    Scene(sceneInfo), 
    textGenerator(bn::sprite_text_generator(common::variable_8x16_sprite_font))
{
    BN_LOG("Loading Event Scene");
    //leave space for the event text
    setMaxBounds(bn::fixed_point(getMaxBounds().x(), getMaxBounds().y() - 32));
    
    //display text
    textGenerator.set_center_alignment();
    textGenerator.generate(0, getMaxBounds().y() + 26, eventDetails.eventMessage, textSprites);
    BN_LOG(eventDetails.eventMessage);
}

SceneUpdateResult EventScene::update()
{
    return Scene::update();
}