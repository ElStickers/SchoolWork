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
        oss << drive.runCommands(inputString) << endl;
      }
    }
  } else {
    throw int(2);
  }
  return oss.str();
}

string Driver::runCommands(string inputString)  {
  if(inputString.size() == 1) {
    return inputString;
  } else  {
    return inputString;
  }
}
