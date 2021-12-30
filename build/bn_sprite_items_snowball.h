#ifndef BN_SPRITE_ITEMS_SNOWBALL_H
#define BN_SPRITE_ITEMS_SNOWBALL_H

#include "bn_sprite_item.h"

//{{BLOCK(snowball_bn_gfx)

//======================================================================
//
//	snowball_bn_gfx, 16x16@8, 
//	+ palette 48 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 96 + 256 = 352
//
//	Time-stamp: 2021-12-26, 12:37:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SNOWBALL_BN_GFX_H
#define GRIT_SNOWBALL_BN_GFX_H

#define snowball_bn_gfxTilesLen 256
extern const bn::tile snowball_bn_gfxTiles[bn::max(64 / 8, 1)];

#define snowball_bn_gfxPalLen 96
extern const bn::color snowball_bn_gfxPal[48];

#endif // GRIT_SNOWBALL_BN_GFX_H

//}}BLOCK(snowball_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item snowball(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(snowball_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(snowball_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

