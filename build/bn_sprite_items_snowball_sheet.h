#ifndef BN_SPRITE_ITEMS_SNOWBALL_SHEET_H
#define BN_SPRITE_ITEMS_SNOWBALL_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(snowball_sheet_bn_gfx)

//======================================================================
//
//	snowball_sheet_bn_gfx, 16x96@8, 
//	+ palette 48 entries, not compressed
//	+ 24 tiles not compressed
//	Total size: 96 + 1536 = 1632
//
//	Time-stamp: 2024-03-16, 19:17:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SNOWBALL_SHEET_BN_GFX_H
#define GRIT_SNOWBALL_SHEET_BN_GFX_H

#define snowball_sheet_bn_gfxTilesLen 1536
extern const bn::tile snowball_sheet_bn_gfxTiles[48];

#define snowball_sheet_bn_gfxPalLen 96
extern const bn::color snowball_sheet_bn_gfxPal[48];

#endif // GRIT_SNOWBALL_SHEET_BN_GFX_H

//}}BLOCK(snowball_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item snowball_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(snowball_sheet_bn_gfxTiles, 48), bpp_mode::BPP_8, compression_type::NONE, 6), 
            sprite_palette_item(span<const color>(snowball_sheet_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

