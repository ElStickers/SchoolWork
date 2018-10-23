// Exercise 10 -- Singly-linked list class
// SList.cpp

#include "SList.h"

SList::~SList() {
  clear();
}

bool SList::empty() const {
  return (head == nullptr);
}

void SList::clear()  {
  while(!empty()) {
    popFront();
  }
}
