
@{{BLOCK(stairs_down_bn_gfx)

@=======================================================================
@
@	stairs_down_bn_gfx, 16x16@4, 
@	+ palette 16 entries, not compressed
@	+ 4 tiles not compressed
@	Total size: 32 + 128 = 160
@
@	Time-stamp: 2024-03-23, 10:34:00
@	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global stairs_down_bn_gfxTiles		@ 128 unsigned chars
	.hidden stairs_down_bn_gfxTiles
stairs_down_bn_gfxTiles:
	.word 0x22222222,0xFFFFFFF2,0xFFFF3332,0xFFF23332,0x33323332,0x33423332,0x33423332,0x33423332
	.word 0x22222222,0x2FFFFFFF,0x2FFFFFFF,0x2FFFFFFF,0x2FFFFFFF,0x2FFFFFF2,0x2FFF4442,0x2FF24412
	.word 0x33423332,0x33423332,0x33423332,0x33423332,0x33423332,0x33423332,0x33423332,0x22222222
	.word 0x21124412,0x21124412,0x21124412,0x21124412,0x21124412,0x21124412,0x21124412,0x22222222

	.section .rodata
	.align	2
	.global stairs_down_bn_gfxPal		@ 32 unsigned chars
	.hidden stairs_down_bn_gfxPal
stairs_down_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(stairs_down_bn_gfx)
