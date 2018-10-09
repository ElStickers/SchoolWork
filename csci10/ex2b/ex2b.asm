; Exercise 2b - mad libs
; ex2b.asm

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
  welcome db  "Welcome to my x86 assembly program.", 0

  prompt1 db  "What is your name? ", 0
  output1 db  "Nice to meet you, %s.", 0

  prompt2 db  "How many years have you been at Butte College? ", 0
  output2 db  "You have been at Butte College for %u years? Awesome!", 0

  strfmt  db    "%s", 0
  intfmt  db    "%d", 0

  intinput  dd  0

section .bss
  strinput  resb  100

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome
  print endline
  print endline

  print prompt1

  sub   esp, 16
  mov   dword[esp], strfmt
  mov   dword[esp+4], strinput
  call  _scanf
  add   esp, 16

  sub   esp, 16
  mov   dword[esp], output1
  mov   dword[esp+4], strinput
  call  _printf
  add   esp, 16

  print endline
  print endline

  print prompt2

  sub   esp, 16
  mov   dword[esp], intfmt
  mov   dword[esp+4], intinput
  call  _scanf
  add   esp, 16

  sub   esp, 16
  mov   dword[esp], output2
  mov   eax, [intinput]
  mov   dword[esp+4], eax
  call  _printf
  add   esp, 16

  print endline
  print endline

  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret
