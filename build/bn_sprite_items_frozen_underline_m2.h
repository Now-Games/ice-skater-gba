#ifndef BN_SPRITE_ITEMS_FROZEN_UNDERLINE_M2_H
#define BN_SPRITE_ITEMS_FROZEN_UNDERLINE_M2_H

#include "bn_sprite_item.h"

//{{BLOCK(frozen_underline_m2_bn_gfx)

//======================================================================
//
//	frozen_underline_m2_bn_gfx, 32x32@8, 
//	+ palette 64 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 128 + 1024 = 1152
//
//	Time-stamp: 2024-03-06, 22:44:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FROZEN_UNDERLINE_M2_BN_GFX_H
#define GRIT_FROZEN_UNDERLINE_M2_BN_GFX_H

#define frozen_underline_m2_bn_gfxTilesLen 1024
extern const bn::tile frozen_underline_m2_bn_gfxTiles[32];

#define frozen_underline_m2_bn_gfxPalLen 128
extern const bn::color frozen_underline_m2_bn_gfxPal[64];

#endif // GRIT_FROZEN_UNDERLINE_M2_BN_GFX_H

//}}BLOCK(frozen_underline_m2_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item frozen_underline_m2(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(frozen_underline_m2_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(frozen_underline_m2_bn_gfxPal, 64), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

