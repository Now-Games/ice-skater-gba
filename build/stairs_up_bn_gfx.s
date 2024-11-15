
@{{BLOCK(stairs_up_bn_gfx)

@=======================================================================
@
@	stairs_up_bn_gfx, 16x16@4, 
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
	.global stairs_up_bn_gfxTiles		@ 128 unsigned chars
	.hidden stairs_up_bn_gfxTiles
stairs_up_bn_gfxTiles:
	.word 0x00222220,0x00233320,0x00233320,0x22233320,0x33233320,0x31233320,0x31233320,0x31233320
	.word 0x00000000,0x00000000,0x00000000,0x00000022,0x00000023,0x00000023,0x00222223,0x00233323
	.word 0x31222220,0x31222220,0x31222220,0x22222220,0x22222220,0x22222220,0x22222220,0x22222220
	.word 0x00233123,0x00233123,0x00233123,0x00233122,0x00233122,0x00233122,0x00222222,0x00222222

	.section .rodata
	.align	2
	.global stairs_up_bn_gfxPal		@ 32 unsigned chars
	.hidden stairs_up_bn_gfxPal
stairs_up_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(stairs_up_bn_gfx)
