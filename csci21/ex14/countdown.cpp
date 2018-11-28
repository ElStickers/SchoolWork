void countdown (int start) {
  //stop case
  if(start >= 0){
    //operation
    cout << start << " ";
    //chop
    start--;
    //recursive call
    countdown(start);
  }
}

int factorial(int n){
  if(n == 1){
    return 1;
  } else {
    return n*factorial(n-1);
  }
}

//every function call produces a STACK FRAME
factorial(4);
//https://imgur.com/a/AcEMBAG


#include <iostream>
using namespace std;

int factorial(int n) {
  cout << "n: " << endl;
  if (n == 1){
    cout << ", return: 1" << endl;
    return 1;
  } else {
    int result = n * factorial(n -1)'
    cout << ", return: " << result << endl;
    return result;
  }
}

int main() {
  cout << "Final result: " << factorial(10) << endl;

  return 0;
}
