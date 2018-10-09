; Exercise 1b - print hello world
; ex1b.asm

[bits 32]

global _main

extern _printf

section .data
  welcome db  "Hello world!", 10, 0   ; 10 is ASCII endline, 0 is string terminator
  goodbye db  "Goodbye!", 10, 0

section .bss

section .text
_main:
  ; setup stack
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  ; print hello world
  sub   esp, 16                       ; make space on the stack for parameters
  mov   dword[esp], welcome           ; load address of string to print onto the stack
  call  _printf                       ; call to external printf function
  add   esp, 16                       ; pop the parameters from the stack

  ; pring goodbye
  sub esp, 16
  mov dword[esp], goodbye
  call _printf
  add esp, 16
  
  ; cleanup stack
  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret