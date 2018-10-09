#include "NumberList.h"

#include <ctime>
#include <iostream>
#include <string>
using std::cout;
using std::endl;

void showElapsedTime(string label, clock_t start, clock_t stop)
{
  float secs = (float)(stop - start) / CLOCKS_PER_SEC; // SECS
  clock_t ticks = stop - start; // CLOCK TICKS

  cout << label << ": " << ticks << " ticks, "
       << secs << " seconds to execute\n";
}

int main()
{

  return 0;
}
