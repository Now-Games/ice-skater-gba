#ifndef BN_SPRITE_ITEMS_CRACKED_WALL_SHEET_H
#define BN_SPRITE_ITEMS_CRACKED_WALL_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(cracked_wall_sheet_bn_gfx)

//======================================================================
//
//	cracked_wall_sheet_bn_gfx, 16x320@4, 
//	+ palette 16 entries, not compressed
//	+ 80 tiles not compressed
//	Total size: 32 + 2560 = 2592
//
//	Time-stamp: 2024-03-16, 19:17:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CRACKED_WALL_SHEET_BN_GFX_H
#define GRIT_CRACKED_WALL_SHEET_BN_GFX_H

#define cracked_wall_sheet_bn_gfxTilesLen 2560
extern const bn::tile cracked_wall_sheet_bn_gfxTiles[80];

#define cracked_wall_sheet_bn_gfxPalLen 32
extern const bn::color cracked_wall_sheet_bn_gfxPal[16];

#endif // GRIT_CRACKED_WALL_SHEET_BN_GFX_H

//}}BLOCK(cracked_wall_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cracked_wall_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(cracked_wall_sheet_bn_gfxTiles, 80), bpp_mode::BPP_4, compression_type::NONE, 20), 
            sprite_palette_item(span<const color>(cracked_wall_sheet_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

