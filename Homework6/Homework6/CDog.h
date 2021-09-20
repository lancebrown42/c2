
// --------------------------------------------------------------------------------
// Name: CDog
// Abstract: This class represents a dog.
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
	char* m_pstrName;
	int m_intAge;
	float m_sngWeight;


	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	// Name
	void SetName(const char* strNewName);
	const char* GetName();
	// Age
	void SetAge(int intNewAge);
	const int GetAge();
	// Weight
	void SetWeight(float fltNewWeight);
	const float GetWeight();


protected:

private:



//------------------------------------------
//Constructors
//------------------------------------------

public:
	//Default Constructor
	CDog();

	//Parameterized constructors
	CDog(const char* pstrName);
	CDog(const char* pstrName, int intAge);
	CDog(const char* pstrName, int intAge, float sngWeight);
protected:
	void initialize(const char* pstrName, int intAge, float sngWeight);


};



