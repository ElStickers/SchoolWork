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

		mov				al, [item_input]
		cmp				al, 2
		je				_output2

		mov 			al, [item_input]
		cmp				al, 3
		je				_output3

		mov				al, [item_input]
		cmp				al, 4
		je				_output4

		mov				al, [item_input]
		cmp				al, 5
		je				_output5

		mov				al, [item_input]
		cmp				al, 6
		je				_output6

	_output1:
		outputItem		itm_frmt, item1
		mov						eax, [item1+Items.price]
		mov						[pymnt_amnt], eax
		jmp						_pay

	_output2:
		outputItem		itm_frmt, item2
		mov						eax, [item2+Items.price]
		mov						[pymnt_amnt], eax
		jmp						_pay

	_output3:
		outputItem		itm_frmt, item3
		mov						eax, [item3+Items.price]
		mov						[pymnt_amnt], eax
		jmp						_pay

	_output4:
		outputItem		itm_frmt, item4
		mov						eax, [item4+Items.price]
		mov						[pymnt_amnt], eax
		jmp						_pay

	_output5:
		outputItem		itm_frmt, item5
		mov						eax, [item5+Items.price]
		mov						[pymnt_amnt], eax
		jmp						_pay

	_output6:
		outputItem		itm_frmt, item6
		mov						eax, [item6+Items.price]
		mov						[pymnt_amnt], eax
		jmp						_pay

	_pay:
		print 				pymnt_prmpt
		outputPrice		price_frmt, pymnt_amnt
		print					credit_out
		scan					uint_frmt, credits

	_check_change:
		mov						al, [credits]
		cmp						al, [pymnt_amnt]
		jb						_pay
		je						_change

	_change:
		print 				item_prmpt
		
	_exit:
	
	mov		esp, ebp
	mov		eax, 1
	pop		ebp
ret
