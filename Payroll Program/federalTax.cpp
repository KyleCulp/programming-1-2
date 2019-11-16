#include "federalTax.h"

// Author: Kyle Culp
// File: federalTax.cpp

double federalTaxCost(double PYE) {

	if(PYE < 8000) {
		return 0;
	}
	if(8000 <= PYE && PYE < 20000) {
		return ((PYE - 8000) * 0.15) / 52;
	}
	if(PYE >= 20000) {
		double middlePay = ((20000 - 8000) * 0.15);
		return (middlePay + ((PYE - 20000) * 0.28)) / 52;
	}

	// Default return 0
	return 0;
} 
