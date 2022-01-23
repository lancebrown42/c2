//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 11- Templates
//-----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "CResizableArray.h"
#include "CStack.h"
#include "CQueue.h"
// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
// CResizableArray
void ArrayTests();
// Char
void ResizableArrayTestsChar();
void ResizableArrayPassByReferenceChar(CResizableArray<char> &clsValues);
void ResizableArrayPassByValueChar(CResizableArray<char> clsCopyOfOriginal);
// Long
void ResizableArrayTestsLong();
void ResizableArrayPassByReferenceLong(CResizableArray<long> &clsValues);
void ResizableArrayPassByValueLong(CResizableArray<long> clsCopyOfOriginal);
// Double
void ResizableArrayTestsDouble();
void ResizableArrayPassByReferenceDouble(CResizableArray<double> &clsValues);
void ResizableArrayPassByValueDouble(CResizableArray<double> clsCopyOfOriginal);
// CStack
void StackTests();
void StackTestsChar();
void StackPassByReferenceChar(CStack<char> &clsValues);
void StackPassByValueChar(CStack<char> clsCopyOfOriginal);
void StackTestsLong();

void StackPassByReferenceLong(CStack<long> &clsValues);
void StackPassByValueLong(CStack<long> clsCopyOfOriginal);
void StackTestsDouble();
void StackPassByReferenceDouble(CStack<double> &clsValues);
void StackPassByValueDouble(CStack<double> clsCopyOfOriginal);
// CQueue
void QueueTests();
void QueueTestsChar();
void QueuePassByReferenceChar(CQueue<char> &clsValues);
void QueuePassByValueChar(CQueue<char> clsCopyOfOriginal);
void QueueTestsLong();
void QueuePassByReferenceLong(CQueue<long> &clsValues);
void QueuePassByValueLong(CQueue<long> clsCopyOfOriginal);
void QueueTestsDouble();
void QueuePassByReferenceDouble(CQueue<double> &clsValues);
void QueuePassByValueDouble(CQueue<double> clsCopyOfOriginal);
// --------------------------------------------------------------------------------
// Name: main
// Abstract: C++ now with templates!
// --------------------------------------------------------------------------------
void main()
{
	ArrayTests();
	StackTests();
	QueueTests();
}
// --------------------------------------------------------------------------------
// Name: ArrayTests
// Abstract: Test code for CResizableArray with templates
// --------------------------------------------------------------------------------
void ArrayTests()
{
	ResizableArrayTestsChar();
	ResizableArrayTestsLong();
	ResizableArrayTestsDouble();
}
#pragma region "Resizable Array: Char"
// --------------------------------------------------------------------------------
// Name: ResizableArrayTestsChar
// Abstract: Test every single class method for resizable array.
// --------------------------------------------------------------------------------
void ResizableArrayTestsChar()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Resizable Array Tests: Long" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CResizableArray<char> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - SetSize
	clsValues1.SetSize(4);
	clsValues1.Print("#2a - SetSize( 4 )");
	clsValues1.SetSize(0);
	clsValues1.SetSize(4, 'A');
	clsValues1.Print("#2b - SetSize( 4, 'A' )");
	// #3 - GetSize
	cout << "#3 - GetSize: 4? " << clsValues1.GetSize() << endl;
	// #4 - Populate with subscript operator
	clsValues1[-1] = 'A';
	clsValues1[0] = 'a';
	clsValues1[1] = 'c';
	clsValues1[2] = 'e';
	clsValues1[3] = 'f';
	clsValues1[4] = 'H';
	clsValues1.Print("#4 - Populate with subscript operator");
	{
		// #5 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CResizableArray<char> clsValues2(clsValues1);
		clsValues2.Print("#5a - Copy Constructor, Assignment Operator, DeepCopy and const Subscript" );
	}
	clsValues1.Print("#5b - Original unaffected");
	// #6 - Parameterized Constructor #1 - Size
	CResizableArray<char> clsValues3(2);
	clsValues3.Print("#6 - Parameterized Constructor #1 - Size:2");
	// #7 - Parameterized Constructor #2 - Size, Default Value
	CResizableArray<char> clsValues4(3, 'Y');
	clsValues4.Print("#7 - Parameterized Constructor #2 - Size:3, Default Value: Y");
	// #8 - Plus Equal
	clsValues3 += clsValues4;
	clsValues3.Print("#8 - Plus Equal: '0, 0' + 'Y, Y, Y'");
	// #9 - Plus with assign to self
	clsValues3 = clsValues3 + clsValues3;
	clsValues3.Print("#9 - Plus with assign to self: '0, 0, Y, Y, Y' + '0, 0, Y, Y, Y'");	// #10 - SetValueAt
	clsValues1.SetValueAt('z', -1);
	clsValues1.SetValueAt('Z', 5);
	clsValues1.Print("#10 - SetValueAt");
	// #11 - GetValueAt
	cout << "#11 - GetValueAt" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#11a - GetValueAt( -1 ): " << clsValues1.GetValueAt(-1) << endl;
	cout << "#11b - GetValueAt( 1 ): " << clsValues1.GetValueAt(1) << endl;
	cout << "#11c - GetValueAt( 2 ): " << clsValues1.GetValueAt(2) << endl;
	cout << "#11d - GetValueAt( 5 ): " << clsValues1.GetValueAt(5) << endl;
	// #12 - AddValueToFront
	clsValues1.AddValueToFront('v');
	clsValues1.Print("#12 - AddValueToFront: -10");
	// #13 - AddValueToEnd
	clsValues1.AddValueToEnd('V');
	clsValues1.Print("#13 - AddValueToFront: 50");
	// #14 - InsertValueAt
	clsValues1.InsertValueAt('u', -5);
	clsValues1.Print("#14a - InsertValueAt: -50, -5");
	clsValues1.InsertValueAt('p', 3);
	clsValues1.Print("#14b - InsertValueAt: 5, 3");
	clsValues1.InsertValueAt('U', 50);
	clsValues1.Print("#14c - InsertValueAt: 100, 50");
	// #15 - RemoveAt
	clsValues3 = clsValues1;
	clsValues3.RemoveAt(-1);
	clsValues3.Print("#15a - RemoveAt: -1");
	clsValues3.RemoveAt(10);
	clsValues3.Print("#15b - RemoveAt: 10");
	clsValues3.RemoveAt(2);
	clsValues3.Print("#15c - RemoveAt: 2");
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.Print("#15d - RemoveAt: 0 * 6");
	// #16a - Pass By Reference
	clsValues1.Print("#16a - Pass By Reference - Before");
	ResizableArrayPassByReferenceChar(clsValues1);
	clsValues1.Print("#16c - Pass By Reference - After");
	// #17a - Pass By Value
	clsValues1.Print("#17a - Pass By Value - Before");
	ResizableArrayPassByValueChar(clsValues1);
	clsValues1.Print("#17c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: ResizableArrayPassByReferenceChar
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void ResizableArrayPassByReferenceChar(CResizableArray<char> &clsValues)
{
	clsValues.Print("#16b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: ResizableArrayPassByValueChar
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void ResizableArrayPassByValueChar(CResizableArray<char> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#17b - Pass By Value - During");
}
#pragma endregion
#pragma region "Resizable Array: Long"
// --------------------------------------------------------------------------------
// Name: ResizableArrayTestsLong
// Abstract: Test every single class method for resizable array.
// --------------------------------------------------------------------------------
void ResizableArrayTestsLong()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Resizable Array Tests: Long" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CResizableArray<long> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - SetSize
	clsValues1.SetSize(4);
	clsValues1.Print("#2a - SetSize( 4 )");
	clsValues1.SetSize(0);
	clsValues1.SetSize(4, -1);
	clsValues1.Print("#2b - SetSize( 4, -1 )");
	// #3 - GetSize
	cout << "#3 - GetSize: 4? " << clsValues1.GetSize() << endl;
	// #4 - Populate with subscript operator
	clsValues1[-1] = -2;
	clsValues1[0] = 2;
	clsValues1[1] = 4;
	clsValues1[2] = 6;
	clsValues1[3] = -8;
	clsValues1[4] = 8;
	clsValues1.Print("#4 - Populate with subscript operator");
	{
		// #5 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CResizableArray<long> clsValues2(clsValues1);
		clsValues2.Print("#5a - Copy Constructor, Assignment Operator, DeepCopy and const Subscript" );
	}
	clsValues1.Print("#5b - Original unaffected");
	// #6 - Parameterized Constructor #1 - Size
	CResizableArray<long> clsValues3(2);
	clsValues3.Print("#6 - Parameterized Constructor #1 - Size:2");
	// #7 - Parameterized Constructor #2 - Size, Default Value
	CResizableArray<long> clsValues4(3, 4);
	clsValues4.Print("#7 - Parameterized Constructor #2 - Size:3, Default Value: 4");
	// #8 - Plus Equal
	clsValues3 += clsValues4;
	clsValues3.Print("#8 - Plus Equal: '0, 0' + '4, 4, 4'");
	// #9 - Plus with assign to self
	clsValues3 = clsValues3 + clsValues3;
	clsValues3.Print("#9 - Plus with assign to self: '0, 0, 4, 4, 4' + '0, 0, 4, 4, 4'");
	// #10 - SetValueAt
	clsValues1.SetValueAt(-5, -1);
	clsValues1.SetValueAt(10, 5);
	clsValues1.Print("#10 - SetValueAt");
	// #11 - GetValueAt
	cout << "#11 - GetValueAt" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#11a - GetValueAt( -1 ): " << clsValues1.GetValueAt(-1) << endl;
	cout << "#11b - GetValueAt( 1 ): " << clsValues1.GetValueAt(1) << endl;
	cout << "#11c - GetValueAt( 2 ): " << clsValues1.GetValueAt(2) << endl;
	cout << "#11d - GetValueAt( 5 ): " << clsValues1.GetValueAt(5) << endl;
	// #12 - AddValueToFront
	clsValues1.AddValueToFront(-10);
	clsValues1.Print("#12 - AddValueToFront: -10");
	// #13 - AddValueToEnd
	clsValues1.AddValueToEnd(50);
	clsValues1.Print("#13 - AddValueToFront: 50");
	// #14 - InsertValueAt
	clsValues1.InsertValueAt(-50, -5);
	clsValues1.Print("#14a - InsertValueAt: -50, -5");
	clsValues1.InsertValueAt(5, 3);
	clsValues1.Print("#14b - InsertValueAt: 5, 3");
	clsValues1.InsertValueAt(100, 50);
	clsValues1.Print("#14c - InsertValueAt: 100, 50");
	// #15 - RemoveAt
	clsValues3 = clsValues1;
	clsValues3.RemoveAt(-1);
	clsValues3.Print("#15a - RemoveAt: -1");
	clsValues3.RemoveAt(10);
	clsValues3.Print("#15b - RemoveAt: 10");
	clsValues3.RemoveAt(2);
	clsValues3.Print("#15c - RemoveAt: 2");
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.Print("#15d - RemoveAt: 0 * 6");
	// #16a - Pass By Reference
	clsValues1.Print("#16a - Pass By Reference - Before");
	ResizableArrayPassByReferenceLong(clsValues1);
	clsValues1.Print("#16c - Pass By Reference - After");
	// #17a - Pass By Value
	clsValues1.Print("#17a - Pass By Value - Before");
	ResizableArrayPassByValueLong(clsValues1);
	clsValues1.Print("#17c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: ResizableArrayPassByReferenceLong
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void ResizableArrayPassByReferenceLong(CResizableArray<long> &clsValues)
{
	clsValues.Print("#16b - Pass By Reference - During");
}// --------------------------------------------------------------------------------
// Name: ResizableArrayPassByValueLong
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void ResizableArrayPassByValueLong(CResizableArray<long> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#17b - Pass By Value - During");
}
#pragma endregion
#pragma region "Resizable Array: Double"
// --------------------------------------------------------------------------------
// Name: ResizableArrayTestsDouble
// Abstract: Test every single class method for resizable array.
// --------------------------------------------------------------------------------
void ResizableArrayTestsDouble()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Resizable Array Tests: Double" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CResizableArray<double> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - SetSize
	clsValues1.SetSize(4);
	clsValues1.Print("#2a - SetSize( 4 )");
	clsValues1.SetSize(0);
	clsValues1.SetSize(4, -1.1);
	clsValues1.Print("#2b - SetSize( 4, -1.1 )");
	// #3 - GetSize
	cout << "#3 - GetSize: 4? " << clsValues1.GetSize() << endl;
	// #4 - Populate with subscript operator
	clsValues1[-1] = -2.2;
	clsValues1[0] = 2.2;
	clsValues1[1] = 4.4;
	clsValues1[2] = 6.6;
	clsValues1[3] = -8.8;
	clsValues1[4] = 8.8;
	clsValues1.Print("#4 - Populate with subscript operator");
	{
		// #5 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CResizableArray<double> clsValues2(clsValues1);
		clsValues2.Print("#5a - Copy Constructor, Assignment Operator, DeepCopy and const Subscript" );
	}
	clsValues1.Print("#5b - Original unaffected");
	// #6 - Parameterized Constructor #1 - Size
	CResizableArray<double> clsValues3(2);
	clsValues3.Print("#6 - Parameterized Constructor #1 - Size:2");
	// #7 - Parameterized Constructor #2 - Size, Default Value
	CResizableArray<double> clsValues4(3, 4.4);
	clsValues4.Print("#7 - Parameterized Constructor #2 - Size:3, Default Value: 4");
	// #8 - Plus Equal
	clsValues3 += clsValues4;
	clsValues3.Print("#8 - Plus Equal: '0, 0' + '4.4, 4.4, 4.4'");
	// #9 - Plus with assign to self
	clsValues3 = clsValues3 + clsValues3;
	clsValues3.Print("#9 - Plus with assign to self: '0, 0, 4.4, 4.4, 4.4' + '0, 0, 4.4, 4.4, 4.4'" );
		// #10 - SetValueAt
		clsValues1.SetValueAt(-5.5, -1);
	clsValues1.SetValueAt(10.1, 5);
	clsValues1.Print("#10 - SetValueAt");
	// #11 - GetValueAt
	cout << "#11 - GetValueAt" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#11a - GetValueAt( -1 ): " << clsValues1.GetValueAt(-1) << endl;
	cout << "#11b - GetValueAt( 1 ): " << clsValues1.GetValueAt(1) << endl;
	cout << "#11c - GetValueAt( 2 ): " << clsValues1.GetValueAt(2) << endl;
	cout << "#11d - GetValueAt( 5 ): " << clsValues1.GetValueAt(5) << endl;
	// #12 - AddValueToFront
	clsValues1.AddValueToFront(-10.1);
	clsValues1.Print("#12 - AddValueToFront: -10");
	// #13 - AddValueToEnd
	clsValues1.AddValueToEnd(50.5);
	clsValues1.Print("#13 - AddValueToFront: 50");
	// #14 - InsertValueAt
	clsValues1.InsertValueAt(-50.50, -5);
	clsValues1.Print("#14a - InsertValueAt: -50.5, -5");
	clsValues1.InsertValueAt(5.5, 3);
	clsValues1.Print("#14b - InsertValueAt: 5.5, 3");
	clsValues1.InsertValueAt(100.1, 50);
	clsValues1.Print("#14c - InsertValueAt: 100.1, 50");
	// #15 - RemoveAt
	clsValues3 = clsValues1;
	clsValues3.RemoveAt(-1);	clsValues3.Print("#15a - RemoveAt: -1");
	clsValues3.RemoveAt(10);
	clsValues3.Print("#15b - RemoveAt: 10");
	clsValues3.RemoveAt(2);
	clsValues3.Print("#15c - RemoveAt: 2");
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.RemoveAt(0);
	clsValues3.Print("#15d - RemoveAt: 0 * 6");
	// #16a - Pass By Reference
	clsValues1.Print("#16a - Pass By Reference - Before");
	ResizableArrayPassByReferenceDouble(clsValues1);
	clsValues1.Print("#16c - Pass By Reference - After");
	// #17a - Pass By Value
	clsValues1.Print("#17a - Pass By Value - Before");
	ResizableArrayPassByValueDouble(clsValues1);
	clsValues1.Print("#17c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: ResizableArrayPassByReferenceDouble
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void ResizableArrayPassByReferenceDouble(CResizableArray<double> &clsValues)
{
	clsValues.Print("#16b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: ResizableArrayPassByValueDouble
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void ResizableArrayPassByValueDouble(CResizableArray<double> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#17b - Pass By Value - During");
}
#pragma endregion
// --------------------------------------------------------------------------------
// Name: StackTests
// Abstract: Test code for CStack with templates
// --------------------------------------------------------------------------------
void StackTests()
{
	StackTestsChar();
	StackTestsLong();
	StackTestsDouble();
}
#pragma region "Stack: Char"
// --------------------------------------------------------------------------------
// Name: StackTestsChar
// Abstract: Test every single class method for stack.
// --------------------------------------------------------------------------------
void StackTestsChar()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Stack Tests: Char" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CStack<char> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - Push
	clsValues1.Push('a');
	clsValues1.Push('b');
	clsValues1.Push('c');
	clsValues1.Print("Push: a, b, c");
	{
		// #3 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CStack<char> clsValues2(clsValues1);
		clsValues2.Print("#3a - Copy Constructor, Assignment Operator and DeepCopy");
	}
	clsValues1.Print("#3b - Original unaffected");
	// #4a - IsEmpty
	cout << "#4a - IsEmpty? " << clsValues1.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #5 - Pop
	CStack<char> clsValues3(clsValues1);
	cout << "#5 - Pop" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#5a - Pop: " << clsValues3.Pop() << endl;
	cout << "#5b - Pop: " << clsValues3.Pop() << endl;
	cout << "#5c - Pop: " << clsValues3.Pop() << endl;
	cout << "#5d - Pop: " << clsValues3.Pop() << endl;
	cout << endl;
	// #4b - IsEmpty
	cout << "#4b - IsEmpty? " << clsValues3.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #6a - Pass By Reference
	clsValues1.Print("#6a - Pass By Reference - Before");
	StackPassByReferenceChar(clsValues1);
	clsValues1.Print("#6c - Pass By Reference - After");
	// #7a - Pass By Value
	clsValues1.Print("#7a - Pass By Value - Before");
	StackPassByValueChar(clsValues1);
	clsValues1.Print("#7c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: StackPassByReferenceChar
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void StackPassByReferenceChar(CStack<char> &clsValues)
{
	clsValues.Print("#6b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: StackPassByValueChar
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void StackPassByValueChar(CStack<char> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#7b - Pass By Value - During");
}
#pragma endregion
#pragma region "Stack: Long"
// --------------------------------------------------------------------------------
// Name: StackTestsLong
// Abstract: Test every single class method for stack.
// --------------------------------------------------------------------------------
void StackTestsLong()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Stack Tests: Long" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CStack<long> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - Push
	clsValues1.Push(1);
	clsValues1.Push(2);
	clsValues1.Push(3);
	clsValues1.Print("Push: 1, 2, 3");
	{
		// #3 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CStack<long> clsValues2(clsValues1);
		clsValues2.Print("#3a - Copy Constructor, Assignment Operator and DeepCopy");
	}
	clsValues1.Print("#3b - Original unaffected");
	// #4a - IsEmpty
	cout << "#4a - IsEmpty? " << clsValues1.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #5 - Pop
	CStack<long> clsValues3(clsValues1);
	cout << "#5 - Pop" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#5a - Pop: " << clsValues3.Pop() << endl;
	cout << "#5b - Pop: " << clsValues3.Pop() << endl;
	cout << "#5c - Pop: " << clsValues3.Pop() << endl;
	cout << "#5d - Pop: " << clsValues3.Pop() << endl;
	cout << endl;
	// #4b - IsEmpty
	cout << "#4b - IsEmpty? " << clsValues3.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #6a - Pass By Reference
	clsValues1.Print("#6a - Pass By Reference - Before");
	StackPassByReferenceLong(clsValues1);
	clsValues1.Print("#6c - Pass By Reference - After");
	// #7a - Pass By Value
	clsValues1.Print("#7a - Pass By Value - Before");
	StackPassByValueLong(clsValues1);
	clsValues1.Print("#7c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: StackPassByReferenceLong
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void StackPassByReferenceLong(CStack<long> &clsValues)
{
	clsValues.Print("#6b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: StackPassByValueLong
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void StackPassByValueLong(CStack<long> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#7b - Pass By Value - During");
}
#pragma endregion
#pragma region "Stack: Double"
// --------------------------------------------------------------------------------
// Name: StackTestsDouble
// Abstract: Test every single class method for stack.
// --------------------------------------------------------------------------------
void StackTestsDouble()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Stack Tests: Double" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CStack<double> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - Push
	clsValues1.Push(1.1);
	clsValues1.Push(2.2);
	clsValues1.Push(3.3);
	clsValues1.Print("Push: 1.1, 2.2, 3.3");
	{
		// #3 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CStack<double> clsValues2(clsValues1);
		clsValues2.Print("#3a - Copy Constructor, Assignment Operator and DeepCopy");
	}
	clsValues1.Print("#3b - Original unaffected");
	// #4a - IsEmpty
	cout << "#4a - IsEmpty? " << clsValues1.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #5 - Pop
	CStack<double> clsValues3(clsValues1);
	cout << "#5 - Pop" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#5a - Pop: " << clsValues3.Pop() << endl;
	cout << "#5b - Pop: " << clsValues3.Pop() << endl;
	cout << "#5c - Pop: " << clsValues3.Pop() << endl;
	cout << "#5d - Pop: " << clsValues3.Pop() << endl;
	cout << endl;
	// #4b - IsEmpty
	cout << "#4b - IsEmpty? " << clsValues3.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #6a - Pass By Reference
	clsValues1.Print("#6a - Pass By Reference - Before");
	StackPassByReferenceDouble(clsValues1);
	clsValues1.Print("#6c - Pass By Reference - After");
	// #7a - Pass By Value
	clsValues1.Print("#7a - Pass By Value - Before");
	StackPassByValueDouble(clsValues1);
	clsValues1.Print("#7c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: StackPassByReferenceDouble
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void StackPassByReferenceDouble(CStack<double> &clsValues)
{
	clsValues.Print("#6b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: StackPassByValueDouble
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void StackPassByValueDouble(CStack<double> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#7b - Pass By Value - During");
}
#pragma endregion
// --------------------------------------------------------------------------------
// Name: QueueTests
// Abstract: Test code for CQueue with templates
// --------------------------------------------------------------------------------
void QueueTests()
{
	QueueTestsChar();
	QueueTestsLong();
	QueueTestsDouble();
}
#pragma region "Queue: Char"
// --------------------------------------------------------------------------------
// Name: QueueTestsChar
// Abstract: Test every single class method for Queue.
// --------------------------------------------------------------------------------
void QueueTestsChar()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Queue Tests: Char" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CQueue<char> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - Push
	clsValues1.Push('a');
	clsValues1.Push('b');
	clsValues1.Push('c');
	clsValues1.Print("Push: a, b, c");
	{
		// #3 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CQueue<char> clsValues2(clsValues1);
		clsValues2.Print("#3a - Copy Constructor, Assignment Operator and DeepCopy");
	}
	clsValues1.Print("#3b - Original unaffected");
	// #4a - IsEmpty
	cout << "#4a - IsEmpty? " << clsValues1.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #5 - Pop
	CQueue<char> clsValues3(clsValues1);
	cout << "#5 - Pop" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#5a - Pop: " << clsValues3.Pop() << endl;
	cout << "#5b - Pop: " << clsValues3.Pop() << endl;
	cout << "#5c - Pop: " << clsValues3.Pop() << endl;
	cout << "#5d - Pop: " << clsValues3.Pop() << endl;
	cout << endl;
	// #4b - IsEmpty
	cout << "#4b - IsEmpty? " << clsValues3.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #6a - Pass By Reference
	clsValues1.Print("#6a - Pass By Reference - Before");
	QueuePassByReferenceChar(clsValues1);
	clsValues1.Print("#6c - Pass By Reference - After");
	// #7a - Pass By Value
	clsValues1.Print("#7a - Pass By Value - Before");
	QueuePassByValueChar(clsValues1);
	clsValues1.Print("#7c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: QueuePassByReferenceChar
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void QueuePassByReferenceChar(CQueue<char> &clsValues)
{
	clsValues.Print("#6b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: QueuePassByValueChar
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void QueuePassByValueChar(CQueue<char> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#7b - Pass By Value - During");
}
#pragma endregion
#pragma region "Queue: Long"
// --------------------------------------------------------------------------------
// Name: QueueTestsLong
// Abstract: Test every single class method for Queue.
// --------------------------------------------------------------------------------
void QueueTestsLong()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Queue Tests: Long" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CQueue<long> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - Push
	clsValues1.Push(1);
	clsValues1.Push(2);
	clsValues1.Push(3);
	clsValues1.Print("Push: 1, 2, 3");
	{
		// #3 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CQueue<long> clsValues2(clsValues1);
		clsValues2.Print("#3a - Copy Constructor, Assignment Operator and DeepCopy");
	}
	clsValues1.Print("#3b - Original unaffected");
	// #4a - IsEmpty
	cout << "#4a - IsEmpty? " << clsValues1.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #5 - Pop
	CQueue<long> clsValues3(clsValues1);
	cout << "#5 - Pop" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#5a - Pop: " << clsValues3.Pop() << endl;
	cout << "#5b - Pop: " << clsValues3.Pop() << endl;
	cout << "#5c - Pop: " << clsValues3.Pop() << endl;
	cout << "#5d - Pop: " << clsValues3.Pop() << endl;
	cout << endl;
	// #4b - IsEmpty
	cout << "#4b - IsEmpty? " << clsValues3.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #6a - Pass By Reference
	clsValues1.Print("#6a - Pass By Reference - Before");
	QueuePassByReferenceLong(clsValues1);
	clsValues1.Print("#6c - Pass By Reference - After");
	// #7a - Pass By Value
	clsValues1.Print("#7a - Pass By Value - Before");
	QueuePassByValueLong(clsValues1);
	clsValues1.Print("#7c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: QueuePassByReferenceLong
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void QueuePassByReferenceLong(CQueue<long> &clsValues)
{
	clsValues.Print("#6b - Pass By Reference - During");
}
// --------------------------------------------------------------------------------
// Name: QueuePassByValueLong
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void QueuePassByValueLong(CQueue<long> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#7b - Pass By Value - During");
}
#pragma endregion
#pragma region "Queue: Double"
// --------------------------------------------------------------------------------
// Name: QueueTestsDouble
// Abstract: Test every single class method for Queue.
// --------------------------------------------------------------------------------
void QueueTestsDouble()
{
	cout << "------------------------------------------------------------" << endl;
	cout << "Queue Tests: Double" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << endl;
	// #1 - Constructor
	CQueue<double> clsValues1;
	clsValues1.Print("#1 - Default Constructor");
	// #2 - Push
	clsValues1.Push(1.1);
	clsValues1.Push(2.2);
	clsValues1.Push(3.3);
	clsValues1.Print("Push: 1.1, 2.2, 3.3");
	{
		// #3 - Copy Constructor
		// Placing in brackets means copy will go out of scope and call destructor for copy
		// Original should be unaffected
		CQueue<double> clsValues2(clsValues1);
		clsValues2.Print("#3a - Copy Constructor, Assignment Operator and DeepCopy");
	}
	clsValues1.Print("#3b - Original unaffected");
	// #4a - IsEmpty
	cout << "#4a - IsEmpty? " << clsValues1.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #5 - Pop
	CQueue<double> clsValues3(clsValues1);
	cout << "#5 - Pop" << endl;
	cout << "----------------------------------------" << endl;
	cout << "#5a - Pop: " << clsValues3.Pop() << endl;
	cout << "#5b - Pop: " << clsValues3.Pop() << endl;
	cout << "#5c - Pop: " << clsValues3.Pop() << endl;
	cout << "#5d - Pop: " << clsValues3.Pop() << endl;
	cout << endl;
	// #4b - IsEmpty
	cout << "#4b - IsEmpty? " << clsValues3.IsEmpty() << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	// #6a - Pass By Reference
	clsValues1.Print("#6a - Pass By Reference - Before");
	QueuePassByReferenceDouble(clsValues1);
	clsValues1.Print("#6c - Pass By Reference - After");
	// #7a - Pass By Value
	clsValues1.Print("#7a - Pass By Value - Before");
	QueuePassByValueDouble(clsValues1);
	clsValues1.Print("#7c - Pass By Value - After");
	system("pause");
}
// --------------------------------------------------------------------------------
// Name: QueuePassByReferenceDouble
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void QueuePassByReferenceDouble(CQueue<double> &clsValues)
{
	clsValues.Print("#6b - Pass By Reference - During");
}// --------------------------------------------------------------------------------
// Name: QueuePassByValueDouble
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void QueuePassByValueDouble(CQueue<double> clsCopyOfOriginal)
{
	clsCopyOfOriginal.Print("#7b - Pass By Value - During");
}
#pragma endregion