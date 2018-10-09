// Exercise 3b - comparing numbers
// ex3b.c

#include <stdio.h>

int main(void) {

  printf("Welcome to my number comparing program.\n");

  while(1) {

    // prompts and inputs
	unsigned int choice1;
	do
	{
		printf("Please Enter a number between 1 and 50.\n");
		scanf(" %u", &choice1);
		if(choice1 < 2 || choice1 > 50)
		{
			printf("Please make sure your number is between 1 and 50.\n\n");
		}
		
	}while(choice1 < 2 || choice1 > 50);
	
	unsigned int choice2;
	do
	{
		printf("Please Enter another number between 1 and 50.\n");
		scanf(" %u", &choice2);
		if(choice2 < 2 || choice2 > 50)
		{
			printf("Please make sure your number is between 1 and 50.\n\n");
		}
	}while(choice2 < 2 || choice2 > 50);

    // comparisons and output of results
	if(choice1 > choice2)
	{
		printf("The first number %u is greater than the second number %u.\n", choice1, choice2);
	}
	else if(choice2 > choice1)
	{
		printf("The second number %u is greater than the first number %u.\n", choice2, choice1);
	}
	else
	{
		printf("The first and second number are the same.\n");	
	}

    printf("Go again [y/n]? ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'n' || answer == 'N') {
      break;
    }
  }

  return 0;
}
