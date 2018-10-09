;Author		: Juan Palos
;Filename	: asm_project2.asm
;Description:

[bits 32]

%include "p2_lib.mac"

global _main

section .data

section .bss

section .text

_main:
	push	ebp
	mov		ebp, esp
	and		esp, 0xfffffff0

	_begin:
		callSystem	clear
		print		ascii1
		print		ascii2
		print 		ascii3
		print 		ascii4
		print 		ascii5

		print		line
		printGuide	guide_frmt, guide1
		print 		line
		printItem 	item0, item1, item2, item3, item4, item5
		print		line

		print 		item_prmpt
		scan		uint_frmt, item_input


	mov		esp, ebp
	mov		eax, 1
	pop		ebp
ret
