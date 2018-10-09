// Exercise 2b - mad libs
// ex2b.c

#include <stdio.h>

int main(void) {

  printf("Welcome to my x86 assembly program.\n\n");

  printf("What is your name? ");
  char name[100];
  scanf("%s", name);
  printf("Nice to meet you, %s.\n\n", name);

  printf("How many years have you been at Butte College? ");
  int years;
  scanf("%d", &years);
  printf("You have been at Butte College for %u years? Awesome!\n", years);

  return 0;
}
