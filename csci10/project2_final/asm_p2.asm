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
		callSys		clear
		print			ascii1
		print			ascii2
		print 		ascii3
		print 		ascii4
		print 		ascii5

		print				line
		printGuide	guide_frmt, guide1
		print 			line
		printItem 	item1, item2, item3, item4, item5, item6
		print				line

		print 		item_prmpt
		scan			uint_frmt, item_input

		mov 			al, [item_input]
		cmp				al, 0
		je				_exit

		mov				al, [item_input]
		cmp				al, 1
		je				_output1

	_output1:
		outputItem		itm_frmt, item1
		outputPrice		price_frmt, item1
		mov						eax, [item1+Items.price]
		print					pymnt_amnt
		jmp						_pay

	_output2:
		outputItem		itm_frmt, item2
		outputPrice		price_frmt, item2
		jmp						_pay
	_pay:
		print 				pymnt_prmpt
	_exit:

	mov		esp, ebp
	mov		eax, 1
	pop		ebp
ret
