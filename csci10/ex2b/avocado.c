#include <stdio.h>

int main(void)
{
	printf("\tAvocado!\n");
	printf("\n");
	
	int lilNumber = -99;
	unsigned int bigNumber = 101;
	
	printf("Little number is %d.\n\n", lilNumber);
	
	printf("Big numbes is %u.\n\n", bigNumber);
	
	printf("big (%u) > lil (%d)?\n\n", bigNumber, lilNumber);
	
	//user inputs
	
	printf("Enter a negative number: ");
	scanf("%d", &lilNumber);
	
	printf("Enter a positive number: ");
	scanf("%u", &bigNumber);
	
	printf("You entered %d and %u.\n\n", lilNumber, bigNumber);
	
	return 0;
}