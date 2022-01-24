
@{{BLOCK(rock_wall_bn_gfx)

@=======================================================================
@
@	rock_wall_bn_gfx, 16x64@4, 
@	+ palette 16 entries, not compressed
@	+ 16 tiles not compressed
@	Total size: 32 + 512 = 544
@
@	Time-stamp: 2022-01-24, 00:07:29
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global rock_wall_bn_gfxTiles		@ 512 unsigned chars
	.hidden rock_wall_bn_gfxTiles
rock_wall_bn_gfxTiles:
	.word 0x11211111,0x11211111,0x12122112,0x12111221,0x21111111,0x21111112,0x12211121,0x11122211
	.word 0x11112111,0x11112111,0x11111211,0x21111121,0x12211122,0x11122211,0x11121111,0x11112111
	.word 0x11112111,0x11221111,0x22112111,0x21111222,0x21111112,0x12211121,0x11122211,0x22222222
	.word 0x11112111,0x11111211,0x21112122,0x12221111,0x11211111,0x11121112,0x21112221,0x22222222
	.word 0x11112111,0x11121111,0x11121111,0x12211111,0x21211122,0x11211211,0x11122111,0x11121111
	.word 0x22111211,0x21112111,0x21122111,0x21212111,0x22111212,0x22111121,0x22111211,0x21211211
	.word 0x11221111,0x12112211,0x12111122,0x21111211,0x21111211,0x21112111,0x12112111,0x11211211
	.word 0x21122211,0x21211211,0x21211121,0x22111121,0x22111212,0x22112111,0x21212111,0x21122111

	.word 0x11122112,0x11121212,0x11121122,0x21211122,0x12111122,0x12111212,0x11211212,0x11222112
	.word 0x11211211,0x11121121,0x11121112,0x11211112,0x11211112,0x22111121,0x11221121,0x11112211
	.word 0x11211212,0x11211122,0x12111122,0x21211122,0x11121212,0x11122112,0x11121112,0x11211122
	.word 0x11112111,0x11122111,0x11211211,0x22111212,0x11111221,0x11112111,0x11112111,0x11121111
	.word 0x22222222,0x11122211,0x12211121,0x21111112,0x21111222,0x22112111,0x11221111,0x11112111
	.word 0x22222222,0x21112221,0x11121112,0x11211111,0x12221111,0x21112122,0x11111211,0x11112111
	.word 0x11122211,0x12211121,0x21111112,0x21111111,0x12111221,0x12122112,0x11211111,0x11211111
	.word 0x11112111,0x11121111,0x11122211,0x12211122,0x21111121,0x11111211,0x11112111,0x11112111

	.section .rodata
	.align	2
	.global rock_wall_bn_gfxPal		@ 32 unsigned chars
	.hidden rock_wall_bn_gfxPal
rock_wall_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(rock_wall_bn_gfx)
