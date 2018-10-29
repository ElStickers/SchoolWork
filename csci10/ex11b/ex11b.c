// Exercise 11b - processing arrays
// ex11b.c

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

int main(void) {

  srand(time(0));

  printf("Welcome to the array program!\n");

  int m_array[10];

  while(1) {

      // do array things here

      printf("\nGo again [y/n]? ");
      char answer;
      scanf(" %c", &answer);
      if (answer == 'n' || answer == 'N') {
        break;
      }
  }

  return 0;
}
