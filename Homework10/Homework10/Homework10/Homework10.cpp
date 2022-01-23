//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 10
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Includes - built-in libraries
//-----------------------------------------------------------------------
#include <iostream>
#include "CNode.h"
#include "CQueue.h"
#include "CStack.h"


//-----------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------


//------------------------------------------------------------------------
// Name:
// Problem #1
// Abstract: 
//------------------------------------------------------------------------

//-----------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------
void StackTests();
void StackTestRef(CStack &clsRef);
void StackTestVal(CStack clsVal);
void QueueTests();
void QueueTestRef(CQueue &clsRef);
void QueueTestVal(CQueue clsVal);

//------------------------------------------------------------------------
// Name: Main
// Abstract: Program start 
//------------------------------------------------------------------------

void main()
{
	StackTests();
	QueueTests();
	system("pause");

	
}
//------------------------------------------------------------------------
// Name: StackTests
// Abstract: Testing Stack class 
//------------------------------------------------------------------------
void StackTests() {
	CStack clsStackTest = CStack();
	for (int i = 0; i < 10; i++) {
		clsStackTest.Push(i);
	}
	clsStackTest.Print("list");

	clsStackTest.Pop();
	clsStackTest.Print("pop");
	clsStackTest.Push(999);
	clsStackTest.Print("Push");
	clsStackTest.Print("Before ref");
	StackTestRef(clsStackTest);
	clsStackTest.Print("after ref");
	clsStackTest.Print("Before val");
	StackTestVal(clsStackTest);
	clsStackTest.Print("after val");
	for (int i = 0; i < 10; i++) {
		clsStackTest.Pop();
	}
	clsStackTest.Print("Popped all");

}
//------------------------------------------------------------------------
// Name: StackTestRef
// Abstract: Stack pass by ref
//------------------------------------------------------------------------
void StackTestRef(CStack &clsRef) {
	clsRef.Print("Stack Pass by Ref test");
}
//------------------------------------------------------------------------
// Name: StackTestVal
// Abstract: Stack pass by Val
//------------------------------------------------------------------------
void StackTestVal(CStack clsVal) {
	clsVal.Print("Stack Pass by Val test");
}
//------------------------------------------------------------------------
// Name: QueueTests
// Abstract: Testing Queue class
//------------------------------------------------------------------------
void QueueTests() {
	CQueue clsQueueTest = CQueue();
	for (int i = 1; i < 10; i++) {
		clsQueueTest.Push(i);
	}
	clsQueueTest.Print("list");

	clsQueueTest.Pop();
	clsQueueTest.Print("pop");
	clsQueueTest.Push(999);
	clsQueueTest.Print("Push");
	clsQueueTest.Print("Before ref");
	QueueTestRef(clsQueueTest);
	clsQueueTest.Print("after ref");
	clsQueueTest.Print("Before val");
	QueueTestVal(clsQueueTest);
	clsQueueTest.Print("after val");
	for (int i = 0; i < 10; i++) {
		clsQueueTest.Pop();
	}
	clsQueueTest.Print("Popped all");

}
//------------------------------------------------------------------------
// Name: QueueTestRef
// Abstract: Queue pass by ref
//------------------------------------------------------------------------
void QueueTestRef(CQueue &clsRef) {
	clsRef.Print("Queue Pass by Ref test");
}
//------------------------------------------------------------------------
// Name: QueueTestVal
// Abstract: queue pass by val
//------------------------------------------------------------------------
void QueueTestVal(CQueue clsVal) {
	clsVal.Print("Queue Pass by Val test");
}


