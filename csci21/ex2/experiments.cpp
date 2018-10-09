#include "NumberList.h"

#include <functional>
#include <iostream>
using std::cout;
using std::endl;
using std::function;

int main() {
  NumberList myList;

  if (myList.load("numbers.txt") == true) {
    cout << "Numbers loaded." << endl << endl;

    cout << "Numbers divisible by 100" << endl;
    function<bool (int)> evens = [](int n) { return n % 100 == 0; };
    cout << myList.filter(evens) << endl;

    cout << endl << "Numbers less than -990" << endl;
    function<bool (int)> tinies = [](int n) { return n < -990; };
    cout << myList.filter(tinies) << endl;

    cout << endl << "Numbers greater than 990" << endl;
    function<bool (int)> biggies = [](int n) { return n > 990; };
    cout << myList.filter(biggies) << endl;
  }
  return 0;
}
