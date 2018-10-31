//Author:       Juan Palos
//FileName:     project3.cpp
//Description:
#include "driver.h"
int main()  {
  Driver temp;
  temp.hello();
  cout << "Enter the file name you would like to open." << endl;
  string filename;
  cin >> filename;
  temp.grabFile(filename);
  return 0;
}
