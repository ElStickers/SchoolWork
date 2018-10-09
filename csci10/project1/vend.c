//project name:	project 1 - vending machine
//file name: 	vendmach.c
//programmer: 	juan palos

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int stck_chk(unsigned int cnt);

struct items	{
	char name[100];
	float price;
	unsigned int stock;
};

int main(void)	{
	struct items item[5];
	
	strcpy(item[0].name, "Pepsi");
	item[0].price = 2;
	item[0].stock = 3;
	
	strcpy(item[1].name, "SmartWater");
	item[1].price = 2;
	item[1].stock = 7;
	
	strcpy(item[2].name, "Pirates Booty");
	item[2].price = 3;
	item[2].stock = 5;
	
	strcpy(item[3].name, "Flaming Hot Cheetos");
	item[3].price = 3;
	item[3].stock = 0;
	
	strcpy(item[4].name, "Rasberry Pi");
	item[4].price = 40;
	item[4].stock = 1;
	
	printf("==================Butte College Vending===================\n\n");
	printf("**********************Item Selection**********************");
	printf("\n\n");
	bool done = false;
	while(done == false)	{
		for(int i = 0; i < 5; i++)	{
			printf("==========================================================\n");
			printf("|| %d) %s: ||", i + 1 , item[i].name);
			printf(" Price: $%.2f || ", item[i].price);
			printf(" Stock: %u", item[i].stock);
			if(i == 0)	{
				printf("               ||\n");
			}
			else if(i == 1)	{
				printf("          ||\n");
			}
			else if(i == 2)	{
				printf("       ||\n");
			}
			else if(i == 3)	{
				printf(" ||\n");
			}
			else	{
				printf("        ||\n");
				printf("==========================================================\n");
				printf("==========================================================\n");
			}
		}
		printf("What would you like to purchase? || ");
		printf("Press '6' to exit.  ||\n");
		printf("==========================================================\n");
		int choice;
		scanf("%d", &choice);
		printf("\n");
		//system("cls");
		//unsigned int cnt = 0;
		if(choice <= 5)	{
			if(item[choice - 1].stock > 0)	{
				printf("==========================================================\n");
				printf("You have selected item: %d) %s.\n", choice, item[choice - 1].name);
				printf("Your total is: $%.2f\n", item[choice - 1].price);
				printf("Please 'Instert' your payment.(Type in amount you owe.)\n");
				float pymnt;
				scanf("%f", &pymnt);
				if(pymnt == item[choice - 1].price)	{
					item[choice - 1].stock--;
					char choice1 = 's';
					printf("Dispensing item...\n");
					while(choice1 != 'y' || choice1 != 'Y' || choice1 != 'n' || choice1 != 'N')	{
						printf("Would you like to purchase additional items?(y/n)\n");
						scanf(" %c", &choice1);
						if(choice1 == 'n' || choice1 == 'N')	{
							printf("Thank You! Goodbye.");
							done = true;
							break;
						}
						else if(choice1 == 'y' || choice1 == 'Y')	{
							done = false;
							break;
						}
						else	{
							printf("Sorry that input was invalid.\n");
						}
					}
					
				}
				else if(pymnt > item[choice - 1].price)	{
					item[choice - 1].stock--;
					float change = pymnt - item[choice - 1].price;
					printf("Don't forget your change: $%.2f\n", change);
					char choice1 = 's';
					while(choice1 != 'y' || choice1 != 'Y' || choice1 != 'n' || choice1 != 'N')	{
						printf("Would you like to purchase additional items?(y/n)\n");
						scanf(" %c", &choice1);
						if(choice1 == 'n' || choice1 == 'N')	{
							printf("Thank You! Goodbye.");
							done = true;
							break;
						}
						else if(choice1 == 'y' || choice1 == 'Y')	{
							done = false;
							break;
						}
						else	{
							printf("Sorry that input was invalid.\n");
						}
					}
				}
				else	{
					float amntOwed = item[choice - 1].price - pymnt;
					printf("Sorry but you still owe: $%.2f\n", amntOwed);
					printf("Please press 'P' to pay your remaining balance or press 'E' to exit.\n");
					char input = 's';
					float pymnt2;
					scanf(" %c", &input);
					if(input == 'E' || input == 'e')	{
						printf("Goodbye!");
						return 1;
					}
					else if(input == 'P' || input == 'p')	{
						printf("Please enter your remaining balance: $%.2f\n", amntOwed);
						scanf("%f", &pymnt2);
						char choice1 = 's';
						if(pymnt2 == amntOwed)	{
							while(choice1 != 'y' || choice1 != 'Y' || choice1 != 'n' || choice1 != 'N')	{
								printf("Would you like to purchase additional items?(y/n)\n");
								scanf(" %c", &choice1);
								if(choice1 == 'n' || choice1 == 'N')	{
									printf("Thank You! Goodbye.");
									done = true;
									break;
								}
								else if(choice1 == 'y' || choice1 == 'Y')	{
									done = false;
									break;
								}
								else	{
									printf("Sorry that input was invalid.\n");
								}
							}
						}
					}
				}
			}
			else	{
				printf("Sorry, item: %d) %s,no longer in stock.\n", choice, item[choice - 1].name);
				char choice;
				while(choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N')	{
					printf("Would you like to purchase additional items?(y/n)\n");
					scanf(" %c", &choice);
					if(choice == 'n' || choice == 'N')	{
						printf("Sorry! Goodbye.");
						done = true;
						break;
					}
					else if(choice == 'y' || choice == 'Y')	{
						done = false;
						break;
					}
					else	{
						printf("Sorry that input was invalid.\n");
					}
				}
			}
		}
		else if(choice > 6)	{
			printf("Choice %u is invalid. ", choice);
			printf("Please try again.\n");
		}
		else if(choice == 6)	{
			printf("Goodbye!");
			done = true;
		}
		else	{
			printf("Sorry input was invalid.\n");
			printf("Please try again.\n");
		}
	}
	return 0;	
}