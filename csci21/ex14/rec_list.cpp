#include <iostream>
using namespace std;

struct Node {
int contents;
Node* next;
};

void push(Node* n, int i) {
  Node* nn = new node;
  nn->contents = i;
  nn->next = n;
  n = nn;
}

void free(Node*& n) {
  if(n) {
    free(n->next);
    cout << "freeing " << n->contents << endl;
    delete n;
  }
}

void print(Node* n) {
  if(n == nullptr){
    //do nothing
  } else {
    cout << n->contents << endl;
    print(n->next);
  }
}

int main() {
  Node* h = nullptr;
  for (int i = 50; i > 0 , i -= 10) {
      push(h, i);
  }
  print(h);
  return 0;
}
