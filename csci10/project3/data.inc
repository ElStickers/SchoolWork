;Author:			Juan Palos
;Name:				data.inc
;Description:	.inc file holding the data section of the program. Which holds all my variables and beautiful ascii art.

section .data
array_prmt  db  "Please enter %i numbers. Limit (-1000 - 1000).", 10, 0
num_range		db	"Your number is out of range. Please select a number larger than -1000 but less than 1000.", 10, 0
num_entry		db	"Number %i: ", 0
menu_prmpt	db  "What would you like to do?", 10, "Choice: ", 0
menu_range	db  "Your number is out of range. Please enter a number from 0 to 10", 10, 0
test_       db  "your number is %i", 0
array_cont	db	"The array contains these numbers: ", 10, 0
clear_prmt	db	"Clearing the Array...", 10, 0
done_clear	db	"Array has been cleared!", 10, 0
retry_prmpt	db  "Would you like to do something else? [y/n]? ", 0
min_value		db	"The Minimum Value is: %i", 10, 0
min_search	db 	"Looking for the minimum value...", 10, 0
min_found		db	"Minimum value has been found!", 10, 0
max_value		db	"The Maximum Value is: %i", 10, 0
max_search	db 	"Looking for the maximum value...", 10, 0
max_found		db	"Maximum value has been found!", 10, 0
sum_value		db	"The sum of the array is: %i", 10, 0
sum_calc		db  "Calculating the sum of the array...", 10, 0
sum_done		db	"The sum of the array has been calculated!", 10, 0
avg_value		db	"The average of the array is: %i", 10, 0
avg_calc		db  "Calculating the average of the array...", 10, 0
avg_done		db	"The average of the array has been calculated!", 10, 0
even_done		db	"All even numbers have been found!", 10, 0
even_search	db	"Looking for even numbers...", 10, "Even Numbers: ", 10, 0
odd_done		db	"All odd numbers have been found!", 10, 0
odd_search	db	"Looking for odd numbers...", 10, "Odd Numbers: ", 10, 0


int_frmt		db	"%i", 0
prnt_frmt   db  "%i", 10, 0
char_fmt		db  " %c", 0
endline			db	"", 10, 0
clear				db	"cls", 0

value       dd 0
choice      dd 0
counter     dd 1
size        dd 10
restart 		dd 0
minimum			dd 0
maximum			dd 0
sum 				dd 0
average 		dd 0

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
						db	"| 7) Display Even Values In Array               |  8) Display Odd Values In Array                |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10
						db	"| 9) Clear Array Contents                       |  10) Do Everything                             |", 10
						db  "|------------------------------------------------------------------------------------------------|", 10
						db	"|                                            0) Exit                                             |", 10
						db	"|------------------------------------------------------------------------------------------------|", 10, 0
ascii 			db	"|  ___    ___ ________  ________       ________  ________  ________  ________      ___    ___    |", 10
						db	"|  |\  \  /  /|\   __  \|\   ____\     |\   __  \|\   __  \|\   __  \|\   __  \    |\  \  /  /|  |", 10
						db	"|  \ \  \/  / | \  \|\  \ \  \___|     \ \  \|\  \ \  \|\  \ \  \|\  \ \  \|\  \   \ \  \/  / /  |", 10
						db	"|   \ \    / / \ \   __  \ \  \____     \ \   __  \ \   _  _\ \   _  _\ \   __  \   \ \    / /   |", 10
						db	"|    /     \/   \ \  \|\  \ \  ___  \    \ \  \ \  \ \  \\  \\ \  \\  \\ \  \ \  \   \/  /  /    |", 10
						db	"|   /  /\   \    \ \_______\ \_______\    \ \__\ \__\ \__\\ _\\ \__\\ _\\ \__\ \__\__/  / /      |", 10
						db	"|  /__/ /\ __\    \|_______|\|_______|     \|__|\|__|\|__|\|__|\|__|\|__|\|__|\|__|\___/ /       |", 10
						db	"|  |__|/ \|__|                           By Juan Palos                            \|___|/        |", 10, 0
