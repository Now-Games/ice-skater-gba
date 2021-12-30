
@{{BLOCK(stage_scene_bn_gfx)

@=======================================================================
@
@	stage_scene_bn_gfx, 256x256@8, 
@	+ palette 48 entries, not compressed
@	+ 9 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x32 
@	Total size: 96 + 576 + 2048 = 2720
@
@	Time-stamp: 2021-12-29, 19:30:31
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global stage_scene_bn_gfxTiles		@ 576 unsigned chars
	.hidden stage_scene_bn_gfxTiles
stage_scene_bn_gfxTiles:
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000
	.word 0x20202020,0x21202020,0x21202020,0x20212020,0x20212020,0x20202120,0x20202120,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202120,0x20202020,0x20202021,0x21202020,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x21202020,0x20202020,0x20212020,0x20202020
	.word 0x20202120,0x20212020,0x20202021,0x20202120,0x20202020,0x20202021,0x20202020,0x20202020
	.word 0x20202020,0x20212020,0x20212020,0x20202120,0x20202120,0x20202021,0x20202021,0x20202020
	.word 0x20202020,0x20202020,0x20202020,0x21202021,0x21202020,0x20202020,0x20212020,0x20202020

	.word 0x20202020,0x20202020,0x20202020,0x20202020,0x20212020,0x20202020,0x20202120,0x20202020
	.word 0x20202021,0x20202120,0x20202020,0x20202021,0x21202020,0x20202020,0x20202020,0x20202020
	.word 0x20212020,0x20202020,0x20202120,0x20202020,0x20202020,0x21202020,0x20202020,0x20212020
	.word 0x21202020,0x20202020,0x20212020,0x20202020,0x20202120,0x21202020,0x20202020,0x20202020
	.word 0x20202120,0x20202120,0x20202021,0x20202021,0x21202020,0x21202020,0x20212020,0x20212020
	.word 0x20202120,0x20202020,0x20202021,0x20202021,0x21202020,0x20202020,0x20202020,0x20202020
	.word 0x20202120,0x20202020,0x20202021,0x21202020,0x20202020,0x20212020,0x20202020,0x20202120
	.word 0x20212020,0x20202020,0x20202120,0x21202020,0x20202021,0x20212020,0x20202020,0x20202020

	.word 0x20202021,0x20202021,0x21202020,0x20202020,0x20212020,0x20212020,0x20202120,0x20202120
	.word 0x20202021,0x20202020,0x21202020,0x20202020,0x20212020,0x20202020,0x20202020,0x20202020

	.section .rodata
	.align	2
	.global stage_scene_bn_gfxMap		@ 2048 unsigned chars
	.hidden stage_scene_bn_gfxMap
stage_scene_bn_gfxMap:
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003
	.hword 0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0001
	.hword 0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001
	.hword 0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001
	.hword 0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007
	.hword 0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0005
	.hword 0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005
	.hword 0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0001,0x0002,0x0001,0x0002,0x0001,0x0002
	.hword 0x0001,0x0002,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0003,0x0004,0x0003,0x0004,0x0003,0x0004,0x0003,0x0004
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0005,0x0006,0x0005,0x0006,0x0005,0x0006
	.hword 0x0005,0x0006,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008
	.hword 0x0007,0x0008,0x0007,0x0008,0x0007,0x0008,0x0007,0x0008

	.section .rodata
	.align	2
	.global stage_scene_bn_gfxPal		@ 96 unsigned chars
	.hidden stage_scene_bn_gfxPal
stage_scene_bn_gfxPal:
	.hword 0x7C1F,0x4210,0x1CE7,0x7FFF,0x6F7B,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x000B,0x021F,0x001F,0x4F1F,0x7E80,0x7C80,0x427A,0x03E0
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x7F0F,0x7F94,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(stage_scene_bn_gfx)
