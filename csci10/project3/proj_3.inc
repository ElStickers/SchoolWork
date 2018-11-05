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

;%1 frmt, %2 array, %3 size
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
  %%_start_populate:
    grabNumber   int_frmt, %2
    printDigit   test_, %2
    print        endline
    mov  eax, [%2]
    mov  dword[ebx+ecx*4], eax
    inc  ecx
    cmp  ecx, %4
    jb   %%_start_populate
  add    esp, 16
popad
%endmacro

%macro	grabNumber 2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		dword[esp+4], %2
		call	_scanf
		add		esp, 16
	popad
%endmacro

section .data
endline			db	"", 10, 0
clear				db	"cls", 0
array_prmt  db  "Please enter %i numbers. Limit (-1000-1000).", 10, 0

int_frmt		db	"%i", 0
prnt_frmt   db  "%i", 10, 0
test_       dd  "your number is %i", 10, 10, 0

value       dd 0
counter     dd 1
size        dd 10

array       times 10 dd 10


ascii1      dd  "   _|_|                                                           _|_|     _|_|_|_|_|", 10, 0
ascii2      dd  " _|    _|  _|  _|_|  _|  _|_|    _|_|_|  _|    _|     _|_|      _|             _|      _|_|    _|_|_|  ", 10, 0
ascii3      dd  " _|_|_|_|  _|_|      _|_|      _|    _|  _|    _|   _|    _|  _|_|_|_|         _|    _|_|_|_|  _|    _|", 10, 0
ascii4      dd  " _|    _|  _|        _|        _|    _|  _|    _|   _|    _|    _|             _|    _|        _|    _|", 10, 0
ascii5      dd  " _|    _|  _|        _|          _|_|_|    _|_|_|     _|_|      _|             _|      _|_|_|  _|    _|", 10, 0
ascii6      dd  "                                               _|                                                        ", 10, 0
ascii7      dd  "                                           _|_|                                                          ", 10, 0
