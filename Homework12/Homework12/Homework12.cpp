// --------------------------------------------------------------------------------
// Name: CClassName
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


int AddNumbers(int intIndex);

void main() {
	int intNumber = 0;

	intNumber = AddNumbers(0);
	cout << "1.1 - Add 1 to 100: " << intNumber << endl;
	
}

int AddNumbers(int intIndex) {
	int intTotal = 0;
	intIndex += 1;
	if (intIndex < 100) {
		intTotal += intIndex + AddNumbers(intIndex);
	}
	else {
		intTotal += intIndex;
	}
	return intTotal;
}