// --------------------------------------------------------------------------------
// Name: CStack
// Abstract: This class ...
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Include this file only once even if referenced multiple times

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CNode.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class CStack
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:


private:
	CNode* m_pclsHeadNode;

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	//Constructors
	CStack();
	CStack(const CStack &clsOriginal);
	~CStack();


	//deep copy
	void operator=(const CStack &clsOriginal);

	//add value to front of stack
	void Push(int intValue);
	//remove and return from top of stack
	int Pop();
	//return true if head node pointer == 0
	bool IsEmpty() const;
	//prints list
	void Print() const;
	void Print(const char* strMessage) const;

protected:

private:
	//init to 0
	void Initialize();
	//deep copy
	void DeepCopy(const CStack &clsOriginal);
	// delete list
	void CleanUp();
};
