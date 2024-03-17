#ifndef BN_SPRITE_ITEMS_PLAYER_SHEET_H
#define BN_SPRITE_ITEMS_PLAYER_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(player_sheet_bn_gfx)

//======================================================================
//
//	player_sheet_bn_gfx, 16x64@8, 
//	+ palette 64 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 128 + 1024 = 1152
//
//	Time-stamp: 2024-03-16, 19:17:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_SHEET_BN_GFX_H
#define GRIT_PLAYER_SHEET_BN_GFX_H

#define player_sheet_bn_gfxTilesLen 1024
extern const bn::tile player_sheet_bn_gfxTiles[32];

#define player_sheet_bn_gfxPalLen 128
extern const bn::color player_sheet_bn_gfxPal[64];

#endif // GRIT_PLAYER_SHEET_BN_GFX_H

//}}BLOCK(player_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item player_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(player_sheet_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(player_sheet_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

