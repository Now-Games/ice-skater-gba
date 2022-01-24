#ifndef BN_SPRITE_ITEMS_SNOW_TILE_H
#define BN_SPRITE_ITEMS_SNOW_TILE_H

#include "bn_sprite_item.h"

//{{BLOCK(snow_tile_bn_gfx)

//======================================================================
//
//	snow_tile_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2022-01-24, 00:07:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SNOW_TILE_BN_GFX_H
#define GRIT_SNOW_TILE_BN_GFX_H

#define snow_tile_bn_gfxTilesLen 128
extern const bn::tile snow_tile_bn_gfxTiles[4];

#define snow_tile_bn_gfxPalLen 32
extern const bn::color snow_tile_bn_gfxPal[16];

#endif // GRIT_SNOW_TILE_BN_GFX_H

//}}BLOCK(snow_tile_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item snow_tile(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(snow_tile_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(snow_tile_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

