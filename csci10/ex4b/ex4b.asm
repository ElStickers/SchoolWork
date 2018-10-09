; Exercise 4b - number guesser
; ex4b.asm

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

%macro printNumber 2
  sub   esp, 16
  mov   dword [esp], %1
  movzx eax, byte [%2]
  mov   dword [esp+4], eax
  call  _printf
  add   esp, 16
%endmacro

section .data
  endline db  "", 10, 0
  welcome db  "Welcome to the number guessing game.", 0

  prompt2 db  "Go again [y/n]? ", 0

  charfmt db    " %c", 0

  restart   db  0

section .bss

section .text
_main:
  push  ebp
  mov   ebp, esp
  and   esp, 0xfffffff0

  print welcome

  _game_start:

    ; get a random number
    mov   cl, 11
    _get_random:
      sub cl, 1
      jz  _not_random
      rdrand  eax
      jnc _get_random

    ; make the number be between 1-100
    mov ah, 0
    mov bl, 100
    div bl
    add ah, 1
    jmp _random_ready

    _not_random:
      rdtsc
    _random_ready:
      mov byte [randnum], ah

  ; guessing loop



  ; see if they want to play again
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
      mov [count], byte 0
      je    _game_start

    mov   esp, ebp
    mov   eax, 1
    pop   ebp
    ret
