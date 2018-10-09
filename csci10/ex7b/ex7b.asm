[bits 32]

global _main

extern _printf
extern _scanf

%macro print 1
	sub esp, 16
	mov dword[esp], %1
	call _printf
	add esp, 16
%endmacro

%macro readNumber 2
	sub esp, 16
	mov dword[esp], %1
	mov eax, %2
	mov dword[esp+4], eax
	call _scanf
	add esp, 16
%endmacro

section .data
	endline  db "", 10, 0
	welcome  db "Welcome to the Math Tutor.", 0
	
	prompt	 db "Enter number (1 - 1000): ", 
	
	add_str  db "%u + %u = %u", 0
	
	uint_str db "%u"

	n1		 dd 0
	n2       dd 0
section .bss

section .text
_main:
	push  ebp
	mov   ebp, esp
	and   esp, 0xfffffff0
	
	print welcome
	print endline
	print endline