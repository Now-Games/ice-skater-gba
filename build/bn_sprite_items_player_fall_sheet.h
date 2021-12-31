#ifndef BN_SPRITE_ITEMS_PLAYER_FALL_SHEET_H
#define BN_SPRITE_ITEMS_PLAYER_FALL_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(player_fall_sheet_bn_gfx)

//======================================================================
//
//	player_fall_sheet_bn_gfx, 16x288@8, 
//	+ palette 32 entries, not compressed
//	+ 72 tiles not compressed
//	Total size: 64 + 4608 = 4672
//
//	Time-stamp: 2021-12-31, 00:43:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_FALL_SHEET_BN_GFX_H
#define GRIT_PLAYER_FALL_SHEET_BN_GFX_H

#define player_fall_sheet_bn_gfxTilesLen 4608
extern const bn::tile player_fall_sheet_bn_gfxTiles[bn::max(1152 / 8, 1)];

#define player_fall_sheet_bn_gfxPalLen 64
extern const bn::color player_fall_sheet_bn_gfxPal[32];

#endif // GRIT_PLAYER_FALL_SHEET_BN_GFX_H

//}}BLOCK(player_fall_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item player_fall_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(player_fall_sheet_bn_gfxTiles, 144), bpp_mode::BPP_8, compression_type::NONE, 18), 
            sprite_palette_item(span<const color>(player_fall_sheet_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

