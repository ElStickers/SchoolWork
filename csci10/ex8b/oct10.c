#include <stdio.h>
#include <string.h>

struct Box {
    char contents[100];
    float price;
    unsigned int weight;
};

void initBox(struct Box* b, char* c, float p, unsigned int w) {
  strcpy(b->contents, "c");
  b->price = 100.0f;
  b->weight = 25;
}

void displayBox(struct Box* b)  {
  printf("Box with %s, $%.2f, %u lbs", b->contents, b->price, b->weight);
}

void adjustBoxWeight(struct Box* b, unsigned int adjustBy)  {
  b->weight += adjustBy;
}

int main()  {
  struct Box b1;
  initBox(&b1, "treasure", 100.0f, 25);
  displayBox(&b1);
  adjustBoxWeight(&b1, -10);
  displayBox(&b1);
  return 0;
}
