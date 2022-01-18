	.include "asm/macros.inc"

	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start ObjectB6
ObjectB6: @ 0x080A0E54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	ldrb r0, [r0, #0xd]
	cmp r0, #3
	bls _080A0E64
	bl DeleteThisEntity
_080A0E64:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne _080A0E76
	movs r0, #1
	strb r0, [r4, #0xc]
	ldrb r1, [r4, #0xa]
	adds r0, r4, #0
	bl InitializeAnimation
_080A0E76:
	ldr r0, [r4, #0x50]
	ldrb r3, [r4, #0xa]
	adds r1, r4, #0
	movs r2, #0
	bl sub_0806FA90
	adds r2, r4, #0
	adds r2, #0x63
	ldrb r0, [r2]
	ldrb r1, [r4, #0xa]
	subs r0, r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl GetNextFrame
	pop {r4, pc}
	.align 2, 0
