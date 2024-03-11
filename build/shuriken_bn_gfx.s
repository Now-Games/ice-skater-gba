
@{{BLOCK(shuriken_bn_gfx)

@=======================================================================
@
@	shuriken_bn_gfx, 16x16@4, 
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
	.global shuriken_bn_gfxTiles		@ 128 unsigned chars
	.hidden shuriken_bn_gfxTiles
shuriken_bn_gfxTiles:
	.word 0x00000000,0x40000000,0x40000000,0x11000000,0x22200000,0x11124000,0x11121440,0x11121111
	.word 0x00000004,0x00000011,0x00000021,0x00000211,0x00000222,0x00002111,0x00042111,0x04412111
	.word 0x11121210,0x11122000,0x11120000,0x22200000,0x11300000,0x11000000,0x11000000,0x10000000
	.word 0x21112111,0x02212111,0x00022111,0x00000222,0x00000021,0x00000002,0x00000002,0x00000000

	.section .rodata
	.align	2
	.global shuriken_bn_gfxPal		@ 32 unsigned chars
	.hidden shuriken_bn_gfxPal
shuriken_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(shuriken_bn_gfx)
