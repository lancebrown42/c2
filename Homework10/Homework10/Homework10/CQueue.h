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
	CQueue(const CQueue &clsOriginalToCopy);
	~CQueue();
	
	//assignment deep copy
	void operator=(const CQueue &clsOriginalToCopy);

	//Append value
	void Push(int intValue);
	// remove and return first value
	int Pop();
	//returns true if head == 0
	bool IsEmpty()const;
	//print
	void Print() const;


protected:

private:
	void Initialize();
	CQueue DeepCopy(const CQueue &clsOriginalToCopy);
	void CleanUp();
};
