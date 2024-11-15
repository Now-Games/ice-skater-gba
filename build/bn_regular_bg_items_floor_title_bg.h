#ifndef BN_REGULAR_BG_ITEMS_FLOOR_TITLE_BG_H
#define BN_REGULAR_BG_ITEMS_FLOOR_TITLE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(floor_title_bg_bn_gfx)

//======================================================================
//
//	floor_title_bg_bn_gfx, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 9 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 576 + 2048 = 2720
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FLOOR_TITLE_BG_BN_GFX_H
#define GRIT_FLOOR_TITLE_BG_BN_GFX_H

#define floor_title_bg_bn_gfxTilesLen 576
extern const bn::tile floor_title_bg_bn_gfxTiles[18];

#define floor_title_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell floor_title_bg_bn_gfxMap[1024];

#define floor_title_bg_bn_gfxPalLen 96
extern const bn::color floor_title_bg_bn_gfxPal[48];

#endif // GRIT_FLOOR_TITLE_BG_BN_GFX_H

//}}BLOCK(floor_title_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item floor_title_bg(
            regular_bg_tiles_item(span<const tile>(floor_title_bg_bn_gfxTiles, 18), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(floor_title_bg_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(floor_title_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

