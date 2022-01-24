#ifndef BN_SPRITE_ITEMS_ICE_TILE_H
#define BN_SPRITE_ITEMS_ICE_TILE_H

#include "bn_sprite_item.h"

//{{BLOCK(ice_tile_bn_gfx)

//======================================================================
//
//	ice_tile_bn_gfx, 16x16@8, 
//	+ palette 48 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 96 + 256 = 352
//
//	Time-stamp: 2022-01-24, 00:07:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ICE_TILE_BN_GFX_H
#define GRIT_ICE_TILE_BN_GFX_H

#define ice_tile_bn_gfxTilesLen 256
extern const bn::tile ice_tile_bn_gfxTiles[8];

#define ice_tile_bn_gfxPalLen 96
extern const bn::color ice_tile_bn_gfxPal[48];

#endif // GRIT_ICE_TILE_BN_GFX_H

//}}BLOCK(ice_tile_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item ice_tile(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(ice_tile_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(ice_tile_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

