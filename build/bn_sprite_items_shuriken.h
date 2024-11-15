#ifndef BN_SPRITE_ITEMS_SHURIKEN_H
#define BN_SPRITE_ITEMS_SHURIKEN_H

#include "bn_sprite_item.h"

//{{BLOCK(shuriken_bn_gfx)

//======================================================================
//
//	shuriken_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SHURIKEN_BN_GFX_H
#define GRIT_SHURIKEN_BN_GFX_H

#define shuriken_bn_gfxTilesLen 128
extern const bn::tile shuriken_bn_gfxTiles[4];

#define shuriken_bn_gfxPalLen 32
extern const bn::color shuriken_bn_gfxPal[16];

#endif // GRIT_SHURIKEN_BN_GFX_H

//}}BLOCK(shuriken_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item shuriken(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(shuriken_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(shuriken_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

