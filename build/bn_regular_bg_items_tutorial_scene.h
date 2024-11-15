#ifndef BN_REGULAR_BG_ITEMS_TUTORIAL_SCENE_H
#define BN_REGULAR_BG_ITEMS_TUTORIAL_SCENE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(tutorial_scene_bn_gfx)

//======================================================================
//
//	tutorial_scene_bn_gfx, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 10 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 640 + 2048 = 2784
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TUTORIAL_SCENE_BN_GFX_H
#define GRIT_TUTORIAL_SCENE_BN_GFX_H

#define tutorial_scene_bn_gfxTilesLen 640
extern const bn::tile tutorial_scene_bn_gfxTiles[20];

#define tutorial_scene_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell tutorial_scene_bn_gfxMap[1024];

#define tutorial_scene_bn_gfxPalLen 96
extern const bn::color tutorial_scene_bn_gfxPal[48];

#endif // GRIT_TUTORIAL_SCENE_BN_GFX_H

//}}BLOCK(tutorial_scene_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item tutorial_scene(
            regular_bg_tiles_item(span<const tile>(tutorial_scene_bn_gfxTiles, 20), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(tutorial_scene_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(tutorial_scene_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

