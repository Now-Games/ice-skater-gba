#ifndef BN_SPRITE_ITEMS_STAIRS_DOWN_H
#define BN_SPRITE_ITEMS_STAIRS_DOWN_H

#include "bn_sprite_item.h"

//{{BLOCK(stairs_down_bn_gfx)

//======================================================================
//
//	stairs_down_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-03-23, 10:34:00
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STAIRS_DOWN_BN_GFX_H
#define GRIT_STAIRS_DOWN_BN_GFX_H

#define stairs_down_bn_gfxTilesLen 128
extern const bn::tile stairs_down_bn_gfxTiles[4];

#define stairs_down_bn_gfxPalLen 32
extern const bn::color stairs_down_bn_gfxPal[16];

#endif // GRIT_STAIRS_DOWN_BN_GFX_H

//}}BLOCK(stairs_down_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item stairs_down(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(stairs_down_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(stairs_down_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

