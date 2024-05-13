
#include <iostream>

using namespace std;                      // compiler error: all the cout and cin need std:: , so I add this code.

int main(void) {
  int num;
  // bool factor_found = true;
  bool factor_found = false;              // logical error: factor_found should be initialized to false.

  cout << "Enter Number:\n";               
  cin >> num;

  // logical error: 0 is not negative.
  // if (num == 0) {
  //   cout << num << " is negative\n";     
  //   return 0;
  // }

  // if (num == 0 && num == 1) { 
  if (num == 0 || num == 1) {         // logical error: this should use ||, because both 0 and 1 are not prime or composite.
    cout << num << " is not prime or composite\n";
    return 0;
  }
 
  // for (int i = 0; i < num; i--) {
  for (int i = 2; i < num; i++) {     // logical error: this loop should use i++ and i should be initialized to 2.
    if (num % i == 0) {
      factor_found = true;
      break;
    }
  }

  if (factor_found) {
    cout << num << " is a composite number\n";
  } else {
    cout << num << " is a prime number\n";
  }
}


// most important logical fixes
// 1. [line 9] bool factor_found = true; -> bool factor_found = false;
// 2. [line 14] delete
// 3. [line 21] if (num == 0 && num == 1) -> if (num == 0 || num == 1)
// 4. [line 27] for (int i = 0; i < num; i--) -> for (int i = 2; i < num; i++)


// most important compiler fixes
// 1. [line 4] add using namespace std; 

