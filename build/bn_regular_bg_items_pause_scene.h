#ifndef BN_REGULAR_BG_ITEMS_PAUSE_SCENE_H
#define BN_REGULAR_BG_ITEMS_PAUSE_SCENE_H

#include "bn_regular_bg_item.h"

//{{BLOCK(pause_scene_bn_gfx)

//======================================================================
//
//	pause_scene_bn_gfx, 256x256@8, 
//	+ palette 256 entries, not compressed
//	+ 99 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 6336 + 2048 = 8896
//
//	Time-stamp: 2024-11-17, 23:25:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSE_SCENE_BN_GFX_H
#define GRIT_PAUSE_SCENE_BN_GFX_H

#define pause_scene_bn_gfxTilesLen 6336
extern const bn::tile pause_scene_bn_gfxTiles[198];

#define pause_scene_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell pause_scene_bn_gfxMap[1024];

#define pause_scene_bn_gfxPalLen 512
extern const bn::color pause_scene_bn_gfxPal[256];

#endif // GRIT_PAUSE_SCENE_BN_GFX_H

//}}BLOCK(pause_scene_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item pause_scene(
            regular_bg_tiles_item(span<const tile>(pause_scene_bn_gfxTiles, 198), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(pause_scene_bn_gfxPal, 256), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(pause_scene_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

