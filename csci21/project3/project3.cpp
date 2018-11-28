//Author:       Juan Palos
//FileName:     project3.cpp
//Description:
#include "driver.h"
//#include "DLList.hpp"

int main(int argc, char const *argv[]) {
  try {
    DLList *list = nullptr;
    int argCount = argc;
    vector<string> argVec;
    for(int i = 0; i < argc; i++)  {
      argVec.push_back(argv[i]);
    }
    Driver temp;
    temp.argCheck(argCount);
    string filename = argVec[1];
    temp.grabFile(filename, list);
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
