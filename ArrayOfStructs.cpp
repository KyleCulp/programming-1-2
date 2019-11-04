#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Imitating JSON here with arrays
string PersonData[11][5] = {
	{ 
		"Kyle",
		"Culp",
		"Male",
		"20",
		"76 inches"
	},{ 
		"Chris",
		"Culp",
		"Male",
		"28",
		"75 inches"
	},{ 
		"Bobert",
		"Male",
		"25",
		"56 inches"
	},{ 
		"Rick",
		"Frazier",
		"Male",
		"23",
		"70 inches"
	},{ 
		"Hillary",
		"Clinton",
		"Female",
		"72 ",
		"64 inches"
	},{ 
		"Donald",
		"Trump",
		"Male",
		"20",
		"76 inches"
	},{ 
		"Bobbie",
		"Owens",
		"Female",
		"50",
		"76 inches"
	},{ 
		"Jamie",
		"Griffin",
		"Female",
		"20",
		"66 inches"
	},{ 
		"Donald",
		"Trump",
		"Male",
		"20",
		"76 inches"
	},{ 
		"Donald",
		"Trump",
		"Male",
		"20",
		"76 inches"
	},{ 
		"Donald",
		"Trump",
		"Male",
		"20",
		"76 inches"
	},
};



struct Person {
	string first_name;
	string last_name;
	string gender;
	string age;
	string height;
} first_name, last_name, gender, age, height;

// Global Array of Structs
Person People[11];




int main () {


	return 0;
}

void printmovie (movies_t movie) {
}
