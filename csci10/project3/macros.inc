; This macro will print all arguments given to it.
; %1  must be format string.
; %2+ are all variables you want to print (value).
%macro print 1-*
    pushad
    
    mov  ebx, 0
    sub  esp, 16
    
    %rep %0
        
        mov  dword[esp+ebx*4], %1
        inc  ebx
        
    %rotate 1
    %endrep
    
    call _printf
    add  esp, 16
    
    popad
%endmacro

; Asks the user for input and stores the value in memory.
; %1 Format to be read
; %2 Memory location to store value in.
%macro read 2
    pushad

    sub   esp, 16
    mov   dword [esp], %1
    mov   dword [esp+4], %2
    call  _scanf
    add   esp, 16
    
    popad
%endmacro

; Ensures the user enters correct integers.
%macro getInteger 0
    pushad
    
    %%_start_get_input:
        print inputPrompt2
        read intFmt, tempInt
        
        cmp  dword[tempInt], 1000
        jg   %%_repeat_get_input
        cmp  dword[tempInt], -1000
        jl   %%_repeat_get_input
        
        jmp  %%_end_get_input
        
    %%_repeat_get_input:
        print endline
        print endline
        print incorrectInput
        print endline
        print endline
        jmp %%_start_get_input
        
    %%_end_get_input:
    
    popad
%endmacro

; Asks the user for integers until array is full.
; %1 Array base (memory)
; %2 Array size (memory)
%macro populateArray 2
    pushad
    
    print inputPrompt1
    
    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    %%_start_populate_array:
        mov  edx, [%1+ecx*4]
        getInteger
        
        mov  edx, [tempInt]
        mov  dword[%1+ecx*4], edx                ; Place user input in array.
        
        inc  ecx
        cmp  ecx, [%2]
        jb   %%_start_populate_array

        mov  dword[tempInt], 0                   ; Clear tempInt
    
    popad
%endmacro

; Sort the array in ascending order.
; %1 Array base (memory)
; %2 Array size (memory)
%macro sortArray 2
    pushad

    mov  ecx, 0                                  ; ECX will count for the loop
    %%_start_sort_array:
        mov  ebx, [%1+ecx*4]                     ; EBX will hold current element to be compared.
        mov  eax, [%1+ecx*4+4]                   ; EAX will hold next element to be compared to.
        cmp  ebx, eax
        jnl  %%_move_up
        jmp  %%_repeat_sort_array
        ; Don't forget to mark that one has been changed to run again!!!!!!!!

    %%_move_up:
        mov  dword[tempInt], 1                   ; Mark for repeat
        mov  dword[%1+ecx*4], eax                ; Switch the two elements
        mov  dword[%1+ecx*4+4], ebx

    %%_repeat_sort_array:
        mov  edx, [%2]                           ; EDX will help compare for end of loop.
        sub  edx, 1                              ; Needs to be one less than intArraySize
        inc  ecx
        cmp  ecx, edx
        jne  %%_start_sort_array

    mov  ecx, 0
    cmp  dword[tempInt], 0
    je   %%_end_sort_array

    ; Repeats to sort other elements in the array
    mov  dword[tempInt], 0                   ; Clear tempInt
    jmp  %%_start_sort_array

        %%_end_sort_array:

    popad
%endmacro

; Prints the array of integers.
; %1 Array base (memory)
; %2 Array size (memory)
%macro printArray 2
    pushad
    
    print arrayFmt1
    
    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    %%_start_print_array:
        mov  edx, [%1+ecx*4]
        print arrayFmt2, edx                     ; Print current integer

        inc  ecx
        cmp  ecx, [%2]
        jb   %%_start_print_array
        
        print endline
    
    popad
%endmacro

; Sets all integers in the array to 0
; %1 Array base (memory)
; %2 Array size (memory)
%macro clearArray 2
    pushad
    
    ; Clear array
    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    %%_start_clear_array:
        mov  dword[%1+ecx*4], 0

        inc  ecx
        cmp  ecx, [%2]
        jb   %%_start_clear_array
        
    popad
%endmacro

; Gets minimum value in the array.
; %1 Array base (memory)
; %2 Array size (memory)
%macro getMin 2
    pushad
    
    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    mov  edx, [%1]                               ; EDX will hold the min value
    %%_start_get_min:
        cmp  dword[%1+ecx*4], edx
        jl  %%_smaller_value
        
    %%_loop_check_min:
        inc  ecx
        cmp  ecx, [%2]
        jnz  %%_start_get_min
        jmp  %%_end_get_min
        
    %%_smaller_value:
        mov  edx, dword[%1+ecx*4]
        jmp  %%_loop_check_min
        
    %%_end_get_min:
        mov  [min], edx
    
    popad
