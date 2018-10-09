//class stuff
#include <stdlib.h>

unsigned int getNumber()	{
	unsigned int number;
	while(1)	{
		printf("Enter number (1-1000): ");
		scanf("%u", &number);
		if(number >= 1 && number <= 1000)	{
			return number;
		}
	}
	return 0;
}

int main()	{
	
	unsigned int n1 = getNumber();
	unsigned int n2 = getNumber();
	
	printf("%u + %u = %u\n", n1, n2, n1 + n2);
	
	return 0;
}