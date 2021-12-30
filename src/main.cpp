#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_music.h"
#include "bn_music_items.h"
#include "bn_color.h"
#include "bn_log.h"
#include "is_scene_manager.h"

int main() {
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));

    is::scene_manager sm = is::scene_manager();

    BN_LOG("Enter Log");
    while (true) {
        sm.update();
        bn::core::update();
    }

    bn::music::stop();
}
