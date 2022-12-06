// --------------------------------------------------------------------------------
// Name: CDog
// Abstract: Defines dog object
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

class CDog
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:



private:
	string m_strName;
	float m_sngWeight;
	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	// Value
	void SetWeight(float sngWeight);
	float GetWeight();
	void SetName(string strName);
	string GetName();

	// DoSomething
	void Bark();


protected:

private:

};
