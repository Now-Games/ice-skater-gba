#include "bn_core.h"
#include "bn_log.h"
#include "bn_music.h"
#include "bn_bg_palettes.h"
#include "scene_manager.h"

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
    
    SceneManager sm = SceneManager();

    while(true)
    {
        sm.update();
        bn::core::update();
    }

    bn::music::stop();
}
