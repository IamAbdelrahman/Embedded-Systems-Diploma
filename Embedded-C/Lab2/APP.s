
APP.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0008 	ldr	r0, [pc, #8]	; 18 <main+0x18>
   c:	ebfffffe 	bl	0 <UART_send_string>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e8bd8800 	pop	{fp, pc}
  18:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	413a6874 	teqmi	sl, r4, ror r8
  10:	6c656462 	cfstrdvs	mvd6, [r5], #-392	; 0xfffffe78
  14:	6d686172 	stfvse	f6, [r8, #-456]!	; 0xfffffe38
  18:	00006e61 	andeq	r6, r0, r1, ror #28
	...

Disassembly of section .rodata:

00000000 <string_buffer2>:
   0:	61657263 	cmnvs	r5, r3, ror #4
   4:	61206574 			; <UNDEFINED> instruction: 0x61206574
   8:	6f722e20 	svcvs	0x00722e20
   c:	61746164 	cmnvs	r4, r4, ror #2
  10:	63657320 	cmnvs	r5, #32, 6	; 0x80000000
  14:	6e6f6974 			; <UNDEFINED> instruction: 0x6e6f6974
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	3128203a 			; <UNDEFINED> instruction: 0x3128203a
   8:	2d393a35 	vldmdbcs	r9!, {s6-s58}
   c:	39313032 	ldmdbcc	r1!, {r1, r4, r5, ip, sp}
  10:	2d34712d 	ldfcss	f7, [r4, #-180]!	; 0xffffff4c
  14:	75627530 	strbvc	r7, [r2, #-1328]!	; 0xfffffad0
  18:	3175746e 	cmncc	r5, lr, ror #8
  1c:	2e392029 	cdpcs	0, 3, cr2, cr9, cr9, {1}
  20:	20312e32 	eorscs	r2, r1, r2, lsr lr
  24:	39313032 	ldmdbcc	r1!, {r1, r4, r5, ip, sp}
  28:	35323031 	ldrcc	r3, [r2, #-49]!	; 0xffffffcf
  2c:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  30:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  34:	5b202965 	blpl	80a5d0 <main+0x80a5d0>
  38:	2f4d5241 	svccs	0x004d5241
  3c:	2d6d7261 	sfmcs	f7, 2, [sp, #-388]!	; 0xfffffe7c
  40:	72622d39 	rsbvc	r2, r2, #3648	; 0xe40
  44:	68636e61 	stmdavs	r3!, {r0, r5, r6, r9, sl, fp, sp, lr}^
  48:	76657220 	strbtvc	r7, [r5], -r0, lsr #4
  4c:	6f697369 	svcvs	0x00697369
  50:	3732206e 	ldrcc	r2, [r2, -lr, rrx]!
  54:	39393537 	ldmdbcc	r9!, {r0, r1, r2, r4, r5, r8, sl, ip, sp}
  58:	Address 0x0000000000000058 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002b41 	andeq	r2, r0, r1, asr #22
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000021 	andeq	r0, r0, r1, lsr #32
  10:	45543505 	ldrbmi	r3, [r4, #-1285]	; 0xfffffafb
  14:	0506004a 	streq	r0, [r6, #-74]	; 0xffffffb6
  18:	01090108 	tsteq	r9, r8, lsl #2
  1c:	01140412 	tsteq	r4, r2, lsl r4
  20:	03170115 	tsteq	r7, #1073741829	; 0x40000005
  24:	01190118 	tsteq	r9, r8, lsl r1
  28:	061e011a 			; <UNDEFINED> instruction: 0x061e011a
