#if __INCLUDE_LEVEL__ < 1

#include <string>
#include <iostream>
#include "insuranceCost.h"
using namespace std;

#endif

// Author: Kyle Culp
// File: insuranceCost.cpp

// Would use a switch here, but messing with the ints seemed 
// counter productive compared to 3 if statements
double insuranceCost(char inscode) {
	if(inscode == 'N') {
		return 0;
	}
	if(inscode == 'S') {
		return 9.50;
	}
	if(inscode == 'F') {
		return 24.75;
	}
	// default return 0 
	return 0;
}
