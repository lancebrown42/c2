// --------------------------------------------------------------------------------
// Name: CQueue
// Abstract: This class ...
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Include this file only once even if referenced multiple times

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
#include "CNode.h"
using namespace std;

class CQueue
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:

	int m_intValue;

private:
	CNode* m_pclsHeadNode;
	CNode* m_pclsTailNode;
	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	//Constructors
	CQueue();
	CQueue(const CQueue &clsOriginal);
	~CQueue();


	//deep copy
	void operator=(const CQueue &clsOriginal);

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
	void DeepCopy(const CQueue &clsOriginal);
	// delete list
	void CleanUp();
};