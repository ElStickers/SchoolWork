; Exercise 11b - processing arrays
; ex11b.asm

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

%macro printTwo 2
  pushad

  sub   esp, 16
  mov   dword [esp], %1
  mov   eax, dword %2
  mov   dword [esp+4], eax
  call  _printf
  add   esp, 16

  popad
%endmacro

%macro populateArray 2
  mov ecx, 0
  %%_start_populate:
    push ecx
    getRandomSigned
    pop ecx

    mov dword [%1 + ecx * 4], eax

    inc ecx
    cmp ecx, %2
    jb %%_start_populate
%endmacro

%macro getRandomSigned 0
  getRandom 100
  mov ebx, eax

  push ebx
  getRandom 2
  pop ebx

  cmp eax, 2
  jl %%_is_positive
    mov eax, ebx
    mov ebx, -1
    imul ebx
    mov ebx, eax
  %%_is_positive:
  mov eax, ebx
%endmacro

%macro getRandom 1
  mov   cl, 11
  %%_get_random:
    sub cl, 1
    jz  %%_not_random
    rdrand  eax
    jnc %%_get_random

    ; make the number be between 1-%1
    mov ah, 0
    mov bl, %1
    div bl
    add ah, 1
    movsx bx, ah
    jmp %%_random_ready

    %%_not_random:
      rdtsc
      jmp %%_end_random
    %%_random_ready:
      movsx eax, bx
    %%_end_random:
%endmacro

section .data
  endline db  "", 10, 0
  welcome db  "Welcome to the array program!", 0

  intout db  "%d ", 0
  prompt2 db  "Go again [y/n]? ", 0

  charfmt db    " %c", 0

  restart db 0
  m_array times 10 dw 0

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
    
    ; clear the array
    ; print the array

    print endline
    print endline
    
    ; population the array with random numbers
    ; print the array

    print endline
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
