//Author:       Juan Palos
//FileName:     project3.cpp
//Description:

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

#include "DLList.hpp"

using std::cin;
using std::cout;
using std::exception;
using std::endl;
using std::ifstream;
using std::istringstream;;
using std::ostream;
using std::ostringstream;
using std::string;
using std::stringstream;
using std::vector;

void argCheck(int argc)  {
  if(argc == 1)  {
    throw int(1);
  } else if (argc >= 3) {
    throw int(3);
  }
}

template <class T>
void grabFile(string filename, T *&list) {
  ifstream inputfile(filename);
  string inputString;
  if(inputfile.is_open()) {
    while(getline(inputfile, inputString)) {
      if(inputString.find('#') != std::string::npos)  {
        inputString.clear();
      } else  {
        runCommands(inputString, list);
      }
    }
  } else {
    throw int(2);
  }
  inputfile.close();
}

template <class T>
void runCommands(string inputString, T *&list)  {
  istringstream iss(inputString);
  char command;
  int number = 0;
  string token;
  int counter = 0;
  stringstream ss;
  while(getline(iss, token, ' ')) {
    if(counter == 0)  {
      ss << token;
      ss >> command;
    } else if (counter == 1) {
      ss << token;
      ss >> number;
    } else {
      break;
    }
    counter++;
  }
  switch(toupper(command)) {
    case 'A': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
        break;
      } else if(list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        cout << "VALUE " << list->front() << " AT HEAD" << endl;
      }
      break;
    }
    case 'B': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        list->pushBack(number);
        cout << "VALUE " << number << " ADDED TO TAIL" << endl;
      }
      break;
    }
    case 'C': {
      if (list != nullptr)  {
        delete list;
        list = nullptr;
      }
        list = new T;
        cout << "LIST CREATED" << endl;
      break;
    }
    case 'D': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        list->kill(list);
        cout << "LIST DELETED" << endl;
      }
      break;
    }
    case 'E': {
      if (list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        if(list->findValue(number)) {
          list->removeAll(number);
          cout << "VALUE " << number << " ELIMINATED" << endl;
        } else {
          cout << "VALUE " << number << " NOT FOUND" << endl;
       }

      }
      break;
    }
    case 'F': {
      if (list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        list->pushFront(number);
        cout << "VALUE " << number << " ADDED TO HEAD" << endl;
      }
      break;
    }
    case 'G': {
      if (list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        if(list->findValue(number)) {
          cout << "VALUE " << number << " FOUND" << endl;
        } else {
          cout << "VALUE " << number << " NOT FOUND" << endl;
        }
      }
      break;
    }
    case 'I': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        list->insert(number);
        cout << "VALUE " << number << " INSERTED"<< endl;
      }
      break;
    }
    case 'K': {
      if (list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        list->popBack();
        cout << "REMOVED TAIL" << endl;
      }
      break;
    }
    case 'N': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        cout << "LIST SIZE IS " << list->getSize() << endl;
      }
      break;
    }
    case 'P': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else if(list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        cout << list->toString() << endl;
      }
      break;
    }
    case 'R': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        if(list->findValue(number)) {
          list->removeFirst(number);
          cout << "VALUE " << number << " REMOVED" << endl;
        } else {
          cout << "VALUE " << number << " NOT FOUND" << endl;
        }
      }
      break;
    }
    case 'T': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        list->popFront();
        cout << "REMOVED HEAD" << endl;
      }
      break;
    }
    case 'X': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else {
        list->clear();
        cout << "LIST CLEARED" << endl;
      }
      break;
    }
    case 'Z': {
      if(list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else if(list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        cout << "VALUE " << list->tailVal() << " AT TAIL" << endl;
      }
      break;
    }
  }
}

int main(int argc, char const *argv[]) {
  try {
    DLList<int> *list = nullptr;
    int argCount = argc;
    vector<string> argVec;
    for(int i = 0; i < argc; i++)  {
      argVec.push_back(argv[i]);
    }
    argCheck(argCount);
    string filename = argVec[1];
    grabFile(filename, list);
  } catch (const int& error)  {
    if (error == 1)  {
      cout << "Error[1]: No command line argument given." << endl;
    } else if (error == 2) {
      cout << "Error[404 ]: File not found." << endl;
    } else if (error ==3) {
      cout << "Error[3]: Too many arguments given." << endl;
    }
  }
  return 0;
}
