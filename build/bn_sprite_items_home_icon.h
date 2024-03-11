#ifndef BN_SPRITE_ITEMS_HOME_ICON_H
#define BN_SPRITE_ITEMS_HOME_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(home_icon_bn_gfx)

//======================================================================
//
//	home_icon_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-03-06, 22:44:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_HOME_ICON_BN_GFX_H
#define GRIT_HOME_ICON_BN_GFX_H

#define home_icon_bn_gfxTilesLen 128
extern const bn::tile home_icon_bn_gfxTiles[4];

#define home_icon_bn_gfxPalLen 32
extern const bn::color home_icon_bn_gfxPal[16];

#endif // GRIT_HOME_ICON_BN_GFX_H

//}}BLOCK(home_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item home_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(home_icon_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(home_icon_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

