//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 8- Deep copy
//-----------------------------------------------------------------------
#include <iostream>
#include "CResizableArray.h"
// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void Test1(CResizableArray &clsValues);		// By Reference
void Test2(CResizableArray clsValues);		// By Value

// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
void main()

{

	CResizableArray clsValues(5);

	clsValues.SetValueAt(2, 0);
	clsValues.SetValueAt(8, 1);
	clsValues.SetValueAt(41, 2);
	clsValues.SetValueAt(879, 3);
	clsValues.SetValueAt(123, 4);

	clsValues.Print();

	// Test 1
	Test1(clsValues);
	printf("After Test 1 ------------------------------\n");
	clsValues.Print();

	// Test 2
	Test2(clsValues);
	printf("After Test 2 ------------------------------\n");
	clsValues.Print();

}

// --------------------------------------------------------------------------------
// Name: Test1
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void Test1(CResizableArray &clsValues)
{
	printf("Test 1 ------------------------------\n");
	clsValues.Print();
}


// --------------------------------------------------------------------------------
// Name: Test2
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void Test2(CResizableArray clsValues)
{
	printf("Test 2 ------------------------------\n");
	clsValues.Print();
}

