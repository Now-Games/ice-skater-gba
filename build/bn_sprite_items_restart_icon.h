#ifndef BN_SPRITE_ITEMS_RESTART_ICON_H
#define BN_SPRITE_ITEMS_RESTART_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(restart_icon_bn_gfx)

//======================================================================
//
//	restart_icon_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_RESTART_ICON_BN_GFX_H
#define GRIT_RESTART_ICON_BN_GFX_H

#define restart_icon_bn_gfxTilesLen 128
extern const bn::tile restart_icon_bn_gfxTiles[4];

#define restart_icon_bn_gfxPalLen 32
extern const bn::color restart_icon_bn_gfxPal[16];

#endif // GRIT_RESTART_ICON_BN_GFX_H

//}}BLOCK(restart_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item restart_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(restart_icon_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(restart_icon_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

