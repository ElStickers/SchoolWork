; Exercise 8b - signed data viewer
; ex8b.asm

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

%macro getPennies 3
pushad
  %%_start_getPennies:
    print %1
    readInteger %2, %3
    cmp dword[%3], 1
    jb  %%_start_getPennies
    cmp dword[%3], 1000
    ja  %%_start_getPennies
popad
%endmacro

%macro readInteger 2
pushad
  sub   esp, 16
  mov   dword [esp], %1
  mov   dword [esp+4], %2
  call  _scanf
  add   esp, 16
popad
%endmacro

;%1 fmt string
;%2 register
%macro printChange 2
  pushad
    sub esp, 16
    mov dword[esp], %1
    mov dword[esp+4], %2
    call _printf
    add esp, 16
  popad
%endmacro

section .data
  endline db  "", 10, 0
  welcome db  "Welcome to the change maker.", 0

  prompt1 db  "Enter the number of pennies (1-1000)", 0
  prompt2 db  "Go again [y/n]? ", 0


  qout    db  "%u quarters"
  dout    db  "%u dimes"
  nout    db  "%u nickles"
  pout    db  "%u pennies"

  intfmt  db    "%u", 0
  charfmt db    " %c", 0

  value  dd  0
  input1 dd 0
  restart db  0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome
  print endline

  _start:
    print endline
    getPennies  prompt1, intfmt, value
    print endline

    ;quarters
    mov  eax, [value]
    mov  edx, 0
    mov  ecx, 25
    div  ecx
    printChange qout, eax
    print endline

    ;dimes
    mov  eax, edx
    mov  edx, 0
    mov  ecx, 10
    div  ecx
    printChange dout, eax
    print endline

    mov  eax, edx
    mov  edx, 0
    mov  ecx, 5
    div  ecx
    printChange nout, eax
    print endline

    printChange pout, edx


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

    %macro	print 1-*
    	pushad
    		mov ebx, 0
    		sub 	esp, 16
    		%rep %0
    			mov		dword[esp+ebx], %1
    			add 	ebx, 4
    			%rotate 1
    		%endrep
    		call	_printf
    		add		esp, 16
    	popad
    %endmacro
