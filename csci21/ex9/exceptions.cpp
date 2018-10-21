#include <array>
#include <ctime>
#include <iostream>
#include <string>

using std::array;
using std::cout;
using std::cin;
using std::string;

void printArray(const array<int, 10>& numbers)

void populateArray(array<int, 10>& numbers) {
  for(int& i : numbers)  {
    i = rand() % 101;
    if(rand() % 2 == 0) {
      i *= -1
    }
  }
}


int int main() {
  srand(time(0));

  array<int, 10> numbers;

  populateArray(numbers);

  return 0;
}
