#ifndef BN_SPRITE_ITEMS_PLAY_ICON_H
#define BN_SPRITE_ITEMS_PLAY_ICON_H

#include "bn_sprite_item.h"

//{{BLOCK(play_icon_bn_gfx)

//======================================================================
//
//	play_icon_bn_gfx, 16x16@4, 
//	+ palette 16 entries, not compressed
//	+ 4 tiles not compressed
//	Total size: 32 + 128 = 160
//
//	Time-stamp: 2024-03-02, 18:19:24
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PLAY_ICON_BN_GFX_H
#define GRIT_PLAY_ICON_BN_GFX_H

#define play_icon_bn_gfxTilesLen 128
extern const bn::tile play_icon_bn_gfxTiles[4];

#define play_icon_bn_gfxPalLen 32
extern const bn::color play_icon_bn_gfxPal[16];

#endif // GRIT_PLAY_ICON_BN_GFX_H

//}}BLOCK(play_icon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item play_icon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(play_icon_bn_gfxTiles, 4), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(play_icon_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

