#ifndef BN_SPRITE_ITEMS_LEVEL_BUTTON_H
#define BN_SPRITE_ITEMS_LEVEL_BUTTON_H

#include "bn_sprite_item.h"

//{{BLOCK(level_button_bn_gfx)

//======================================================================
//
//	level_button_bn_gfx, 16x16@8, 
//	+ palette 64 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 128 + 256 = 384
//
//	Time-stamp: 2024-03-06, 22:44:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVEL_BUTTON_BN_GFX_H
#define GRIT_LEVEL_BUTTON_BN_GFX_H

#define level_button_bn_gfxTilesLen 256
extern const bn::tile level_button_bn_gfxTiles[8];

#define level_button_bn_gfxPalLen 128
extern const bn::color level_button_bn_gfxPal[64];

#endif // GRIT_LEVEL_BUTTON_BN_GFX_H

//}}BLOCK(level_button_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item level_button(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(level_button_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(level_button_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

