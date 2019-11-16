#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "grossPay.h"
#include "insuranceCost.h"
using namespace std;

/*
* Author: Kyle Culp
* Assignment: Sort an Array of Structs
* Due: November 18th, 2019
* Description: 
*/


struct Person {
	string name;
	double rate;
	double hours;
	double inscode;
	double socSEC;
	double stateTax;
	double fedTax;
	double net;
} name, hours, inscode, socSEC, stateTax, fedTax, net;


int getTotalPeople() {
    ifstream payRoll("payroll.fil"); 
	int totalPeople = 0;
    string line;

	// Get amount of people in file
	while (getline(payRoll, line)) {
		totalPeople++;
	}
	payRoll.close();

	return totalPeople;
}

void printHeading() {
	cout << setprecision(2) << fixed;
	cout << setw(1) << "\n";
	cout << setw(16) << "NAME";
	cout << setw(8) << "RATE";
	cout << setw(8) << "HOURS";
	cout << setw(8) << "INS";
	cout << setw(8) << "SOC";
	cout << setw(8) << "STATE";
	cout << setw(8) << "FED";
	cout << setw(8) << "NET";
	cout << setw(1) << "\n";
	cout << setw(40) << "";
	cout << setw(8) << "SEC";
	cout << setw(8) << "TAX";
	cout << setw(8) << "TAX";
	cout << setw(1) << "\n";
	cout << setw(1) << "\n";
}

void printTable(Person People[]) {
	for(int i=0; i < ; i++) {
		cout << setw(16) << People[i].name;
		cout << setw(8) << "RATE";
		cout << setw(8) << "HOURS";
		cout << setw(8) << "INS";
		cout << setw(8) << "SOC";
		cout << setw(8) << "STATE";
		cout << setw(8) << "FED";
		cout << setw(8) << "NET";
	}
}



double grossPay(double rate, double hours);
double insuranceCost(char inscode);

int main () {
	// Declare Variables
    char cname[20];
    double rate, hours;
    char inscode;
	int loopTracker = 0;

	// Setup Functions
	printHeading();
	int totalPeople = getTotalPeople();
	Person People[totalPeople + 1];

    ifstream payRoll("payroll.fil"); // open the input file
    while (payRoll.get(cname, 21)) {  // read in 20 chars from the input file
        string name = cname;
		payRoll >> rate >> hours >> ws >> inscode >> ws;  // read the rest of the data

		double gross = grossPay(rate, hours);
		double insCost = insuranceCost(inscode);

		// Declare person
		Person person;

		person.name = name;
		person.rate = rate;
		person.hours = hours;
		person.inscode = insCost;

		People[loopTracker] = person;
		loopTracker++;
      } 
    payRoll.close();  // close the input file
    return 0;
  }
