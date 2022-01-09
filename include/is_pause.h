#ifndef IS_PAUSE_H
#define IS_PAUSE_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_optional.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_ptr.h"
#include "bn_rect_window.h"
#include "bn_window.h"

#include "bn_regular_bg_items_pause_scene.h"
#include "common_fixed_8x16_sprite_font.h"

namespace is
{

class pause
{
private:
    bn::optional<bn::regular_bg_ptr> _bg;
    bn::regular_bg_builder _display_builder;
    bool close_pause = false;

public:
    pause();
    ~pause();
    void update();
};

}

#endif // IS_PAUSE_H
