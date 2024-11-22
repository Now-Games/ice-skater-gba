#ifndef BN_SPRITE_ITEMS_STAIRS_SHEET_H
#define BN_SPRITE_ITEMS_STAIRS_SHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(stairs_sheet_bn_gfx)

//======================================================================
//
//	stairs_sheet_bn_gfx, 16x64@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2024-11-20, 21:29:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STAIRS_SHEET_BN_GFX_H
#define GRIT_STAIRS_SHEET_BN_GFX_H

#define stairs_sheet_bn_gfxTilesLen 512
extern const bn::tile stairs_sheet_bn_gfxTiles[16];

#define stairs_sheet_bn_gfxPalLen 32
extern const bn::color stairs_sheet_bn_gfxPal[16];

#endif // GRIT_STAIRS_SHEET_BN_GFX_H

//}}BLOCK(stairs_sheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item stairs_sheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(stairs_sheet_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(stairs_sheet_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

