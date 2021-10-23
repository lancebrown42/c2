//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 7- Resizable arrays take 2
//-----------------------------------------------------------------------
#include <iostream>
#include "CResizableArray.h"
// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void Test1(CResizableArray &clsValues);		// By Reference
void Test2(CResizableArray clsValues);		// By Value

//-----------------------------------------------------------------
// Mystery Solution:
// Test2 is being passed the value of a pointer, rather than the content, which 
// conflicts with the pointer from Test1, so when Test1 cleans up and clears the 
// space in memory, Test2 also gets deleted.
// 
// Solution: Don't pass the pointer to the test method, pass a new object
// by dereferencing the pointer and allocating a new space in memory for a 
// new copy of the "array"

// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
void main()

{
	
	CResizableArray clsValues( 5 );
	
	clsValues.SetValueAt(2, 0);
	clsValues.SetValueAt(8, 1);
	clsValues.SetValueAt(41, 2);
	clsValues.SetValueAt(879, 3);
	clsValues.SetValueAt(123, 4);

	clsValues.Print();
	
	// Test 1
	//Test1(clsValues);
	printf("After Test 1 ------------------------------\n");
	clsValues.Print();

	// Test 2
	//Test2(clsValues);
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

