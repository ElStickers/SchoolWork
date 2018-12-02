;Author			 : Juan Palos
;Name				 : project2_lib.mac
;Description : .inc file containing all the macros for the project3 program

extern _printf
extern _scanf
extern _system

%macro	print 1-*
	pushad
		sub 	esp, 16
			mov ebx, 0
			%rep %0
				mov		dword[esp+ebx], %1
				add 	ebx, 4
				%rotate 1
			%endrep
			call	_printf
		add		esp, 16
	popad
%endmacro

;%1 frmt, %2 value
%macro	scan 2
	pushad
		sub		esp, 16
		mov		dword[esp], %1
		mov		dword[esp+4], %2
		call	_scanf
		add		esp, 16
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

;%1 array, %2 size
%macro	arraySum	2
	pushad
		sub		esp, 16
			mov		edx, 0
			mov		ecx, 0
			%%_start_sum:
				add		edx, dword[%1+ecx*4]
				inc 	ecx
				cmp 	ecx, %2
				jne 	%%_start_sum
					mov	[sum], edx
		add		esp, 16
	popad
%endmacro

;%1 size
%macro	arrayAverage	1
	pushad
		sub	esp, 16
			print avg_calc
			mov		edx, 0
			mov		ebx, %1
			mov		eax, [sum]
			cdq
			idiv	ebx
			%%_round:
				cmp		edx, 5
				jae		%%_round_up
				jmp		%%_found_average
				%%_round_up:
					cmp		eax, 0
					jg		%%_positive
					jmp		%%_negative
					%%_positive:
						add	eax, 1
						jmp		%%_found_average
					%%_negative:
						sub   eax, 1
						jmp		%%_found_average
			%%_found_average:
				mov		[average], eax
				print avg_done
		add	esp, 16
	popad
%endmacro

;%1 array, %2 size
%macro clearArray	2
	pushad
		sub		esp, 16
			mov 	ecx, 0
			mov		ebx, %1
			mov   esi, 1
			print clear_prmt
			%%_start_clear:
			mov					dword[ebx+ecx*4], 0
			inc 				ecx
			inc   			esi
			cmp 				ecx, %2
			jb					%%_start_clear
			print 			done_clear
			printArray  prnt_frmt, array
		add		esp, 16
	popad
%endmacro

;%1array, %2 size
%macro	findEven	2
		pushad
			sub		esp, 16
				mov		ecx, 0
				print	even_search
				%%_find_even:
					mov		edx, 0
					mov		eax, [%1+ecx*4]
					mov		ebx, 2
					idiv	ebx
					cmp		edx, 0
					je		%%_found_even
				%%_even_loop:
					inc   ecx
					cmp		ecx, %2
					jb		%%_find_even
					jmp		%%_done
				%%_found_even:
					mov		eax, [%1+ecx*4]
					print int_frmt, eax
					print	endline
					jmp		%%_even_loop
				%%_done:
					print	even_done
			add		esp, 16
		popad
%endmacro

;%1array, %2 size
%macro	findOdd	2
		pushad
			sub		esp, 16
				mov		ecx, 0
				print	odd_search
				%%_find_odd:
					mov		edx, 0
					mov		eax, [%1+ecx*4]
					mov		ebx, 2
					idiv	ebx
					cmp		edx, 1
					je		%%_found_odd
				%%_odd_loop:
					inc   ecx
					cmp		ecx, %2
					jb		%%_find_odd
					jmp		%%_done
				%%_found_odd:
					mov		eax, [%1+ecx*4]
					print int_frmt, eax
					print endline
					jmp		%%_odd_loop
				%%_done:
					print	odd_done
			add		esp, 16
		popad
%endmacro

;%1 array, %2 size
%macro findMax	2
	pushad
		print max_search
		mov		ecx, 0
		mov		ebx, [%1]
		mov		edx, [%1]
		%%_start_max_search:
			cmp 	dword[%1+ecx*4], edx
			jg	%%_its_bigger
		%%_check_loop_count_max:
			inc	ecx
			cmp ecx, %2
			jne %%_start_max_search
				jmp	%%_found_biggest
		%%_its_bigger:
			mov		edx, dword[%1+ecx*4]
			jmp   %%_check_loop_count_max
		%%_found_biggest:
			mov		[maximum], edx
			print max_found
	popad
%endmacro

;%1 array, %2 size
%macro findMin	2
	pushad
		print min_search
		mov		ecx, 0
		mov		ebx, [%1]
		mov		edx, [%1]
		%%_start_min_search:
			cmp 	dword[%1+ecx*4], edx
			jl		%%_its_smaller
		%%_check_loop_count:
			inc	ecx
			cmp ecx, %2
			jne %%_start_min_search
				jmp	%%_found_smallest
		%%_its_smaller:
			mov		edx, dword[%1+ecx*4]
			jmp   %%_check_loop_count
		%%_found_smallest:
			mov		[minimum], edx
			print min_found
	popad
%endmacro

;%1frmt, %2 choice
%macro	grabMenuChoice 2
	pushad
		sub		esp, 16
		%%_begin_grabNumber:
			print menu_prmpt
			mov		dword[esp], %1
			mov		dword[esp+4], %2
			call	_scanf
		%%_range_check:
			cmp		dword[%2], 0
			jl		%%_print_prompt
			cmp		dword[%2], 10
			jg		%%_print_prompt
				jmp %%_exit
		%%_print_prompt:
			print menu_range
			jmp	  %%_begin_grabNumber
		%%_exit:
		add		esp, 16
	popad
%endmacro

;%1 frmt, %2 value
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

;%1 frmt, %2 array
%macro	printArray 2
  pushad
    sub    esp, 16
	    mov    ecx, 0
			mov		 esi, 1
			print  array_cont
	    %%_start_print:
	      mov   edx, [%2+ecx*4]
				print num_entry, esi
	      print %1, edx
	      inc   ecx
				inc   esi
	      cmp   ecx, 10
	      jb    %%_start_print
    add    esp, 16
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
