// Exercise 9 -- Singly-linked list class
// SList.cpp

#include "SList.h"

/*
 * Default constructor.
 * Initializes head to nullptr, size to 0.
 */
SList::SList () {
  head = nullptr;
  size = 0;
}

/*
 * Create a new Node to contain value and insert the Node
 * at the head of this SList. Increases the size by 1.
 */
void SList::pushFront (int value) {
  Node* n1 = nullptr;
  n1 = new Node(value);
  size++;
  if(size > 1)  {
    n1->next = head;
  }
  head = n1;
}

/*
 * Return the value stored in the head Node.
 * @return the value in the head Node
 * @throw std::logic_error("EMPTY LIST") when list is empty
 */
int SList::front () noexcept(false) {
  int temp;
  if(size > 0) {
    temp = head->value;
  }
  else if(size == 0)  {
    throw std::logic_error("EMPTY LIST");
  }
  return temp;
}

/*
 * Return the size (number of Nodes in) of this SList.
 * @return the size of this SList
 */
unsigned int SList::getSize () const  {
  return size;
}

/*
 * Check to see if this SList is empty.
 * @return true if this SList is empty, else false
 */
bool SList::empty () const  {
  bool empty;
  if(size == 0) {
    empty = true;
  }
  else if (size > 0) {
    empty = false;
  }
  return empty;
}

/*
 * Return a string representation of this SList.
 * Displays the values (starting from head) of each
 * node in the list, separated by comma.
 *
 * EXAMPLE: "13,-1,0,99,-47"
 *
 * @return a string representation of this SList
 */
string SList::toString () const  {
  Node* n1 = head;
  ostringstream oss;
  int temp = size;
  if(n1 == nullptr)  {
    return oss.str();
  }
  while(n1 != nullptr)  {
    oss << n1->value;
    if(temp != 1) {
      oss << ",";
    }
    n1 = n1->next;
    temp--;
  }
  return oss.str();
}
