#ifndef BN_REGULAR_BG_ITEMS_FINAL_SCENE_BG_H
#define BN_REGULAR_BG_ITEMS_FINAL_SCENE_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(final_scene_bg_bn_gfx)

//======================================================================
//
//	final_scene_bg_bn_gfx, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 24 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 1536 + 2048 = 3680
//
//	Time-stamp: 2024-11-22, 15:35:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FINAL_SCENE_BG_BN_GFX_H
#define GRIT_FINAL_SCENE_BG_BN_GFX_H

#define final_scene_bg_bn_gfxTilesLen 1536
extern const bn::tile final_scene_bg_bn_gfxTiles[48];

#define final_scene_bg_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell final_scene_bg_bn_gfxMap[1024];

#define final_scene_bg_bn_gfxPalLen 96
extern const bn::color final_scene_bg_bn_gfxPal[48];

#endif // GRIT_FINAL_SCENE_BG_BN_GFX_H

//}}BLOCK(final_scene_bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item final_scene_bg(
            regular_bg_tiles_item(span<const tile>(final_scene_bg_bn_gfxTiles, 48), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(final_scene_bg_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(final_scene_bg_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

