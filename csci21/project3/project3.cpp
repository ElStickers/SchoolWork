//Author:       Juan Palos
//FileName:     project3.cpp
//Description:
#include "driver.h"
//#include "DList.hpp"
int main(int argc, char const *argv[]) {
  try {
    int argCount = argc;
    vector<string> argVec;
    for(int i = 0; i < argc; i++)  {
      argVec.push_back(argv[i]);
    }
    Driver temp;
    temp.hello(argCount, argVec);
    string filename = argVec[1];
    cout << temp.grabFile(filename);
  } catch (const int& error)  {
    if (error == 1)  {
      cout << "Error[1]: No command line argument given." << endl;
      return 0;
    } else if (error == 2) {
      cout << "Error[2]: File not found." << endl;
    }
  }
  return 0;
}
