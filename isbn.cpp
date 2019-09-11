#include <iostream>
using namespace std; 

/*
* Author: Kyle Culp
* Assignment: ISBN Validation
*/

// Remove any - from the string
string cleanISBN(string isbn) {
  // Initialize string to hold new isbn number
  string newISBN;

  // The ASCI character - is 45
  for(int i=0; i < isbn.length(); i++) {
    if(isbn[i] != 45) {
      newISBN += isbn[i];
    }
  }

  return newISBN;
}

bool isValid(string isbn) { 
  // Check length early
	if(isbn.length() != 10) return false; 

  // Initialize sum
	int sum = 0; 

  // Make sure last digit is a number, or X.
  if((isbn[9] < '0' || isbn[9] > '9') && isbn[9] != 'X') return false; 

  // Loop through all but last digit, because last digit could be an X.
	for (int i=0; i < 9; i++) { 

    // Weird ASCI magic 
		int character = isbn[i] - 48; 

    // Make sure character is a number
		if (0 > character || 9 < character) return false; 

    // Multiply each number (starting with 10) by its position number and then add to sum.
		sum += (character * (10 - i)); 
	} 


  // If the last character equals X, add 10 to sum. 
  // Otherwise, add the last character 
  if(isbn[9] == 'X') {
    sum += 10;
  } else {
    sum += isbn[9] - '0';
  }

  // If no dividend, return true
	return (sum % 11 == 0); 
} 

/*
* 01-35-957052 valid
* 0134494164 valid
* 0---137-------------081----073 valid (done to show the handling of -)
* 043942089X valid
*/

int main() { 
	string isbn;

  cout << "Please enter the full isbn number: ";
  getline(cin, isbn);

  isbn = cleanISBN(isbn); // Clean up the string to an easy to work with isbn 

	if(isValid(isbn)) { // Validate the isbn
		cout << "Valid ISBN Number."; 
  } else {
		cout << "Invalid ISBN Number."; 
  }


	return 0; 
} 
