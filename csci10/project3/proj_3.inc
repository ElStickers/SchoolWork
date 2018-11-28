;Author			: Juan Palos
;Name			: project2_lib.mac
;Description : lib file containing macros and variables for project2

extern _printf
extern _scanf
extern _system

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

;%1 frmt, %2 array
%macro	printArray 2
  pushad
    sub    esp, 16
    mov    ecx, 0
    %%_start_print:
      mov  edx, [%2+ecx*4]
      print %1, edx
      inc  ecx
      cmp  ecx, 10
      jb   %%_start_print
    add    esp, 16
  popad
%endmacro

;%1 frmt, %2 size
%macro printPrompt 2
  pushad
    sub   esp, 16
    mov   dword[esp], %1
    mov   eax, %2
    mov   dword[esp+4], eax
    call  _printf
    add   esp, 16
  popad
%endmacro

;%1frmt, %2number
%macro	printDigit 2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		eax, [%2]
		mov		dword[esp+4], eax
		call	_printf
		add		esp, 16
	popad
%endmacro

;%1 frmt, %2 value, %3 array, %4 size
%macro populateArray 4
pushad
  sub    esp, 16
  mov    ebx, %3
  mov    ecx, 0
	mov		 esi, 1
  %%_start_populate:
		print				 num_entry, esi
    grabNumber   int_frmt, %2
    print        endline
    mov  eax, [%2]
    mov  dword[ebx+ecx*4], eax
    inc  ecx
		inc  esi
    cmp  ecx, %4
    jb   %%_start_populate
  add    esp, 16
popad
%endmacro

%macro	grabNumber 2
	pushad
		sub		esp, 16
		%%_begin_grabNumber:
			mov		dword[esp], %1
			mov		dword[esp+4], %2
			call	_scanf
		%%_range_check:
			cmp		dword[%2], -1000
			jl		%%_print_prompt
			cmp		dword[%2], 1000
			jg		%%_print_prompt
				jmp %%_exit
		%%_print_prompt:
			print num_range
			print num_entry, esi
			jmp	  %%_begin_grabNumber
		%%_exit:
		add		esp, 16
	popad
%endmacro

%macro	grabMenuChoice 2
	pushad
		sub		esp, 16
		%%_begin_grabNumber:
			mov		dword[esp], %1
			mov		dword[esp+4], %2
			call	_scanf
		%%_range_check:
			cmp		dword[%2], 0
			jl		%%_print_prompt
			cmp		dword[%2], 8
			jg		%%_print_prompt
				jmp %%_exit
		%%_print_prompt:
			print menu_range
			jmp	  %%_begin_grabNumber
		%%_exit:
		add		esp, 16
	popad
%endmacro


section .data
endline			db	"", 10, 0
clear				db	"cls", 0
array_prmt  db  "Please enter %i numbers. Limit (-1000-1000).", 10, 0
num_range		db	"Your number is out of range. Please select a number larger than -1000 but less than 1000.", 10, 0
num_entry		db	"Number %i: ", 0
menu_prmpt	db  "What would you like to do?", 10, "Choice: ", 0
menu_range	db  "Your number is out of range. Please select a number from 0 to 8", 10, 0
int_frmt		db	"%i", 0
prnt_frmt   db  "%i", 10, 0
test_       db  "your number is %i", 0

value       dd 0
choice      dd 0
counter     dd 1
size        dd 10

array       times 10 dd 10

;display stuff(ascii art and menu setup)
line				db	" ================================================================================================", 10, 0
menu				db	"|----------------------------------------------MENU----------------------------------------------|", 10
						db	"| 1) Insert Numbers(10) Into array              |  2) Print Array Contents                       |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10
						db	"| 3) Display Minimum Value In Array             |  4) Display Maximum Value In Array             |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10
						db	"| 5) Dispaly Sum Of Array Values                |  6) Display Average Of Array Values            |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10
						db	"| 7) Display Even Vaulues In Array              |  8) Do All(In Menu Order)                      |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10
						db	"| 9) Clear Array Contents                       |  0) Exit                                       |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10, 0
ascii 			db	"|  ___    ___ ________  ________       ________  ________  ________  ________      ___    ___    |", 10
						db	"|  |\  \  /  /|\   __  \|\   ____\     |\   __  \|\   __  \|\   __  \|\   __  \    |\  \  /  /|  |", 10
						db	"|  \ \  \/  / | \  \|\  \ \  \___|     \ \  \|\  \ \  \|\  \ \  \|\  \ \  \|\  \   \ \  \/  / /  |", 10
						db	"|   \ \    / / \ \   __  \ \  \____     \ \   __  \ \   _  _\ \   _  _\ \   __  \   \ \    / /   |", 10
						db	"|    /     \/   \ \  \|\  \ \  ___  \    \ \  \ \  \ \  \\  \\ \  \\  \\ \  \ \  \   \/  /  /    |", 10
						db	"|   /  /\   \    \ \_______\ \_______\    \ \__\ \__\ \__\\ _\\ \__\\ _\\ \__\ \__\__/  / /      |", 10
						db	"|  /__/ /\ __\    \|_______|\|_______|     \|__|\|__|\|__|\|__|\|__|\|__|\|__|\|__|\___/ /       |", 10
						db	"|  |__|/ \|__|                           By Juan Palos                            \|___|/        |", 10, 0
