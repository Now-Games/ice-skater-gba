#ifndef BN_SPRITE_ITEMS_LEVEL_SELECT_ICON_H
#define BN_SPRITE_ITEMS_LEVEL_SELECT_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(level_select_icon_bn_gfx)

//======================================================================
//
//	level_select_icon_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-03-16, 19:17:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LEVEL_SELECT_ICON_BN_GFX_H
#define GRIT_LEVEL_SELECT_ICON_BN_GFX_H

#define level_select_icon_bn_gfxTilesLen 128
extern const bn::tile level_select_icon_bn_gfxTiles[4];

#define level_select_icon_bn_gfxPalLen 32
extern const bn::color level_select_icon_bn_gfxPal[16];

#endif // GRIT_LEVEL_SELECT_ICON_BN_GFX_H

//}}BLOCK(level_select_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item level_select_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(level_select_icon_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(level_select_icon_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

