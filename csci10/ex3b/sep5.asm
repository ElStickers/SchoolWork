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
  endline  db  "", 10, 0
  welcome  db  "Welcome to my number comparing program.", 0
  prompt1  db  "Enter a number: ", 0 
  prompt2  db  "Enter another number: ", 0 
  prompt3  db  "Go again [y/n]? ", 0
  output1  db  "The first number %u is greater than the second number %u.", 0 
  output2  db  "The second number %u is greater than the first number %u.", 0 
  output3  db  "The first number %u is equivalent to the second number %u.", 0 
  errormsg db "Please enter a value between 1 and 50.", 0 
  testout  db  "You entered %u.", 0

  uintfmt  db  "%u", 0
  charfmt  db  " %c", 0

  input1   dd  10 
  input2   dd  0 
  answer   dd  0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0
  
  _input_1_loop:
	  ; input1, between 1 and 50
	  print prompt1 
	  
	  sub   esp, 16 
	  mov   dword[esp], uintfmt
	  mov   dword[esp+4], input1 
	  call  _scanf 
	  add   esp, 16 
	  
	  mov   al, [input1]
	  cmp   al, 50 
	  ja    _input_1_error
	  
	  cmp   al, 1 
	  jb    _input_1_error
	  
	  jmp   _input_1_end
	  
	  _input_1_error: 
		print errormsg
		print endline
		jmp   _input_1_loop
  
	  _input_1_end:
  
	  sub   esp, 16
      mov   dword[esp], testout
	  movzx eax, byte[input1]
	  mov   dword[esp+4], eax
      call  _printf
      add   esp, 16
  
  
  
  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret
