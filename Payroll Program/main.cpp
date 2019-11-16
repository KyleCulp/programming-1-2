#if __INCLUDE_LEVEL__ < 1

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "grossPay.h"
#include "insuranceCost.h"
#include "federalTax.h"

#endif

using namespace std;


/*
* Author: Kyle Culp
* Assignment: Sort an Array of Structs
* Due: November 18th, 2019
* Description: 
*/


// Test if Files Exist
bool testFile() {
	ifstream payRoll("payroll.fil"); 
	if(!payRoll) {
		return false;
	}

	return true;
}

// External Functions
double grossPay(double rate, double hours);
double insuranceCost(char inscode);
double federalTaxCost(double PYE);

struct Person {
	string name;
	double rate;
	double hours;
	double inscode;
	double socialTax;
	double stateTax;
	double fedTax;
	double net;
} name, hours, inscode, socialTax, stateTax, fedTax, net;

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
	cout << setw(2) << setprecision(2) << fixed;
	cout << setw(16) << "NAME";
	cout << setw(8) << "RATE";
	cout << setw(8) << "HOURS";
	cout << setw(8) << "INS";
	cout << setw(8) << "SOC";
	cout << setw(8) << "STATE";
	cout << setw(10) << "FED";
	cout << setw(10) << "NET";
	cout << setw(1) << "\n";
	// New Line
	cout << setw(40) << "";
	cout << setw(8) << "SEC";
	cout << setw(8) << "TAX";
	cout << setw(10) << "TAX";
	cout << setw(1) << "\n";
	cout << setw(1) << "\n";
}


void printPeople(Person People[], int peopleSize) {
	for(int i=0; i < peopleSize; i++) {
		cout << setw(16) << People[i].name;
		cout << setw(4) << People[i].rate; // Unsure why it needs to be 4
		cout << setw(8) << People[i].hours;
		cout << setw(8) << People[i].inscode;
		cout << setw(8) << People[i].socialTax;
		cout << setw(8) << People[i].stateTax;
		cout << setw(10) << People[i].fedTax;
		cout << setw(10) << People[i].net;
		cout << setw(1) << "\n";
	}
}

int main () {
	// Initial File Check
	bool payRollExist = testFile();
	if(!payRollExist) {
		cout << "Please verify that payroll.fil exist";
		return 0;
	}

	// Declare Variables
    char cname[20];
    double rate, hours;
    char inscode;
	int loopTracker = 0;

	// Setup Functions
	printHeading();
	int totalPeople = getTotalPeople();
	Person People[totalPeople];

    ifstream payRoll("payroll.fil"); // open the input file
    while (payRoll.get(cname, 21)) {  // read in 20 chars from the input file
        string name = cname;
		payRoll >> rate >> hours >> ws >> inscode >> ws;  // read the rest of the data

		double gross = grossPay(rate, hours);
		double insCost = insuranceCost(inscode);
		double socialCost = gross * 0.07;
		double stateTax = gross * 0.03;
		double PYE = gross * 52;
		double fedTax = federalTaxCost(PYE);
		double netPay = gross - insCost - socialCost - stateTax - fedTax;

		// Declare person
		Person person;

		person.name = name;
		person.rate = rate;
		person.hours = hours;
		person.inscode = insCost;
		person.socialTax = socialCost;
		person.stateTax = stateTax;
		person.fedTax = fedTax;
		person.net = netPay;

		People[loopTracker] = person;
		loopTracker++;
	}

	printPeople(People, loopTracker);

    payRoll.close();  // close the input file
    return 0;
  }
