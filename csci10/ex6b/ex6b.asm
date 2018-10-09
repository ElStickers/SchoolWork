; Exercise 6b - register viewer
; ex6b.asm

[bits 32]

global _main

extern _printf

%macro print 1
  sub   esp, 16
  mov   dword [esp], %1
  call  _printf
  add   esp, 16
%endmacro

%macro printTwo 3
  sub   esp, 16
  mov   dword [esp], %1
  mov   dword [esp+4], %2
  mov   dword [esp+8], %3
  call  _printf
  add   esp, 16
%endmacro

section .data
  endline  db "", 10, 0
  welcome  db "Welcome to the register viewer.", 0
  reg_overlay  db "SHOWING REGISTER OVERLAY", 0
  reg_volatile db "SHOWING REGISTER VOLATILITY", 0

  eax_str  db "EAX", 0
  ebx_str  db "EBX", 0
  ecx_str  db "ECX", 0
  edx_str  db "EDX", 0

  out_dec  db "%s (decimal): %u", 0
  out_hex  db "%s (hex):     0x%08x", 0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome
  print endline
  print endline

  ; SHOWING REGISTER VOLATILITY
  print reg_volatile
  print endline
  print endline

  ; EAX
  mov   eax, 0
  printTwo out_dec, eax_str, eax
  print endline
  printTwo out_hex, eax_str, eax
  print endline
  print endline
  ; EBX
  mov	ebx, 0
  printTwo out_dec, ebx_str, ebx
  print endline
  printTwo out_hex, ebx_str, ebx
  ; ECX
  mov	ecx, 0
  printTwo out_dec, ecx_str, ecx
  print endline
  printTwo out_hex, ecx_str, ecx

  ; EDX


  ; SHOWING REGISTER OVERLAY
  print reg_overlay
  print endline
  print endline

  ; EAX -> AL -> AH -> AX -> EAX SEQUENCE
  mov	eax, 0
  mov	al, 0xff
  mov	


  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret
