
@{{BLOCK(play_icon_bn_gfx)

@=======================================================================
@
@	play_icon_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-03-16, 19:17:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global play_icon_bn_gfxTiles		@ 128 unsigned chars
	.hidden play_icon_bn_gfxTiles
play_icon_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00330000,0x33330000,0x33330000,0x33330000,0x33330000,0x33330000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000033,0x00000333,0x00003333,0x00033333
	.word 0x33330000,0x33330000,0x33330000,0x33330000,0x33330000,0x00330000,0x00000000,0x00000000
	.word 0x00033333,0x00003333,0x00000333,0x00000033,0x00000000,0x00000000,0x00000000,0x00000000

	.section .rodata
	.align	2
	.global play_icon_bn_gfxPal		@ 32 unsigned chars
	.hidden play_icon_bn_gfxPal
play_icon_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(play_icon_bn_gfx)
