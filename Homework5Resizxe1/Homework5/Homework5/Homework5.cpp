//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 5- Resizable arrays
//-----------------------------------------------------------------------
#include <iostream>
#include "CResizableArray.h"
int main()
{
	
	CResizableArray clsValues;
	//initialize
	clsValues.Initialize();
	//set size to 5
	clsValues.SetSize(5);
	clsValues.Print((char*)"Size set to 5");
	//populate array
	for (long i = 0; i < clsValues.GetSize(); i++) {
		clsValues.SetValueAt((i+1) * 2, i);
	}
	clsValues.Print((char*)"Assigned Even Numbers");
	//prepend
	clsValues.AddValueToFront(15);
	clsValues.Print((char*)"Added 15 to front");
	//append
	clsValues.AddValueToEnd(3);
	clsValues.Print((char*)"Added 3 to end");
	//insert
	clsValues.InsertValueAt(90, 3);
	clsValues.Print((char*)"Added 90 at index 3");
	//remove
	clsValues.RemoveAt(3);
	clsValues.Print((char*)"Remove the 90 at index 3");

	clsValues.Print();

}
