;Author			: Juan Palos
;Name			: project2_lib.mac

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

%macro	print 1
	sub		esp, 16
	mov		dword[esp], %1
	call	_printf
	add		esp, 16
%endmacro

%macro	scan 2
	sub		esp, 16
	mov		dword[esp], %1
	mov		dword[esp+4], %2
	call	_scanf
	add		esp, 16
%endmacro

%macro	printGuide 2
	sub		esp, 16
	mov		dword[esp], %1
	mov		dword[esp+4], %2 + Guide.name
	mov		dword[esp+8], %2 + Guide.price
	mov		dword[esp+12], %2 + Guide.stock
	call	_printf
	add		esp, 16
%endmacro

;%1 frmt, %2 name, %3 price, %4 stock
%macro printItem  1-*
	%rep 	%0
		sub		esp, 16
		mov		dword[esp], %1+Items.frmt
		mov		eax, dword[%1 + Items.num]
		mov		dword[esp+4], eax
		mov		dword[esp+8], %1+Items.name
		mov		eax, dword[%1 + Items.price]
		mov		dword[esp+12], eax
		mov		eax, dword[%1 + Items.stock]
		mov		dword[esp+16], eax
		call	_printf
		add		esp, 16
	%rotate 1
	%endrep
%endmacro

%macro	callSystem	1
	sub		esp, 16
	mov 	dword[esp], %1
	call	_system
	add 	esp, 16
%endmacro

section .data
	endline		db	"", 10, 0
	clear		db	"cls", 0
	line		db	"--------------------------------------------------", 10, 0
	item_prmpt	db	"What would you like to buy? (0-6)", 10 ,0
	item_input	dd	0

	guide_frmt	db 	"|%s		|| %s	|| %s |", 10, 0
	uint_frmt	db	"%u", 0

	ascii1		db	" __     _______ _   _ ____ ___ _   _  ____   __  __    _    ____ _   _ ___ _   _ _____ ", 10, 0
	ascii2		db	" \ \   / / ____| \ | |  _ \_ _| \ | |/ ___| |  \/  |  / \  / ___| | | |_ _| \ | | ____|", 10, 0
	ascii3		db	"  \ \ / /|  _| |  \| | | | | ||  \| | |  _  | |\/| | / _ \| |   | |_| || ||  \| |  _|", 10, 0
	ascii4		db	"   \ V / | |___| |\  | |_| | || |\  | |_| | | |  | |/ ___ \ |___|  _  || || |\  | |___", 10, 0
	ascii5		db	"    \_/  |_____|_| \_|____/___|_| \_|\____| |_|  |_/_/   \_\____|_| |_|___|_| \_|_____|", 10, 0

	guide1:
		istruc	Guide
			at	Guide.name,		db	"#  Item Name", 0
			at	Guide.price,	db	"Price", 0
			at	Guide.stock,	db	"Stock", 0
		iend

	item0:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	1
			at	Items.name,		db	"Pepsi", 0
			at	Items.price,	dd	20
			at	Items.stock,	dd	3
		iend

	item1:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	2
			at	Items.name,		db	"SmartWater", 0
			at	Items.price,	dd	33
			at	Items.stock,	dd	9
		iend

	item2:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	3
			at	Items.name,		db	"Doritos", 0
			at	Items.price,	dd	24
			at	Items.stock,	dd	7
		iend

	item3:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	4
			at	Items.name,		db	"Scantron", 0
			at	Items.price,	dd	8
			at	Items.stock,	dd	23
		iend

	item4:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	5
			at	Items.name,		db	"RasberryPie", 0
			at	Items.price,	dd	356
			at	Items.stock,	dd	3
		iend

	item5:
		istruc	Items
			at	Items.frmt,		db	"|%u) %s		|| %u		|| %u	 |", 10, 0
			at	Items.num,		dd	6
			at	Items.name,		db	"Ipad Pro", 0
			at	Items.price,	dd	1234
			at	Items.stock,	dd	2
		iend
