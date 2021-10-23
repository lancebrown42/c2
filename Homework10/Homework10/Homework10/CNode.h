// --------------------------------------------------------------------------------
// Name: CNode
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
using namespace std;

class CNode
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:


private:
	int m_intValue;
	CNode* m_pclsNextNode;


	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	//Constructors
	CNode();
	CNode(int intValue);
	CNode(int intValue, CNode* pclsNextNode);
	//shallow copy
	CNode(const CNode &clsOriginal);
	~CNode();

	//Shallow copy
	void operator = (const CNode &clsOriginal);
	//get/set
	void SetValue(int intNewValue);
	int GetValue();

	void SetNextNode(CNode* pclsNextNode);
	CNode* GetNextNode();



protected:

private:

	void ShallowCopy(const CNode &clsOriginal);
};
