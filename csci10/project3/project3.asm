; Author:       Juan Palos
; Filename:     project3.asm
; Description:

[bits 32]

%include "proj_3.inc"

global _main

section .data

section .bss

section .text

_main:
  push    ebp
  mov     ebp, esp
  and     esp, 0xfffffff0

  _begin:
    print           line
    printAscii      ascii
    print           line
    printPrompt     array_prmt, [size]
    populateArray   int_frmt, value, array, [size]
    printArray      prnt_frmt, array

  mov     esp, ebp
  mov     eax, 1
  pop     ebp
ret
