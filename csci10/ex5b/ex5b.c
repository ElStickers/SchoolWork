// Exercise 5b - data viewer
// ex5b.c

#include <stdio.h>

void display(unsigned int i, unsigned int value) {
  printf("Value #%u\n", i);
  printf("base-10 -> %u\n", value);
  printf("base-16 -> 0x%08x\n", value);

  printf("base-2  -> 0b");
  for(unsigned int i=0; i<32; i++) {


  }
  printf("\n\n");
}

int main(void) {

  //printf("sizeof(unsigned int) = %lu\n\n", sizeof(unsigned int));

  printf("Welcome to the data viewer.\n");

  while(1) {

      // prompt for and read four inputs
      

      display(1, input1);
      display(2, input2);
      display(3, input3);
      display(4, input4);

      printf("\nGo again [y/n]? ");
      char answer;
      scanf(" %c", &answer);
      if (answer == 'n' || answer == 'N') {
        break;
      }
  }

  return 0;
}
