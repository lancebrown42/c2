
// --------------------------------------------------------------------------------
// Name: CClassName
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CDog.h"

// --------------------------------------------------------------------------------
// Name: SetName
// Abstract: Set the name
// --------------------------------------------------------------------------------
void CDog::SetName(const char* strNewName)
{
	char* buffer = new char[];
	if (strlen(strNewName) >= 49) {
		char* buffer = new char[49];
	}
	else {
		char* buffer = new char[strlen(strNewName)];
	}
	strcpy(buffer, strNewName);
	strcpy(m_pstrName, buffer);

}


// --------------------------------------------------------------------------------
// Name: GetName
// Abstract: Get the name
// --------------------------------------------------------------------------------
const char* CDog::GetName()
{
	return m_pstrName;
}

// --------------------------------------------------------------------------------
// Name: SetAge
// Abstract: Set the age
// --------------------------------------------------------------------------------
void CDog::SetAge(int intNewAge)
{
	if (intNewAge < 0) {
		intNewAge = 0;
	}
	if (intNewAge >= 0 && intNewAge < 40) {

		m_intAge = intNewAge;
	}
}


// --------------------------------------------------------------------------------
// Name: GetAge
// Abstract: Get the age
// --------------------------------------------------------------------------------
const int CDog::GetAge()
{
	return m_intAge;
}

// --------------------------------------------------------------------------------
// Name: SetWeight
// Abstract: Set the weight
// --------------------------------------------------------------------------------
void CDog::SetWeight(float sngNewWeight)
{
	if (sngNewWeight < 0) {
		sngNewWeight = 0;
	}
	if (sngNewWeight >= 0 && sngNewWeight < 500) {

		m_sngWeight = sngNewWeight;
	}
}


// --------------------------------------------------------------------------------
// Name: GetWeight
// Abstract: Get the weight
// --------------------------------------------------------------------------------
const float CDog::GetWeight()
{
	return m_sngWeight;
}

//Default Constructor
CDog::CDog() {
	initialize("", 0, 0);
}

//Parameterized constructors
CDog::CDog(const char* pstrName) {
	initialize(m_pstrName, 0, 0);

}
CDog::CDog(const char* pstrName, int intAge) {
	initialize(m_pstrName, m_intAge, 0);
}
CDog::CDog(const char* pstrName, int intAge, float sngWeight) {
	initialize(m_pstrName, m_intAge, m_sngWeight);
}

//initialization
void CDog::initialize(const char* pstrName, int intAge, float sngWeight) {
	SetName(pstrName);
	SetAge(intAge);
	SetWeight(sngWeight);

}


