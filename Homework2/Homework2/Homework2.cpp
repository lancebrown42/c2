//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 3
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Includes - built-in libraries
//-----------------------------------------------------------------------
#include <iostream>;

//-----------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------


//------------------------------------------------------------------------
// Name: New and Delete
// Problem #1
// Abstract: Creates array and populates with user input and then deletes
//------------------------------------------------------------------------


//------------------------------------------------------------------------
// Name: MakeArray
// Abstract: Allocates memory for array
//------------------------------------------------------------------------

void MakeArray(long* &palngValues, long &lngArraySize) {
	printf("Enter the size of the array:\n");
	scanf_s("%d", &lngArraySize);
	if (lngArraySize < 1 || lngArraySize > 100) {
		printf("Enter a value between 1 and 100\n");
		MakeArray(palngValues, lngArraySize);
	}
	palngValues = new long[lngArraySize];
}

//------------------------------------------------------------------------
// Name: PopulateArray
// Abstract: Takes user input to poulate array
//------------------------------------------------------------------------
void PopulateArray(long*& palngValues, long& lngArraySize) {
	for (int i = 0; i < lngArraySize; i++) {
		printf("Enter value %d:\n", i + 1);
		scanf_s("%d", palngValues + i);
	}
}

//------------------------------------------------------------------------
// Name: PrintArray
// Abstract: Prints array content
//------------------------------------------------------------------------
void PrintArray(long*& palngValues, long& lngArraySize) {
	for (int i = 0; i < lngArraySize; i++) {
		printf("Index: %d\tValue: %d\n", i, *(palngValues + i));
	}
}

//------------------------------------------------------------------------
// Name: DeleteArray
// Abstract: Deletes array
//------------------------------------------------------------------------
void DeleteArray(long* &palngValues) {
	delete [] palngValues;
	palngValues = 0;
}
//------------------------------------------------------------------------
// Name: Main
// Abstract: Program start 
//------------------------------------------------------------------------
void main()
{
	long lngArraySize = 0;
	long* palngValues = 0;
	MakeArray(palngValues, lngArraySize);
	PopulateArray(palngValues, lngArraySize);
	PrintArray(palngValues, lngArraySize);
	DeleteArray(palngValues);
	printf("The value at: %p is %p after delete", &palngValues, palngValues);

}

