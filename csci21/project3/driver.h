//Author:       Juan Palos
#pragma once
#include "DLList.hpp"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
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

template <class T>
class Driver  {
public:
  void argCheck(int argc);
  void grabFile(string filename, T *&list);
  void runCommands(string inputString, T *&list);
private:
};
