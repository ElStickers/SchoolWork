//Author:   Juan Palos
//Date:     November 6th, 2018

template <class T>
classs List {
public:
  T front() {

  }
  void pushFront(T contents) {
    Node* n = new Node;
    n->contents = contents;
    n->next = nullptr;
    head = n;
  }

private:
  template <class T>
  struct Node {
    T contents;
    Node* next;
  } *head;
};
