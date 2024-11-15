#ifndef BN_REGULAR_BG_ITEMS_CREDITS_BG_H
#define BN_REGULAR_BG_ITEMS_CREDITS_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(credits_bg_bn_gfx)

//======================================================================
//
//	credits_bg_bn_gfx, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 94 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 6016 + 2048 = 8576
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CREDITS_BG_BN_GFX_H
#define GRIT_CREDITS_BG_BN_GFX_H

#define credits_bg_bn_gfxTilesLen 6016
extern const bn::tile credits_bg_bn_gfxTiles[188];

#define credits_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell credits_bg_bn_gfxMap[1024];

#define credits_bg_bn_gfxPalLen 512
extern const bn::color credits_bg_bn_gfxPal[256];

#endif // GRIT_CREDITS_BG_BN_GFX_H

//}}BLOCK(credits_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item credits_bg(
            regular_bg_tiles_item(span<const tile>(credits_bg_bn_gfxTiles, 188), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(credits_bg_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(credits_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

