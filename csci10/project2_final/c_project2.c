//project name:	project 2 - vending machine
//file name: 	vendmach.c
//programmer: 	juan palos

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int stck_chk(unsigned int cnt);

struct items	{
	char name[100];
	unsigned int price;
	unsigned int stock;
};

struct items initItem(struct items b, char* n, float p, unsigned int s) {
  strcpy(b.name, n);
  b.price = p;
  b.stock = s;
  return b;
}

void displayMenu(struct items item[], int i) {
  printf("==========================================================\n");
  printf("|| %d) %-*s||", i + 1 , 20, item[i].name);
  printf(" Price: $%-*u|| ", 7, item[i].price);
  printf(" Stock: %-*u", 2, item[i].stock);
  printf("|\n");
}

void giveChange(int change)  {
  unsigned int quarters;
  unsigned int dimes;
  unsigned int nickels;
  unsigned int pennies;

  quarters = (change / 25);
  dimes = (change % 25) / 10;
  nickels = ((change % 25) % 10) / 5;
  pennies = (((change % 25) % 10 ) % 5);

  printf("Here is your change: \n");
  printf("Quarters: %u\n", quarters);
  printf("Dimes: %u\n", dimes);
  printf("Nickels: %u\n", nickels);
  printf("Pennies: %u\n", pennies);
  printf("Total Change: %u\n", change);
}

int main(void)	{
  struct items i1;
	struct items item[5];

  item[0] = initItem(i1, "Pepsi", 2, 3);
  item[1] = initItem(i1, "SmartWater", 3, 7);
  item[2] = initItem(i1, "Pirates Booty", 5, 5);
  item[3] = initItem(i1, "Flaming Hot Cheetos", 22, 0);
  item[4] = initItem (i1, "Rasberry Pi", 40, 1)  ;

	bool done = false;
	while(done == false)	{
    system("CLS");
    printf("==================Butte College Vending===================\n\n");
  	printf("**********************Item Selection**********************");
  	printf("\n\n");
		for(int i = 0 ; i < 5; i++)	{
      displayMenu(item, i);
		}
    printf("==========================================================\n");
		printf("What would you like to purchase? || ");
		printf("Press '0' to exit.  ||\n");
		printf("==========================================================\n");
    printf("Selection: ");
		int choice;
		scanf("%d", &choice);
		printf("\n");
		//system("cls");
		//unsigned int cnt = 0;
		if(choice <= 5 && choice != 0)	{
      if(item[choice - 1].stock > 0)	{
				printf("==========================================================\n");
				printf("You have selected item: %d) %s.\n", choice, item[choice - 1].name);
				printf("Your total is: $%u\n", item[choice - 1].price);
				printf("Please 'Instert' your payment.(Type in amount you owe.)\n");
				unsigned int pymnt;
				scanf("%u", &pymnt);
				if(pymnt >= item[choice - 1].price)	{
					item[choice - 1].stock--;
					char choice1 = 's';
					printf("Dispensing item...\n");
          pymnt = pymnt - item[choice - 1].price;
          giveChange(pymnt);
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
      else if(item[choice - 1].stock == 0){
        printf("Sorry we're out of that item. Would you like to select something else? (y/n)\n");
        char loop = 's';
        while(loop != 'y' || loop != 'Y' || loop != 'n' || loop != 'N') {
          scanf(" %c", &loop);
          if(loop == 'y' || loop == 'Y'){
            done = false;
            break;
          }
        }
      }
    }
		else if(choice > 6)	{
			printf("Choice %u is invalid. ", choice);
			printf("Please try again.\n");
		}
		else if(choice == 0)	{
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
