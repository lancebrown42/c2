// --------------------------------------------------------------------------------
// Name: Homework 12
// Abstract: Recursion pt 1
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//problem 1
int AddNumbers(int intIndex);
//problem 2
void MaximumRecursion(int intCalls);
//problem 3
int AddNumbersInRange(int intStart, int intStop);
//Step 2
//Problem 1
long long FindFactorial(int intNumber);
//Problem 2
void DisplayFactorials();
//problem 3
double FindFactorialDbl(int intNumber);
void MaximumFactorial();
double Fibonacci(int intNumber);

int main() {
	int intNumber = 0;

	intNumber = AddNumbers(0);
	printf("1.1 - Add 1 to 100: %d\n",intNumber);
	

	MaximumRecursion(0);

	intNumber = AddNumbersInRange(5, 30);
	printf("1.3: Add 5 to 30: %d\n", intNumber);

	long long lnumber = 0;
	lnumber = FindFactorial(10);
	printf("2.1: Find the factorial of 10!: %d\n", lnumber);

	DisplayFactorials();
	MaximumFactorial();
	double dblNumber = 0;
	dblNumber = Fibonacci(100);
	printf("2.3: Find Fibonnaci sum of 100: %1.0f\n", dblNumber);
}

// --------------------------------------------------------------------------------
// Name: AddNumbers
// Abstract: Adds numbers recursively
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// Name: MaximumRecursion
// Abstract: Finds max number of recursion calls
// Breaks after 4763 with 32 GB RAM, but then also at 4756...., then 4760. 
// --------------------------------------------------------------------------------
void MaximumRecursion(int intCalls) {
	intCalls += 1;
	printf("This is call #%d\n", intCalls);
	if (intCalls < 4750) {
		MaximumRecursion(intCalls);
	}
}

// --------------------------------------------------------------------------------
// Name: AddNumbersInRange
// Abstract: Adds numbers from start to stop
// --------------------------------------------------------------------------------
int AddNumbersInRange(int intStart, int intStop) {
	int intTotal = 0;
	if (intStart < intStop) {
		intTotal = intStart + AddNumbersInRange(intStart + 1, intStop);
	}
	else {
		intTotal = intStop;
	}
	return intTotal;
}

// --------------------------------------------------------------------------------
// Name: FindFactorial
// Abstract: Finds the factorial of given number
// --------------------------------------------------------------------------------
long long FindFactorial(int intNumber) {
	long long factorial = 0;
	if (intNumber > 1) {
		factorial = intNumber * FindFactorial(intNumber - 1);
	}
	else {
		factorial = 1;
	}
	return factorial;
}
// --------------------------------------------------------------------------------
// Name: FindFactorialDbl
// Abstract: Finds the factorial of given number
// --------------------------------------------------------------------------------
double FindFactorialDbl(int intNumber) {
	double factorial = 0;
	if (intNumber > 1) {
		factorial = intNumber * FindFactorialDbl(intNumber - 1);
	}
	else {
		factorial = 1;
	}
	return factorial;
}

// --------------------------------------------------------------------------------
// Name: DisplayFactorials
// Abstract: Finds the factorials between 1 and 20
// --------------------------------------------------------------------------------
void DisplayFactorials() {
	long long factorial = 0;
	for (int i = 1; i <= 10; i++) {
		factorial = FindFactorial(i);
		printf("%2d = %10I64d       ", i, factorial);
		factorial = FindFactorial(i + 10);
		printf("%2d = %20I64d\n", i+10, factorial);
	}
}
// --------------------------------------------------------------------------------
// Name: MaximumFactorial
// Abstract: Finds the biggest factorial, which is 170!
// --------------------------------------------------------------------------------
void MaximumFactorial() {
	double factorial = 0;
	factorial =  FindFactorialDbl(170);
	cout << "big factorial " << factorial << endl;
	//printf("Big factorial: %f\n", factorial);
	
}
// --------------------------------------------------------------------------------
// Name: Fibonacci
// Abstract: Finds Fibonacci value at a given index - No idea what the maximum is, but it slows down after 50, and 100 takes an eternity
// --------------------------------------------------------------------------------
double Fibonacci( int intNumber) {
	double value = 0;
	if (intNumber > 1) {
		value = Fibonacci(intNumber - 1) + Fibonacci(intNumber - 2);
	}
	else if(intNumber ==1) {
		value = 1;
	}

	return value;
	
}

