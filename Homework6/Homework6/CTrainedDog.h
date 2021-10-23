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
#include "CDog.h"
using namespace std;

class CTrainedDog: CDog

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
	char* m_pstrBreed;


	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	void SetBreed(const char* strNewBreed);

	const char* GetBreed();
	const void Fetch();
	const void PlayDead();
	const void Print();
	

protected:


private:



	//------------------------------------------
	//Constructors
	//------------------------------------------

public:
	//Default Constructor
	CTrainedDog();

	//Parameterized constructors
	CTrainedDog(const char* pstrName);
	CTrainedDog(const char* pstrName, int intAge);
	CTrainedDog(const char* pstrName, int intAge, float sngWeight);
	CTrainedDog(const char* pstrName, int intAge, float sngWeight, const char* pstrBreed);

	//Destructor
	~CTrainedDog();
protected:
	void initialize(const char* pstrName, int intAge, float sngWeight, const char* pstrBreed);
	void CleanUp();



};