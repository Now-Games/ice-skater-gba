#ifndef BN_REGULAR_BG_ITEMS_TITLE_SCENE_H
#define BN_REGULAR_BG_ITEMS_TITLE_SCENE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(title_scene_bn_gfx)

//======================================================================
//
//	title_scene_bn_gfx, 256x256@8, 
//	+ palette 64 entries, not compressed
//	+ 158 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 128 + 10112 + 2048 = 12288
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TITLE_SCENE_BN_GFX_H
#define GRIT_TITLE_SCENE_BN_GFX_H

#define title_scene_bn_gfxTilesLen 10112
extern const bn::tile title_scene_bn_gfxTiles[316];

#define title_scene_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell title_scene_bn_gfxMap[1024];

#define title_scene_bn_gfxPalLen 128
extern const bn::color title_scene_bn_gfxPal[64];

#endif // GRIT_TITLE_SCENE_BN_GFX_H

//}}BLOCK(title_scene_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item title_scene(
            regular_bg_tiles_item(span<const tile>(title_scene_bn_gfxTiles, 316), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(title_scene_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(title_scene_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

