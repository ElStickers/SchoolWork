#include "dlist.h"

//void processCommandWithValue(char cmd, unsigned int value, DList*&list)

void processCommand(char cmd, DList*& list)  {
  switch (cmd) {
    case 'C': {
      if(list != nullptr) {
        delete list;
      }
      list = new list;
      //cout << "LIST CREATED"
      break;
    }
  }
}

void processFile(string filename, DList*& list) {
  ifstream fin(filename);
  if(fin.open())  {
    string nextCommand;
    while (getline(fin, nextCommand)) {
      processCommand(nextCommand[0], list);
    }
    fin.close();
    
  }
}

int main()  {
  DList* list = nullptr;
}
