// Fig. 5.6: fig05_06.cpp
// Compound interest calculations with for.
#include <iostream>
#include <iomanip>
#include <cmath> // standard math library
using namespace std;

double calculateInterest(double principal, double rate, int years) {
    return principal * pow(1.0 + rate / 100.0, years);
}

int main() {

    const double principal = 11.00;  // initial amount before interest
    const int years = 398;

    // display headers
    cout << "Interest Rates (%)" << setw( 25) << "Amount on deposit" << setw( 25 ) << "S&P500 Return" << setw( 25 ) << "NASDAQ" << endl;
    // set floating-point number format
    cout << fixed << setprecision( 2 );

    double sAndP500 = calculateInterest(principal, 10.17, years);
    double nasdaq = calculateInterest(principal, 10.4, years);

    // calculate amount on deposit for 398 years of different rate
    for (double rate = 2.0; rate <= 12.0; rate += 0.5) {
        double amount = calculateInterest(principal, rate, years);
        cout << fixed << setprecision(2);
        cout << setw(12) << rate
             << setw(30) << amount
             << setw(30) << sAndP500
             << setw(30) << nasdaq
             << endl;
    } // end for 
} // end main


// When the interest rate is above 5%, the interest rate on the deposit is much higher than the current value of the Mona Lisa painting.



