; Exercise 3b - comparing numbers
; ex3b.asm

[bits 32]

global _main

extern _printf
extern _scanf

%macro print 1
  sub   esp, 16
  mov   dword[esp], %1
  call  _printf
  add   esp, 16
%endmacro

section .data
  endline db  "", 10, 0
  welcome db  "Welcome to my number comparing program.", 0
  prompt1 db  "Enter a number between 1 and 50.", 0
  prompt2 db  "Enter another number between 1 and 50.", 0
  prompt3 db  "Go again [y/n]? ", 0
  output1 db  "The first number %u is greater than the second number %u.", 0
  output2 db  "The second number %u is greater than the first number %u.", 0
  output3 db  "The first and second number are equal.", 0
  errormsg db
  
  charfmt db    " %c", 0
  uintfmt db    "%u", 0

  input1  dd  0
  input2  dd  0
  answer  dd  0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome
  print endline
  print endline

  ;labels, jumps(jmp == while true or go to's) and compares control flow in asm
  ;jmp _main_loop_start == unconditional jump, no codition controlling the jump it just happens
  ;conditional jump..ja == jump if al > 5 jna == al < 5 jna jb jnb je jne 
  _main_loop_start:

    ; first input between 1 and 50
	_input_1_loop:
	
		print prompt1
		
		sub esp, 16
		mov dword[esp], uintfmt
		mov dword[esp+4], input1
		call _scanf
		add esp, 16
		
		;al == process register. square brackets dereference variables. referenced by default
		mov al, [input1]
		cmp al, 50
		ja _input_1_error
		
		cmp al, 1
		jb _input_1_error
		
		jmp _input_2_loop
		
		_input_1_error:
			print errormsg
			print endline
			jmp _input_1_loop
		
	_input_2_loop:
		print prompt2

    ; second input

  ; compare the values

  _compare_end:
    print endline
    print endline

    ; ask if they want to go again
    print prompt3

    sub   esp, 16
    mov   dword[esp], charfmt
    mov   dword[esp+4], answer
    call  _scanf
    add   esp, 16

    mov   al, byte [input3]
    cmp   al, 96
    jna   _check_restart
    sub   al, 32

    _check_restart:
      cmp al, 89
      je    _main_loop_start

  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret
