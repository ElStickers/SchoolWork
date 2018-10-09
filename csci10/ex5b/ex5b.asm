; Exercise 5b - data viewer
; ex5b.asm

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
  endline db  "", 10, 0
  welcome db  "Welcome to the data viewer.", 0

  prompt2 db  "Go again [y/n]? ", 0

  charfmt db    " %c", 0

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

    ; prompt for and read four inputs

    ; display input1

    ; display input2

    ; display input3

    ; display input4

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
