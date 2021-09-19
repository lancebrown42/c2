//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Includes - built-in libraries
//-----------------------------------------------------------------------
#include <iostream>;

//-----------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------


//------------------------------------------------------------------------
// Name:
// Problem #1
// Abstract: 
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Name: Main
// Abstract: Program start 
//------------------------------------------------------------------------

void main()
{
	int int_ARR_SIZE = 0;
	long* palngValues = 0;
	printf("Enter the size of the array:\n");
	scanf_s("%d", &int_ARR_SIZE);
	palngValues = new long[int_ARR_SIZE];
	for (int i = 0; i < int_ARR_SIZE; i++) {
		printf("Enter value %d:\n", i + 1);
		scanf_s("%d", palngValues + i);
	}
	for (int i = 0; i < int_ARR_SIZE; i++) {
		printf("Index: %d\tValue: %d\n", i, *(palngValues + i));
	}



}

void MakeArray(long &palngValues) {

}

