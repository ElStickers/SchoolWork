//Author:       Juan Palos
#pragma once

#include <algorithm>
#include <array>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
using std::array;
using std::cin;
using std::cout;
using std::exception;
using std::endl;
using std::fixed;
using std::function;
using std::ifstream;
using std::istringstream;
using std::left;
using std::ostream;
using std::ostringstream;
using std::right;
using std::setfill;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::vector;

class Driver  {
public:
  void hello(int argc, vector<string> argVec);
  string grabFile(string filename);
  string runCommands(string inputString);

private:
};
