
@{{BLOCK(ice_tile_bn_gfx)

@=======================================================================
@
@	ice_tile_bn_gfx, 16x16@8, 
@	+ palette 48 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 96 + 256 = 352
@
@	Time-stamp: 2024-03-16, 19:17:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ice_tile_bn_gfxTiles		@ 256 unsigned chars
	.hidden ice_tile_bn_gfxTiles
ice_tile_bn_gfxTiles:
	.word 0x20202020,0x21202020,0x21202020,0x20212020,0x20212020,0x20202120,0x20202120,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202120,0x20202020,0x20202021,0x21202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x21202020,0x20202020,0x20212020,0x20202020
	.word 0x20202120,0x20212020,0x20202021,0x20202120,0x20202020,0x20202021,0x20202020,0x20202020
	.word 0x20212020,0x20202020,0x20202120,0x20202020,0x20202020,0x21202020,0x20202020,0x20212020
	.word 0x21202020,0x20202020,0x20212020,0x20202020,0x20202120,0x21202020,0x20202020,0x20202020
	.word 0x20202120,0x20202120,0x20202021,0x20202021,0x21202020,0x21202020,0x20212020,0x20212020
	.word 0x20202120,0x20202020,0x20202021,0x20202021,0x21202020,0x20202020,0x20202020,0x20202020

	.section .rodata
	.align	2
	.global ice_tile_bn_gfxPal		@ 96 unsigned chars
	.hidden ice_tile_bn_gfxPal
ice_tile_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x000B,0x021F,0x001F,0x4F1F,0x7E80,0x7C80,0x427A,0x03E0
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x7F0F,0x7F94,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(ice_tile_bn_gfx)
