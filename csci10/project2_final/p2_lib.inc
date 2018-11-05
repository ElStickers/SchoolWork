;Author			: Juan Palos
;Name			: project2_lib.mac
;Description : lib file containing macros and variables for project2

extern _printf
extern _scanf
extern _system

struc	Guide
	.name:	resb	70
	.price:	resb	70
	.stock:	resb	70
endstruc

struc	Items
	.frmt:	resb	60
	.num:		resd	1
	.name:	resb	60
	.price:	resd	1
	.stock:	resd	1
endstruc

%macro	outputItem 2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		dword[esp+4], %2+Items.name
		call	_printf
		add		esp, 16
	popad
%endmacro

%macro	outputPrice	2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		eax, [%2]
		mov		dword[esp+4], eax
		call	_printf
		add		esp, 16
	popad
%endmacro

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

%macro	scan 2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		dword[esp+4], %2
		call	_scanf
		add		esp, 16
	popad
%endmacro

%macro	printGuide 2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		dword[esp+4], %2 + Guide.name
		mov		dword[esp+8], %2 + Guide.price
		mov		dword[esp+12], %2 + Guide.stock
		call	_printf
		add		esp, 16
	popad
%endmacro

%macro printChange 2
  pushad
    sub esp, 16
    mov dword[esp], %1
    mov dword[esp+4], %2
    call _printf
    add esp, 16
  popad
%endmacro

%macro makeChange 1
  pushad
		mov  eax, %1
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
  popad
%endmacro

;%1 frmt, %2 name, %3 price, %4 stock
%macro printItem  1-*
	pushad
		%rep 	%0
			sub		esp, 32
			mov		dword[esp], %1+Items.frmt
			mov		eax, dword[%1 + Items.num]
			mov		dword[esp+4], eax
			mov		dword[esp+8], %1+Items.name
			mov		eax, dword[%1 + Items.price]
			mov		dword[esp+12], eax
			mov		eax, dword[%1 + Items.stock]
			mov		dword[esp+16], eax
			call	_printf
			add		esp, 32
			%rotate 1
		%endrep
	popad
%endmacro

%macro	callSys	1
	pushad
		sub		esp, 16
		mov 	dword[esp], %1
		call	_system
		add 	esp, 16
	popad
%endmacro

section .data
	endline			db	"", 10, 0
	clear				db	"cls", 0
	line				db	"--------------------------------------------------", 10, 0
	item_prmpt	db	"What would you like to buy? (1-6) (0 to exit)", 10 ,0
	pymnt_prmpt	db	"Please enter the amount of credits you would like to pay with", 10, 0
	credit_out	db	"Credits: ", 0
	chnge_prmpt	db	"Thank You!", 10, "Here is your change: ", 10, 0
	total_prmpt	db	"Total Change: %u Credits", 10, 0
	retry_prmpt	db  "Would you like to select another item? [y/n]? ", 0
	goodbye			db  "Thank You! See you next time.", 10 ,0
  soldout			db	"Sorry this item is sold out", 10, 0
	item_input	dd	0
	pymnt_input	dd	0
	pymnt_amnt	dd	0
	credits			dd 	0
	restart 		db  0

	guide_frmt	db 	"|%s		|| %s	|| %s |", 10, 0
	uint_frmt		db	"%d", 0
	char_fmt		db  " %c", 0
	print_frmt	db	"|%u) %s		|| %u		|| %u	 |", 10, 0
	itm_frmt		db	"You have selected %s", 10, 0
	price_frmt	db	"Amount Due: %u credits", 10, 0
	qout    		db  "%u quarters", 10, 0
  dout    		db  "%u dimes", 10, 0
  nout    		db  "%u nickles", 10, 0
  pout    		db  "%u pennies", 10, 0

	ascii1			db	" __     _______ _   _ ____ ___ _   _  ____   __  __    _    ____ _   _ ___ _   _ _____ ", 10, 0
	ascii2			db	" \ \   / / ____| \ | |  _ \_ _| \ | |/ ___| |  \/  |  / \  / ___| | | |_ _| \ | | ____|", 10, 0
	ascii3			db	"  \ \ / /|  _| |  \| | | | | ||  \| | |  _  | |\/| | / _ \| |   | |_| || ||  \| |  _|", 10, 0
	ascii4			db	"   \ V / | |___| |\  | |_| | || |\  | |_| | | |  | |/ ___ \ |___|  _  || || |\  | |___", 10, 0
	ascii5			db	"    \_/  |_____|_| \_|____/___|_| \_|\____| |_|  |_/_/   \_\____|_| |_|___|_| \_|_____|", 10, 0

	guide1:
		istruc	Guide
			at	Guide.name,		db	"#  Item Name", 0
			at	Guide.price,	db	"Price", 0
			at	Guide.stock,	db	"Stock", 0
		iend

	item1:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	1
			at	Items.name,		db	"Pepsi", 0
			at	Items.price,	dd	20
			at	Items.stock,	dd	3
		iend

	item2:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	2
			at	Items.name,		db	"SmartWater", 0
			at	Items.price,	dd	33
			at	Items.stock,	dd	9
		iend

	item3:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	3
			at	Items.name,		db	"Doritos", 0
			at	Items.price,	dd	24
			at	Items.stock,	dd	7
		iend

	item4:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	4
			at	Items.name,		db	"Scantron", 0
			at	Items.price,	dd	8
			at	Items.stock,	dd	23
		iend

	item5:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	5
			at	Items.name,		db	"Advil 30ct", 0
			at	Items.price,	dd	100
			at	Items.stock,	dd	3
		iend

	item6:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	6
			at	Items.name,		db	"#2 Pencil", 0
			at	Items.price,	dd	17
			at	Items.stock,	dd	2
		iend