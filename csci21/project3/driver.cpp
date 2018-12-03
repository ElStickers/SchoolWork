//Author  :        Juan Palos

#include "driver.h"
//#include "DLList.hpp"

template <class T>
void Driver::argCheck(int argc)  {
  if(argc == 1)  {
    throw int(1);
  } else if (argc >= 3) {
    throw int(3);
  }
}

void Driver::grabFile(string filename, T *&list) {
  Driver drive;
  ifstream inputfile(filename);
  string inputString;
  if(inputfile.is_open()) {
    while(getline(inputfile, inputString)) {
      if(inputString.find('#') != std::string::npos)  {
        inputString.clear();
      } else  {
        drive.runCommands(inputString, list);
      }
    }
  } else {
    throw int(2);
  }
  inputfile.close();
}

void Driver::runCommands(string inputString, T *&list)  {
  istringstream iss(inputString);
  char command;
  int number;
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
        cout << "MUST CREAT LIST INSTANCE" << endl;
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
      } else {
        list = new T;
        cout << "LIST CREATED" << endl;
      }
      break;
    }
    case 'D': {
        list->kill(list);
        cout << "LIST DELETED" << endl;
      break;
    }
    case 'E': {
      if (list == nullptr) {
        cout << "MUST CREATE LIST INSTANCE" << endl;
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        list->removeAll(number);
        cout << "VALUE " << number << " ELIMINATED" << endl;
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
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
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
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        list->insert(number);
        cout << "INSERTED " << number << endl;
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
      } else if(list->empty()) {
        cout << "LIST EMPTY" << endl;
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
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        if (list->removeFirst(number) == true) {
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
      } else if (list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        list->clear();
        cout << "LIST CLEARED" << endl;
      }
      break;
    }
    case 'Z': {
      if(list == nullptr) {
        cout << "MUST CREAT LIST INSTANCE" << endl;
      } else if(list->empty()) {
        cout << "LIST EMPTY" << endl;
      } else {
        cout << "VALUE " << list->tailVal() << " AT TAIL" << endl;
      }
      break;
    }
  }
}
