//Author  :        Juan Palos

#include "driver.h"

void Driver::hello(int argc, vector<string> argVec)  {
  if(argc < 2)  {
    throw int(1);
  } else {
    cout << argVec[1] << endl;
  }
}

string Driver::grabFile(string filename) {
  Driver drive;
  cout << "Grabing file..." << filename << endl;
  ifstream inputfile(filename);
  string inputString;
  ostringstream oss;
  if(inputfile.is_open()) {
    while(getline(inputfile, inputString)) {
      if(inputString.find('#') != std::string::npos)  {
        inputString.clear();
      } else  {
        oss << drive.runCommands(inputString);
      }
    }
  } else {
    throw int(2);
  }
  return oss.str();
}

string Driver::runCommands(string inputString)  {
  istringstream iss(inputString);
  char command;
  unsigned int number;
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
  /*ostringstream oss;
  oss << "char " <<  command << " int " << number << endl;
  return oss.str(); */
  ostringstream oss;
  switch(toupper(command)) {
    case 'A': {
      oss << command << " : return contents of head node" << endl;
      break;
    }
    case 'B': {
      oss << command << " : add number to back of list. Number: " << number << endl;
      break;
    }
    case 'C': {
      oss << command << " : create dynamic list instance" << endl;
      break;
    }
    case 'D': {
      oss << command << " : delete the dynamic list instance and set to nullptr" << endl;
      break;
    }
    case 'E': {
      oss << command << " : eliminate all occurrences of number from the list. Number: " << number << endl;
      break;
    }
    case 'F': {
      oss << command << " : add number to front of list. Number: " << number << endl;
      break;
    }
    case 'G': {
      oss << command << " : get number from the list" << endl;
      break;
    }
    case 'I': {
      oss << command << " : insert number into list (sorted)" << endl;
      break;
    }
    case 'K': {
      oss << command << " : pop the tail node" << endl;
      break;
    }
    case 'N': {
      oss << command << " : return the size of the list" << endl;
      break;
    }
    case 'P': {
      oss << command << " : print all items in the list" << endl;
      break;
    }
    case 'R': {
      oss << command << " : remove the first occurrence of number from the list. Number: " << number << endl;
      break;
    }
    case 'T': {
      oss << command << " : pop the head node" << endl;
      break;
    }
    case 'X': {
      oss << command << " : clear the current list instance of contents" << endl;
      break;
    }
    case 'Z': {
      oss << command << " : return contents of tail node" << endl;
      break;
    }
  }
  return oss.str();
}
