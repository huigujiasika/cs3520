/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'


*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments) at the end of file.

#include <iostream>
using namespace std;

int main() {
  
  // int limit = 0, even_product = 0, odd_product = 0, sum; 
  int limit = 10, even_product = 1, odd_product = 1, sum;   // logical error: limit should be 10, 
                                                           //                even_product and odd_product should be initialized to 1.
  char c;

  cout << "The value of limit is " << limit << endl;

  // for (int i = 0; i <= limit; ++i) {
  for (int i = 1; i <= limit; ++i) {        // logical error: i should be initialized to 1.
    // if (i % 2 == 1) { 
    if (i % 2 == 0) {                       // logical error: even should use i % 2 == 0.
      even_product *= i;                   
    } else {
      odd_product *= i;
    }
  }
  sum = even_product + odd_product;
  cout << "The Sum = " << sum << "\n";

  for (c = 'Z'; c >= 'A'; c -= 2) {   
    // cout << i << " ";     
    cout << c << " ";                      // compiler error: i hasn't been initialized.
  }                                        // logical error: we should print c here.
  cout << endl;                   

  return 0;
}

// most important logical fixes
// 1. [line 21] limit = 0 -> limit = 10.
// 2. [line 21] even_product = 0, odd_product = 0 -> even_product = 1, odd_product = 1.
// 3. [line 28] int i = 0 -> int i = 1.
// 4. [line 30] i % 2 == 1 -> i % 2 == 0.
// 5. [line 41] cout << i << " ";  -> cout << c << " ";

// most important compiler fixes
// 1. [line 41] cout << i << " ";  -> cout << c << " ";