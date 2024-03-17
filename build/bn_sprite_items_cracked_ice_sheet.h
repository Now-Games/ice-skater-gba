#ifndef BN_SPRITE_ITEMS_CRACKED_ICE_SHEET_H
#define BN_SPRITE_ITEMS_CRACKED_ICE_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(cracked_ice_sheet_bn_gfx)

//======================================================================
//
//	cracked_ice_sheet_bn_gfx, 16x80@8, 
//	+ palette 64 entries, not compressed
//	+ 20 tiles not compressed
//	Total size: 128 + 1280 = 1408
//
//	Time-stamp: 2024-03-16, 19:17:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CRACKED_ICE_SHEET_BN_GFX_H
#define GRIT_CRACKED_ICE_SHEET_BN_GFX_H

#define cracked_ice_sheet_bn_gfxTilesLen 1280
extern const bn::tile cracked_ice_sheet_bn_gfxTiles[40];

#define cracked_ice_sheet_bn_gfxPalLen 128
extern const bn::color cracked_ice_sheet_bn_gfxPal[64];

#endif // GRIT_CRACKED_ICE_SHEET_BN_GFX_H

//}}BLOCK(cracked_ice_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cracked_ice_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(cracked_ice_sheet_bn_gfxTiles, 40), bpp_mode::BPP_8, compression_type::NONE, 5), 
            sprite_palette_item(span<const color>(cracked_ice_sheet_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

