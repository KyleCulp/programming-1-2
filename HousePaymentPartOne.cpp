#include <iostream>
#include <math.h> 
using namespace std; 

/*
* Author: Kyle Culp
* Assignment: House Payment Part 1
* Note: I hope importing math.h is allowed
*/

// mp = (p * mir) / 1 - (1/1+mir)^(12*y)
// mp = monthly payment
// p = principal
// mir = interest rate for 1 month
// y = year
// yir = interest rate for 1 year


double calculate(double principal, double yir, double years) {
  // Get monthly interest rate
  double mir = yir / 1200;

  // Exponent to send to pow function 
  double exponent = 12 * years;

  // cout << mir;

  double part1 = 1 + mir; 
  double part2 = 1 / part1;
  double part3 = pow(part2, exponent);
  double part4 = 1 - part3;
  double part5 = principal * mir;
  return part5 / part4;
}

int main() {
  double principal, yir, years;

  // cout << "House Payment Program";
  cout << "Please enter the Principal: ";
  cin >> principal;
  cout << "Please enter the Yearly Interest Rate, in decimal format: ";
  cin >> yir;
  cout << "Please enter the loan length, in years: ";
  cin >> years;

  double monthlyPayment = calculate(principal, yir, years);

  cout << "The monthly payment is: $" << monthlyPayment;
}
