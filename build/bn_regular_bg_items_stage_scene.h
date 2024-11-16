#ifndef BN_REGULAR_BG_ITEMS_STAGE_SCENE_H
#define BN_REGULAR_BG_ITEMS_STAGE_SCENE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(stage_scene_bn_gfx)

//======================================================================
//
//	stage_scene_bn_gfx, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 9 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 576 + 2048 = 2720
//
//	Time-stamp: 2024-11-15, 16:51:19
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STAGE_SCENE_BN_GFX_H
#define GRIT_STAGE_SCENE_BN_GFX_H

#define stage_scene_bn_gfxTilesLen 576
extern const bn::tile stage_scene_bn_gfxTiles[18];

#define stage_scene_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell stage_scene_bn_gfxMap[1024];

#define stage_scene_bn_gfxPalLen 96
extern const bn::color stage_scene_bn_gfxPal[48];

#endif // GRIT_STAGE_SCENE_BN_GFX_H

//}}BLOCK(stage_scene_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item stage_scene(
            regular_bg_tiles_item(span<const tile>(stage_scene_bn_gfxTiles, 18), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(stage_scene_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(stage_scene_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

