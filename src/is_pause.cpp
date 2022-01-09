#include "is_pause.h"

namespace is
{

pause::pause() :
    _display_builder(bn::regular_bg_items::pause_scene)
{
    _display_builder.set_priority(1);
    _bg = _display_builder.release_build();
}

pause::~pause()
{
    //
}

void pause::update()
{
    while (true) {
        if ((bn::keypad::start_pressed() || bn::keypad::b_pressed()) && close_pause) {
            BN_LOG("Pause display closed");
            return;
        }
        else if (!close_pause) {
            close_pause = !close_pause;
        }

        bn::core::update();
    }
}

}
