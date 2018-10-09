; Exercise 4b - number guesser
; ex4b.asm

[bits 32]

global _main

extern _printf
extern _scanf

%macro print 1
  sub   esp, 16
  mov   dword [esp], %1
  call  _printf
  add   esp, 16
%endmacro

section .data
  endline  db  "", 10, 0
  prompt   db  "Enter a value between 0 and 3: ", 0

  wun      db  "Wun...", 0
  too      db  "Tu...", 0
  sumthin  db  "Sumthin els...", 0

  uintfmt  db    "%u", 0

  input    dd  0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  _start_while:
	print endline

	; prompt
	print prompt 
	
	; read input
	sub   esp, 16
    mov   dword [esp], uintfmt
    mov   dword [esp+4], input
    call  _scanf
    add   esp, 16
	
	print endline
	
	; check input
	cmp dword [input], 0 
	je _end_while
	
	cmp dword [input], 1
	jne _input_test_2
		print wun
		jmp _start_while
	
	_input_test_2:
	cmp dword [input], 2
	jne _input_test_other
		print too
		jmp _start_while
	
	_input_test_other:
	print sumthin
	jmp _start_while
	
_end_while:

  mov   esp, ebp
  mov   eax, 1
  pop   ebp
  
ret