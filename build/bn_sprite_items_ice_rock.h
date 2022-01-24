#ifndef BN_SPRITE_ITEMS_ICE_ROCK_H
#define BN_SPRITE_ITEMS_ICE_ROCK_H

#include "bn_sprite_item.h"

//{{BLOCK(ice_rock_bn_gfx)

//======================================================================
//
//	ice_rock_bn_gfx, 16x16@8, 
//	+ palette 64 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 128 + 256 = 384
//
//	Time-stamp: 2022-01-24, 00:07:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ICE_ROCK_BN_GFX_H
#define GRIT_ICE_ROCK_BN_GFX_H

#define ice_rock_bn_gfxTilesLen 256
extern const bn::tile ice_rock_bn_gfxTiles[8];

#define ice_rock_bn_gfxPalLen 128
extern const bn::color ice_rock_bn_gfxPal[64];

#endif // GRIT_ICE_ROCK_BN_GFX_H

//}}BLOCK(ice_rock_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item ice_rock(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(ice_rock_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(ice_rock_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

