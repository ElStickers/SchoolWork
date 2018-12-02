; Author:       Juan Palos
; Filename:     project3.asm
; Description:

[bits 32]

%include  "proj3_mac.inc"
%include  "data.inc"

global _main

section .data

section .bss

section .text

_main:
  push    ebp
  mov     ebp, esp
  and     esp, 0xfffffff0

  _begin:
    ;menu display
    callSys         clear
    print           line
    print           ascii
    print           line
    print           menu
    print           line
    grabMenuChoice  int_frmt, choice
    ;decision handling
    mov             al, [choice]
    cmp             al, 0
    je              _exit
    cmp             al, 1
    je              _populate_array
    cmp             al, 2
    je              _print_array
    cmp             al, 3
    je              _display_min_value
    cmp             al, 4
    je              _display_max_value
    cmp             al, 5
    je              _display_sum
    cmp             al, 6
    je              _display_average
    cmp             al, 7
    je              _display_even_values
    cmp             al, 8
    je              _display_odd_values
    cmp             al, 9
    je              _clear_array

  _clear_array:
    clearArray      array, [size]
    cmp             al, 9
    je              _ask_retry
    print           endline
  _populate_array:
    printPrompt     array_prmt, [size]
    populateArray   int_frmt, value, array, [size]
    print           endline
    cmp             al, 1
    je              _ask_retry
  _print_array:
    printArray      prnt_frmt, array
    print           endline
    cmp             al,2
    je              _ask_retry
  _display_min_value:
    findMin         array, [size]
    printDigit      min_value, minimum
    print           endline
    cmp             al,3
    je              _ask_retry
  _display_max_value:
    findMax         array, [size]
    printDigit      max_value, maximum
    print           endline
    cmp             al,4
    je              _ask_retry
  _display_sum:
    arraySum        array, [size]
    printDigit      sum_value, sum
    print           endline
    cmp             al,5
    je              _ask_retry
  _display_average:
    arrayAverage    [size]
    printDigit      avg_value, average
    print           endline
    cmp             al, 6
    je              _ask_retry
  _display_even_values:
    findEven        array, [size]
    print           endline
    cmp             al, 7
    je              _ask_retry
  _display_odd_values:
    findOdd         array, [size]
    print           endline
    cmp             al, 8
    je              _ask_retry
  _ask_retry:
    print 				endline
    print 				retry_prmpt
    scan					char_fmt, restart

    mov   				al, [restart]
    cmp   				al, 96
    jna   				_check_restart
    sub  				 	al, 32
  _check_restart:
    cmp 					al, 89
    je    				_begin
    cmp 					al, 78
    jne 					_ask_retry
  _exit:
  mov     esp, ebp
  mov     eax, 1
  pop     ebp
ret