%endmacro

; Gets maximum value in the array.
; %1 Array base (memory)
; %2 Array size (memory)
%macro getMax 2
    pushad

    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    mov  edx, [%1]                               ; EDX will hold the min value
    %%_start_get_max:
        cmp  dword[%1+ecx*4], edx
        jg  %%_larger_value
        
    %%_loop_check_max:
        inc  ecx
        cmp  ecx, [%2]
        jb   %%_start_get_max
        jmp  %%_end_get_max
        
    %%_larger_value:
        mov  edx, dword[%1+ecx*4]
        jmp  %%_loop_check_max
        
    %%_end_get_max:
        mov  [max], edx

    popad
%endmacro

; Gets sum of all integers in the array.
; %1 Array base (memory)
; %2 Array size (memory)
%macro getSum 2
    pushad

    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    mov  edx, 0                                  ; EDX will hold the sum value
    %%_start_get_sum:
        add  edx, dword[%1+ecx*4]

        inc  ecx
        cmp  ecx, [%2]
        jne  %%_start_get_sum

    mov  [sum], edx

    popad
%endmacro

; Gets the average of all integers in the array using the sum.
; %1 Array size (memory)
%macro getAvg 1
    pushad

    mov  edx, 0                                  ; EDX must be set to 0
    mov  ebx, [%1]                               ; EBX will be the denominator
    mov  eax, [sum]                              ; EAX will be the numerator
    cdq                                          ; Convert the double to quad
    idiv ebx                                     ; eax = eax / ebx

    ; Round value
    cmp  edx, 5
    jge  %%_round_up
    jmp  %%_store_average

    %%_round_up:
        cmp  eax, 0                              ; Check if number is negative
        jl   %%_round_up_negative
        jmp  %%_round_up_positive

        %%_round_up_negative:
            sub  eax, 1
            jmp  %%_store_average

        %%_round_up_positive:
            add  eax, 1
            jmp  %%_store_average

    %%_store_average:
        mov  [avg], eax                          ; Place average in memory

    popad
%endmacro

; Prints all even integers in the array.
; %1 Array base (memory)
; %2 Array size (memory)
%macro printEven 2
    pushad
    
    print evenFmt1

    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    %%_start_print_even:
        mov  edx, 0                              ; EDX must be set to 0
        mov  eax, [%1+ecx*4]                     ; EAX will hold the numerator
        mov  ebx, 2                              ; EBX will hold the denominator
        idiv ebx
        
        cmp  edx, 0
        je   %%_even_value                       ; If the remainder is 0, value was even

    %%_repeat_print_even:
        inc  ecx
        cmp  ecx, [%2]
        jb   %%_start_print_even
        jmp  %%_end_print_even

    %%_even_value:
        mov  eax, [%1+ecx*4]
        print evenFmt2, eax
        jmp  %%_repeat_print_even

    %%_end_print_even:

    popad
%endmacro

; Prints all odd integers in the array.
; %1 Array base (memory)
; %2 Array size (memory)
%macro printOdd 2
    pushad

    print oddFmt1

    mov  ecx, 0                                  ; ECX will count for the loop and incriment memory.
    %%_start_print_odd:
        mov  edx, 0                              ; EDX must be set to 0
        mov  eax, [%1+ecx*4]                     ; EAX will hold the numerator
        mov  ebx, 2                              ; EBX will hold the denominator
        idiv ebx
        
        cmp  edx, 1
        je   %%_odd_value                        ; If the remainder is 1, value was odd

    %%_repeat_print_odd:
        inc  ecx
        cmp  ecx, [%2]
        jb   %%_start_print_odd
        jmp  %%_end_print_odd

    %%_odd_value:
        mov  eax, [%1+ecx*4]
        print oddFmt2, eax
        jmp  %%_repeat_print_odd

    %%_end_print_odd:

    popad
%endmacro

; Ask the user if they want to restart the program.
%macro queryRestart 0
    pushad

    %%_start_query_restart:
        print endline
        print restartPrompt
        read  charFmt, restartValue

        ; Make sure input is 'y' or 'n'
        mov  eax, 'y'
        cmp  [restartValue], eax
        je   %%_end_query_restart
        mov  eax, 'n'
        cmp  [restartValue], eax
        je   %%_end_query_restart

        ; If input isn't 'y' or 'n'
        print endline
        print endline
        print incorrectInput
        print endline
        print endline
        jmp  %%_start_query_restart              ; Repeat restart query

    %%_end_query_restart:
        print endline
        print endline

    popad
%endmacro