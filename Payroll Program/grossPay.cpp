#include "grossPay.h"

// Author: Kyle Culp
// File: grossPay.cpp

double grossPay(double rate, double hours) {
	if(hours > 40) {
		double overtimeHours = hours - 40;
		// Multiply rate by 40
		return (40 * rate) + (overtimeHours * (2 * rate));
	}

	return rate * hours;
}
