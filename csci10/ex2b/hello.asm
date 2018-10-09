; An assembly program
; 29 Aug 18

[bits 32]

global _main

extern _printf
extern _scanf

%macro print_one_thing 1
	sub esp, 16
	mov dword[esp], %1
	call _printf
	add esp, 16
%endmacro

section .data
	msg1 db "tacocat racecar sitonapotatopanotis", 10, 0
	msg2 db "farewell...", 10, 0
	
section .bss

section .text
_main:

	; setup
	push ebp
	mov ebp, esp
	and esp, 0xffffff0
	
	; print the message
	print_one_thing msg1
	
	print_one_thing msg2
	
	;teardown
	mov esp, ebp
	mov eax, 16
	pop ebp

ret
