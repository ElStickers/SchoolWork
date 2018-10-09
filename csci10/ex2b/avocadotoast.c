#include <stdio.h>

int main() 
{
	char fruit[100];
	
	printf("What is your favorite fruit? ");
	scanf("%s", fruit);
	
	char answer;
	printf("Are you sure (y/n)?");
	scanf(" %c", &answer);
	
	if(answer == 'N' || answer == 'n')
	{
		printf("What is your favorite fruit? ");
		scanf("%s", fruit);
	}
	
	printf("\n");
	printf("%s is not my favorite.\n", fruit);
	
	return 0;
}