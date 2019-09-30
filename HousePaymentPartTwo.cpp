#include <iostream>
#include <math.h> 
#include <iomanip> 
using namespace std; 

/*
* Author: Kyle Culp
* Assignment: House Payment Part 2
*/

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
  double part6 = part5 / part4;
  return part6;
}

// quick function to handle yir -> mir, then multiply against remaining balance
double getMonthlyInterest(double remainingBalance, double yir) {
  return remainingBalance * (yir / 1200);
}

// Print first eight months of the payment plan to table
void printFirstEight(double principal, double yir, double years) {
  double monthlyPayment = calculate(principal, yir, years);
  double totalPaid, monthlyInterest, principalPaid, totalPrincipalPaid, remainingBalance = principal;

  // All numbers get cut off after 2 decimals, rounded up
  cout << setprecision(2) << fixed;

  for(int i=1; i<=8; i++) {
    totalPaid += monthlyPayment;
    monthlyInterest = getMonthlyInterest(remainingBalance, yir);
    principalPaid = monthlyPayment - monthlyInterest;
    totalPrincipalPaid += principalPaid;
    remainingBalance -= principalPaid;


    
    cout << setw(1) << "|";
    cout << setw(5) << i;
    cout<< setw(12) << monthlyPayment;
    cout << setw(12) << totalPaid; 
    cout << setw(12) << monthlyInterest; 
    cout << setw(12) << principalPaid;
    cout << setw(12) << totalPrincipalPaid;
    cout << setw(12) << remainingBalance;
    cout << setw(1) << " |\n";
  }
}

// Print last eight months of the payment plan to table
void printLastEight(double principal, double yir, double years) {
  double monthlyPayment = calculate(principal, yir, years);
  double totalPaid, monthlyInterest, principalPaid, totalPrincipalPaid, remainingBalance = principal;

  cout << setprecision(2) << fixed;
  
  // Catch these scoped variables up in time to 9 months before the payment plan is complete
  // Pretty cpu inefficient, but it gets the job done here
  for(int i=1; i<=(years * 12) - 8; i++) {
    totalPaid += monthlyPayment;
    monthlyInterest = getMonthlyInterest(remainingBalance, yir);
    principalPaid = monthlyPayment - monthlyInterest;
    totalPrincipalPaid += principalPaid;
    remainingBalance -= principalPaid;
  }


  // Same thing as printTopHalf's loop, except we're starting where the loop above ended
  for(int i=(years * 12) - 7; i<=years * 12; i++) {
    totalPaid += monthlyPayment;
    monthlyInterest = getMonthlyInterest(remainingBalance, yir);
    principalPaid = monthlyPayment - monthlyInterest;
    totalPrincipalPaid += principalPaid;
    remainingBalance -= principalPaid;
    
    cout << setw(1) << "|";
    cout << setw(5) << i;
    cout<< setw(12) << monthlyPayment;
    cout << setw(12) << totalPaid; 
    cout << setw(12) << monthlyInterest; 
    cout << setw(12) << principalPaid;
    cout << setw(12) << totalPrincipalPaid;
    cout << setw(12) << remainingBalance;
    cout << setw(1) << " |\n";
  }
}

void printTable(double principal, double yir, double years) {
  cout << setprecision(2) << fixed;
  double monthlyPayment = calculate(principal, yir, years);


  cout << " ------------------------------------------------------------------------------";
  cout << "\n|  Principal " << principal << "    Interest Rate " <<  yir << "     Years " << years << "     Payment " << monthlyPayment << " |";
  cout << "\n|                                                                              |";

  cout << "\n|  Month    Pay        Total       Monthly     Principal   Total    Reamining  |";
  cout << "\n|                       Paid       Interest       Paid    Principal   Balance  |";
  cout << "\n|                                                           Paid               |";

  cout << "\n|                                                                              |\n";
  printFirstEight(principal, yir, years);
  cout << "|    -         -           -             -           -         -          -    |\n";
  printLastEight(principal, yir, years);
  cout << " ------------------------------------------------------------------------------";
}

int main() {
  double principal, yir, years;

  cout << "Please enter the Principal: ";
  cin >> principal;
  cout << "Please enter the Yearly Interest Rate, in decimal format: ";
  cin >> yir;
  cout << "Please enter the loan length, in years: ";
  cin >> years;

  double monthlyPayment = calculate(principal, yir, years);


  printTable(principal, yir, years);
}
