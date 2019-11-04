#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

/*
* Author: Kyle Culp
* Assignment: Sort an Array of Structs
* Due: November 4th, 2019
* Description: Prints out 3 tables from an array of data. One table is unsorted, and the other two are sorted differently from each other.
*/


// Imitating JSON here with arrays
string Data[11][5] = {
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
		"Ronsley",
		"Male",
		"79",
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
		"66",
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
		"22",
		"66 inches"
	},{ 
		"Blake",
		"Adams",
		"Male",
		"20",
		"44 inches"
	},{ 
		"Barrack",
		"Obama",
		"Male",
		"64",
		"73 inches"
	},{ 
		"Bernie",
		"Sanders",
		"Male",
		"104",
		"69 inches"
	},
};


// Person Struct with 5 Fields
struct Person {
	string first_name;
	string last_name;
	string gender;
	string age;
	string height;
} first_name, last_name, gender, age, height;

Person People[12];

void fillArray(int dataSize) {
	// [0] = first_name
	// [1] = last_name
	// [2] = gender
	// [3] = age 
	// [4] = height
	for(int i; i < dataSize; i++) {
		People[i].first_name = Data[i][0];
		People[i].last_name = Data[i][1];
		People[i].gender = Data[i][2];
		People[i].age = Data[i][3];
		People[i].height = Data[i][4];
	}
}

void printArray(int dataSize) {
	cout << setprecision(2) << fixed;
	cout << " ------------------------------------------------------";
	cout << setw(1) << " |\n";
	cout << setw(1) << "|";
	cout << setw(12) << "First Name";
	cout << setw(12) << "Last Name";
	cout << setw(12) << "Gender";
	cout << setw(6) << "Age";
	cout << setw(12) << "Height";
	cout << setw(1) << " |\n";
	cout << " ------------------------------------------------------\n";

	for(int i = 0; i < dataSize; i++) {
		cout << setw(1) << "|";
		cout << setw(12) << People[i].first_name;
		cout << setw(12) << People[i].last_name;
		cout << setw(12) << People[i].gender;
		cout << setw(6) << People[i].age;
		cout << setw(12) << People[i].height;
		cout << setw(1) << " |\n";
	}
	cout << " ------------------------------------------------------\n";
}


void sortArrayByAge(int dataSize) {
	for(int i = 1; i < dataSize; i++) {
		for(int k = 0; k < dataSize - i; k++) {
            Person PersonHolder;
            // Convert ages to ints
			int age = atoi(People[k].age.c_str());
            int nextAge = atoi(People[k + 1].age.c_str());
			if(age > nextAge) {
                // Assign current person to temp
                PersonHolder = People[k];
                // Sign next person over current person
                People[k] = People[k + 1];
                // Sign current person to next persons spot
                People[k + 1] = PersonHolder;
            }
		}
	}
}

void sortArrayByLastName(int dataSize) {
	for(int i = 1; i < dataSize; i++) {
		for(int k = 0; k < dataSize - i; k++) {
            Person PersonHolder;
            // If Current is less than 0, then next item is greater
            int identifier = People[k].last_name.compare(People[k + 1].last_name);
            if(identifier < 0) {
                // Assign current person to temp
                PersonHolder = People[k];
                // Sign next person over current person
                People[k] = People[k + 1];
                // Sign current person to next persons spot
                People[k + 1] = PersonHolder;
           }
		}
	}
}


int main () {
	// Get Amount of Rows in 2D array
	int dataSize = sizeof Data / sizeof Data[0];
	// Fill Array of Structs with test data
	fillArray(dataSize);
	// Print Unsorted Array
	printArray(dataSize);

	// Sort Array by Age, ascending order
	sortArrayByAge(dataSize);
	// Print Sorted Array
	printArray(dataSize);

	// Sort Array by Last Name, descending order
    sortArrayByLastName(dataSize);
	// Print Sorted Array
	printArray(dataSize);

	return 0;
}
