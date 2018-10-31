//Author  :        Juan Palos

#include "driver.h"

void Driver::hello()  {
  cout << "hello" << endl;
}

void Driver::grabFile(string filename) {
  cout << "Grabing file..." << endl;
  ifstream inputfile(filename);
  string inputString;
  if(inputfile.is_open()) {
    while(getline(inputfile, inputString)) {
      if(inputString.find('#') != std::string::npos)  {
        inputString.clear();
      } else  {
        cout << inputString << endl;
      }
    }
  } else  {
    cout << "Error: " << filename << "File not found." << endl;
  }
}
