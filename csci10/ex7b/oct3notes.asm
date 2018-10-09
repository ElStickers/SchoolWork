;oct 3 csci10 notes
; Exercise 7b - math tutor
; ex7b.asm

[bits 32]

global _main

extern _printf
extern _scanf

%macro print 1
  pushad
  
  sub   esp, 16
  mov   dword [esp], %1
  call  _printf
  add   esp, 16
  
  popad
%endmacro

%macro printThreeVars 4
	pushad
	
	sub esp, 16
	mov dword[esp], %1
	mov eax, [%2]
	mov dword[esp + 4], eax
	mov eax, [%3]
	mov dword[esp + 8], eax
	mov eax, [%4]
	mov dword[esp + 12], eax
	call _printf
	add esp, 16
	
	popad
%endmacro

%macro readInteger 2
    sub   esp, 16
    mov   dword [esp], %1
    mov   dword [esp+4], %2
    call  _scanf
    add   esp, 16
%endmacro

%macro getInteger 1
  %%_start_get_integer:
    print prompt1
    readInteger intfmt, %1
    cmp dword[%1], 1
    jb %%_start_get_integer
    cmp dword[%1], 1000
    ja %%_start_get_integer
%endmacro

section .data
  endline db  "", 10, 0
  welcome db  "Welcome to the Math Tutor!", 0

  prompt1 db  "Enter an unsigned integer (1-1000): ", 0
  prompt2 db  "Go again [y/n]? ", 0

  add_out db "%u + %u = %u", 0
  mul_out db "%u * %u = %u", 0
  div_out db "%u \ %u = %u", 0
  mod_out db "%u %% %u = %u", 0

  intfmt  db    "%u", 0
  charfmt db    " %c", 0

  input1  dd  0
  input2  dd  0
  result  dd  0
  remainder dd 0
  restart db  0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome
  print endline
  print endline

  _start:

    ; get inputs
    getInteger input1
    getInteger input2

    ; ADD
    mov eax, [input1]
    add eax, [input2]
    mov [result], eax
    printThreeVars add_out, input1, input2, result
    print endline

    ; SUB
    

    ; MUL
	mov eax, [input1]
	mov ebx, [input2]
	mul ebx
	mov [result], eax
	printThreeVars mul_out, input1, input2, result
    print endline
    

    ; DIV
	mov eax, [input1]
	mov edx, 0
	mov ebx, [input2]
	div ebx
	mov [result], eax
	printThreeVars div_out, input1, input2, result
	print endline
    

    ; MOD
	mov [result], edx
	printThreeVars mod_out, input1, input2, result
	print endline
    

  _ask_restart:
    print endline
    print prompt2

    sub   esp, 16
    mov   dword [esp], charfmt
    mov   dword [esp+4], restart
    call  _scanf
    add   esp, 16

    mov   al, [restart]
    cmp   al, 96
    jna   _check_restart
    sub   al, 32

    _check_restart:
      cmp al, 89
      je    _start

    mov   esp, ebp
    mov   eax, 1
    pop   ebp
    ret
