;Author 	: Juan Palos
;Filename	: asm_project1.asm
;Description: Simple Vending Machine display and item selection

[bits 32]

%include "project1_lib.mac" ;includes the lib I made for this project, includes macros and .data

global _main
	
section .data
	
section .bss

section .text
_main:
	push ebp
	mov	 ebp, esp
	and  esp, 0xfffffff0
_start:
	call_system clear	;clears the screen
	print endline
	print line			;prints a series of '=' for aesthetic reasons
	print endline
	item_display disp_frmt, item1, price, stock		;prints info of the first item: name, price and stock amount
	print endline
	item_display disp_frmt, item2, price, stock		;prints info of the second item: name, price and stock amount
	print endline
	item_display disp_frmt, item3, price, stock		;prints info of the third item: name, price and stock amount
	print endline
	item_display disp_frmt, item4, price, stock		;prints info of the fourth item: name, price and stock amount
	print endline
	item_display disp_frmt, item5, price, stock		;prints info of the fifth item: name, price and stock amount
	print endline
	print exit		;prints the exit option
	print endline
	print line2		;more aesthetic lines lol
	print endline
	print prompt1	;promtps user for item selection
	print endline
	scan uintfmt, input		;scan for user input
	
	mov al, [input]			;checking if input == 0
	cmp al, 0				;if it is jumps to exit and program stops
	je _exit				;if input != 0 program continues
	
	mov al, [input]			;checks if input == 1
	cmp al, 1				;if true jumps to corresponding output for item 1
	je _output1
	
	mov al, [input]			;checks if input == 2
	cmp al, 2				;if true jumps to corresponding output for item 2
	je _output2				;does the same for #3-5
	
	mov al, [input]
	cmp al, 3
	je _output3
	
	mov al, [input]
	cmp al, 4
	je _output4
	
	mov al, [input]			;checks if input == 5
	cmp al, 5				;if true jumps to item 5 output
	je _output5				;if above then it jumps back to the begining
	ja _start
	
_output1:						;all ouputs will jump to try again once they print
	print2 	out_prmpt, item1
	print 	endline	
	jmp _try_again
_output2:
	print2 	out_prmpt, item2
	print endline
	jmp _try_again
_output3:
	print2 	out_prmpt, item3
	print endline
	jmp _try_again
_output4:
	print2 	out_prmpt, item4
	print endline
	jmp _try_again
_output5:
	print2 	out_prmpt, item5
	print endline
	jmp _try_again
_try_again:					;asks if user wants to select another item
	print 	again			
	scan	charfmt, input
	mov al, [input]
	cmp al, 96				;checks if input is lowercase if it isnt it makes jump to check
	jna _check	
	sub al, 32				;if input is lowercase we subtract 32 to convert input to upercase
	
_check:						;checks in input == Y 
	cmp al, 89				;if Y then jumps to start
	je _start
	cmp al, 78				;check if input == N if it isnt then it will jump back to 
	jne _try_again			;the try_again label since invalid input was given
_exit:						;if input == N then program continues as normal and exits
	
	mov  esp, ebp
	mov  eax, 1
	pop  ebp

ret






