#ifndef BN_SPRITE_ITEMS_MENU_POINTER_H
#define BN_SPRITE_ITEMS_MENU_POINTER_H

#include "bn_sprite_item.h"

//{{BLOCK(menu_pointer_bn_gfx)

//======================================================================
//
//	menu_pointer_bn_gfx, 16x16@8, 
//	+ palette 64 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 128 + 256 = 384
//
//	Time-stamp: 2021-12-29, 23:15:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENU_POINTER_BN_GFX_H
#define GRIT_MENU_POINTER_BN_GFX_H

#define menu_pointer_bn_gfxTilesLen 256
extern const bn::tile menu_pointer_bn_gfxTiles[bn::max(64 / 8, 1)];

#define menu_pointer_bn_gfxPalLen 128
extern const bn::color menu_pointer_bn_gfxPal[64];

#endif // GRIT_MENU_POINTER_BN_GFX_H

//}}BLOCK(menu_pointer_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item menu_pointer(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(menu_pointer_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(menu_pointer_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

