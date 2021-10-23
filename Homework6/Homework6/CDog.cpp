
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
	int intLength = 0;
	int intIndex = 0;
	intLength = strlen(strNewName);
	
	if (intLength > 49) {
		intLength = 49;
	}
	DeleteString(m_pstrName);
	m_pstrName = new char[intLength + 1];
	for (int i = 0; i < intLength; i++) {
		*(m_pstrName + i) = *(strNewName + i);
	}
	*(m_pstrName + intLength) = 0;
	

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

// --------------------------------------------------------------------------------
// Name: Bark
// Abstract: Prints bark type
// --------------------------------------------------------------------------------
const void CDog::Bark() {
	if (GetWeight() < 15.0f) {
		printf("Yip, yip, yip\n");
	}
	else {
		printf("Woof, woof\n");
	}
}
// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints everything
// --------------------------------------------------------------------------------
const void CDog::Print() {
	printf("Name: %s\nAge: %d\nWeight: %f\nBark: ", GetName(), GetAge(), GetWeight());
	Bark();
}
//Default Constructor
CDog::CDog() {
	initialize("", 0, 0);
}

//Parameterized constructors
CDog::CDog(const char* pstrName) {
	initialize(pstrName, 0, 0);

}
CDog::CDog(const char* pstrName, int intAge) {
	initialize(pstrName, intAge, 0);
}
CDog::CDog(const char* pstrName, int intAge, float sngWeight) {
	initialize(pstrName, intAge, sngWeight);
}

//initialization
void CDog::initialize(const char* pstrName, int intAge, float sngWeight) {
	SetName(pstrName);
	SetAge(intAge);
	SetWeight(sngWeight);

}
//Destructor
CDog::~CDog(){
	CleanUp();
}
//clear memory
void CDog::CleanUp() {
	DeleteString(m_pstrName);
}
//Delete String
void CDog::DeleteString(char* &strDeleteMe) {
	if (strDeleteMe != 0) {
		delete[] strDeleteMe;
		strDeleteMe = 0;
	}
}


