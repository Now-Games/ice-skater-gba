
@{{BLOCK(home_icon_bn_gfx)

@=======================================================================
@
@	home_icon_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-11-13, 22:23:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global home_icon_bn_gfxTiles		@ 128 unsigned chars
	.hidden home_icon_bn_gfxTiles
home_icon_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x30000000,0x33000000,0x33300000,0x33330000,0x33333000,0x33333300
	.word 0x00000000,0x00000000,0x00000003,0x00000033,0x00000333,0x00003333,0x00033333,0x00333333
	.word 0x33333000,0x33333000,0x33333000,0x03333000,0x03333000,0x03333000,0x00000000,0x00000000
	.word 0x00033333,0x00033333,0x00033333,0x00033330,0x00033330,0x00033330,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global home_icon_bn_gfxPal		@ 32 unsigned chars
	.hidden home_icon_bn_gfxPal
home_icon_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(home_icon_bn_gfx)
