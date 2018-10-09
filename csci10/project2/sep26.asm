[bits 32]

global _main

extern _printf

struc Point 
	.x: resd 1 
	.y: resd 1
endstruc

%macro print 1
  sub   esp, 16
  mov   dword [esp], %1
  call  _printf
  add   esp, 16
%endmacro

%macro printRegister 2
sub   esp, 16 
  mov   dword [esp], %1 
  mov   dword [esp + 4], %2 
  call  _printf
  add   esp, 16 
%endmacro

%macro printPoint 2
sub   esp, 16 
  mov  dword [esp], %1 
  mov  eax, [%2 + Point.x]
  mov  dword [esp + 4], eax
  mov  eax, [%2 + Point.y]
  mov  dword [esp + 8], eax  
  call _printf
  add  esp, 16 
%endmacro

section .data
	endline    db "", 10, 0
	overflow   db "OVERFLOW!", 0
	
	point_str  db "x: %u, y: %u", 0 
	
	output_dec db "%u", 0 
	output_hex db "0x%08x", 0 
	
	point1: istruc Point
		at Point.x, dd 13
		at Point.y, dd 42
	iend

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  printPoint point_str, point1
  print endline 
  
  dec dword [point1 + Point.x] 
  
  printPoint point_str, point1
  print endline 
  
  ; experiment 1
  mov ebx, 0x00000000
  
  printRegister output_dec, ebx
  print endline
  printRegister output_hex, ebx 
  print endline
  print endline
  
  ; experiment 2
  mov bl, 0x11
  
  printRegister output_dec, ebx
  print endline
  printRegister output_hex, ebx 
  print endline
  print endline
  
  ; experiment 3
  mov bh, 0x11
  
  printRegister output_dec, ebx
  print endline
  printRegister output_hex, ebx 
  print endline
  print endline
  
  ; experiment 4
  mov bx, 0xFACE
  
  printRegister output_dec, ebx
  print endline
  printRegister output_hex, ebx 
  print endline
  print endline
  
  ; experiment 4
  mov ebx, 0x10100101
  
  printRegister output_dec, ebx
  print endline
  printRegister output_hex, ebx 
  print endline
  print endline
  
  ; experiment 5
  mov ebx, 0x00000000 
  
  cmp ebx, 0 
  je  _do_print
	dec ebx
  
  _do_print:
  
  printRegister output_dec, ebx
  print endline
  printRegister output_hex, ebx 
  print endline
  print endline

  mov   esp, ebp
  mov   eax, 1
  pop   ebp
ret
