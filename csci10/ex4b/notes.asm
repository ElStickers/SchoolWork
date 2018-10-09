;start assembly loops with labels
_start_while:	{
	;code somwhere in here
	cmp [go], 'n'
	;if not equal we make a jump back to _start_while
	jne _start_while
	;finish off loop with a jump to _start_while at the end
	jmp _start_while
}

;do while loop
do {
	
}while(count > 0)
;asm
_start_do_while:	{
	;code in here
	cmp [count], 0
	ja _start_do_while
}

;sample code
do	{
	printf("Enter a number between 5 and 10: ");
	scanf("%u", %input);
}while(input < 5 || input > 10)
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
while(1)	{
	printf("Enter a number between 0 and 3: ");
	scanf("%u", &input );
	
	if (input == 0)	{
		break;
	}
	else if(input ==1)	{
		printf("Wun...\n");
	}
	else if(input==2)	{
		printf("Too...\n");
	}
	else	{
		printf("Something else.....\n");
	}
}
;asm
_start_while:
	//print prompt
	//read prompt
	
	cmp dword [input], 0
	je _end_while
	
	cmp dword [input], 1
	jne _input_test_2
		// printf "wun"
		jmp _start_while
	
	_input_test_2:
	cmp dword [input], 2
	jne _input_test_other
		//printf "too"
		jmp _start_while
		
	_input_test_other:
	//print "something else"
	jmp _start_while
	
_end_while:
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
1. Apples
2. Oranges
3. Cherries
4. Kiwi
5. Banana
6. Blueberries
7. Avocados
8. Quit

unsigned int  input;
do {
	printf("Your selection: ");
	scanf("%u", &input);
} while (input < 1 || input > 8);

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;asm
_start_input_loop:
	//print prompt
	//get input
	
	cmp [input], 1
	jb _start_input_loop ;jump back if below 1
	
	cmp [input], 8
	ja _start_input_loop ;jump back if above 8
	
	//rest of code stuff



















