
@{{BLOCK(stairs_sheet_bn_gfx)

@=======================================================================
@
@	stairs_sheet_bn_gfx, 16x64@4, 
@	+ palette 16 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 32 + 512 = 544
@
@	Time-stamp: 2024-11-20, 21:29:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global stairs_sheet_bn_gfxTiles		@ 512 unsigned chars
	.hidden stairs_sheet_bn_gfxTiles
stairs_sheet_bn_gfxTiles:
	.word 0x22222222,0xFFFFFFF2,0xFFFF3332,0xFFF23332,0x33323332,0x33423332,0x33423332,0x33423332
	.word 0x22222222,0x2FFFFFFF,0x2FFFFFFF,0x2FFFFFFF,0x2FFFFFFF,0x2FFFFFF2,0x2FFF4442,0x2FF24412
	.word 0x33423332,0x33423332,0x33423332,0x33423332,0x33423332,0x33423332,0x33423332,0x22222222
	.word 0x21124412,0x21124412,0x21124412,0x21124412,0x21124412,0x21124412,0x21124412,0x22222222
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000

	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00222220,0x00233320,0x00233320,0x22233320,0x33233320,0x31233320,0x31233320,0x31233320
	.word 0x00000000,0x00000000,0x00000000,0x00000022,0x00000023,0x00000023,0x00222223,0x00233323
	.word 0x31222220,0x31222220,0x31222220,0x22222220,0x22222220,0x22222220,0x22222220,0x22222220
	.word 0x00233123,0x00233123,0x00233123,0x00233122,0x00233122,0x00233122,0x00222222,0x00222222

	.section .rodata
	.align	2
	.global stairs_sheet_bn_gfxPal		@ 32 unsigned chars
	.hidden stairs_sheet_bn_gfxPal
stairs_sheet_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(stairs_sheet_bn_gfx)
