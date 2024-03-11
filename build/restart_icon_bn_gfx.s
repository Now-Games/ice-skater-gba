
@{{BLOCK(restart_icon_bn_gfx)

@=======================================================================
@
@	restart_icon_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-03-06, 22:44:52
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global restart_icon_bn_gfxTiles		@ 128 unsigned chars
	.hidden restart_icon_bn_gfxTiles
restart_icon_bn_gfxTiles:
	.word 0x00000000,0x30000000,0x33000000,0x33300000,0x33000000,0x30000000,0x00000000,0x00000330
	.word 0x00000003,0x00000003,0x00000033,0x00003333,0x00033333,0x00330003,0x00330003,0x03300000
	.word 0x00000330,0x00000330,0x00000330,0x00003300,0x00003300,0x00333000,0x33330000,0x33000000
	.word 0x03300000,0x03300000,0x03300000,0x00330000,0x00330000,0x00033300,0x00003333,0x00000033

	.section .rodata
	.align	2
	.global restart_icon_bn_gfxPal		@ 32 unsigned chars
	.hidden restart_icon_bn_gfxPal
restart_icon_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(restart_icon_bn_gfx)
