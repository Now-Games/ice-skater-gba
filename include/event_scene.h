#ifndef EVENT_SCENE_H
#define EVENT_SCENE_H

#include "bn_sprite_text_generator.h"
#include "scene.h"

class EventScene
{
    protected:
        Scene scene;
        bn::sprite_text_generator textGenerator;
        bn::vector<bn::sprite_ptr, 32> textSprites;
        
    public:
        EventScene(SceneInfo sceneInfo, EventSceneInfo eventDetails);
        ~EventScene() = default;
        Scene* getScene();
        SceneUpdateResult update();
};

#endif // EVENT_SCENE_H
