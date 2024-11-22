#ifndef BN_SPRITE_ITEMS_PLAYER_DEATH_SHEET_H
#define BN_SPRITE_ITEMS_PLAYER_DEATH_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(player_death_sheet_bn_gfx)

//======================================================================
//
//	player_death_sheet_bn_gfx, 16x192@8, 
//	+ palette 32 entries, not compressed
//	+ 48 tiles not compressed
//	Total size: 64 + 3072 = 3136
//
//	Time-stamp: 2024-11-21, 22:14:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAYER_DEATH_SHEET_BN_GFX_H
#define GRIT_PLAYER_DEATH_SHEET_BN_GFX_H

#define player_death_sheet_bn_gfxTilesLen 3072
extern const bn::tile player_death_sheet_bn_gfxTiles[96];

#define player_death_sheet_bn_gfxPalLen 64
extern const bn::color player_death_sheet_bn_gfxPal[32];

#endif // GRIT_PLAYER_DEATH_SHEET_BN_GFX_H

//}}BLOCK(player_death_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item player_death_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(player_death_sheet_bn_gfxTiles, 96), bpp_mode::BPP_8, compression_type::NONE, 12), 
            sprite_palette_item(span<const color>(player_death_sheet_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

