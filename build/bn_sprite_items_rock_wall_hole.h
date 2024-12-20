#ifndef BN_SPRITE_ITEMS_ROCK_WALL_HOLE_H
#define BN_SPRITE_ITEMS_ROCK_WALL_HOLE_H

#include "bn_sprite_item.h"

//{{BLOCK(rock_wall_hole_bn_gfx)

//======================================================================
//
//	rock_wall_hole_bn_gfx, 16x64@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2024-11-13, 22:23:51
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ROCK_WALL_HOLE_BN_GFX_H
#define GRIT_ROCK_WALL_HOLE_BN_GFX_H

#define rock_wall_hole_bn_gfxTilesLen 512
extern const bn::tile rock_wall_hole_bn_gfxTiles[16];

#define rock_wall_hole_bn_gfxPalLen 32
extern const bn::color rock_wall_hole_bn_gfxPal[16];

#endif // GRIT_ROCK_WALL_HOLE_BN_GFX_H

//}}BLOCK(rock_wall_hole_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item rock_wall_hole(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(rock_wall_hole_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(rock_wall_hole_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

