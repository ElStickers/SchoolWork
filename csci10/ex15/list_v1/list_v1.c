#include <stdio.h>

struct Node {
  int contents;
  struct Node* link;
};

// this is a read (C'R'UD) operation
void printList(struct Node* head) {
  if (head) {
    printf("Contents: ");
    while(head) {
      printf("%i ", head->contents);
      head = head->link;
    }
    printf("\n");
  } else {
    printf("The list is empty.\n");
  }
}

int main()  {
  // CRUD
  //
  // Create
  // Read
  // Update
  // Delete

  struct Node* head = 0;

  printList(head);

  struct Node nodie;
  nodie.contents = 99;
  nodie.link = 0;

  head = &nodie;

  printList(head);

  struct Node nodie_jr;
  nodie_jr.contents = 32;
  nodie_jr.link = 0;

  nodie.link = &nodie_jr;

  printList(head);

  return 0;
}
