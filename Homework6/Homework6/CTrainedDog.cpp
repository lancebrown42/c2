
// --------------------------------------------------------------------------------
// Name: CClassName
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CTrainedDog.h"

// --------------------------------------------------------------------------------
// Name: SetBreed
// Abstract: Set the breed
// --------------------------------------------------------------------------------
void CTrainedDog::SetBreed(const char* strNewBreed)
{
	char* buffer = new char[49];
	if (strlen(strNewBreed) >= 49) {
		char* buffer = new char[49];
	}
	else {
		char* buffer = new char[strlen(strNewBreed)];
	}
	strcpy(buffer, strNewBreed);
	strcpy(m_pstrBreed, buffer);

}


// --------------------------------------------------------------------------------
// Name: GetBreed
// Abstract: Get the breed
// --------------------------------------------------------------------------------
const char* CTrainedDog::GetBreed()
{
	return m_pstrBreed;
}
// --------------------------------------------------------------------------------
// Name: Fetch
// Abstract: Prints a fetch message
// --------------------------------------------------------------------------------
const void CTrainedDog::Fetch() {
	printf("Fetching the stick!\n");
}
// --------------------------------------------------------------------------------
// Name: PlayDead
// Abstract: Prints a play dead message
// --------------------------------------------------------------------------------
const void CTrainedDog::PlayDead() {
	printf("I'm dead.\n");
}

// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints everything
// --------------------------------------------------------------------------------
const void CTrainedDog::Print() {
	printf("Name: %s\nAge: %d\nWeight: %f\nBark: ", GetName(), GetAge(), GetWeight());
	Bark();
	Fetch();
	PlayDead();
}
//Default Constructor
CTrainedDog::CTrainedDog() {
	initialize("", 0, 0,"");
}

//Parameterized constructors
CTrainedDog::CTrainedDog(const char* pstrName) {
	initialize(pstrName, 0, 0,"");

}
CTrainedDog::CTrainedDog(const char* pstrName, int intAge) {
	initialize(pstrName, intAge, 0,"");
}
CTrainedDog::CTrainedDog(const char* pstrName, int intAge, float sngWeight) {
	initialize(pstrName, intAge, sngWeight, "");
}
CTrainedDog::CTrainedDog(const char* pstrName, int intAge, float sngWeight, const char* pstrBreed) {
	initialize(pstrName, intAge, sngWeight, pstrBreed);
}

//initialization
void CTrainedDog::initialize(const char* pstrName, int intAge, float sngWeight, const char* pstrBreed) {
	SetName(pstrName);
	SetAge(intAge);
	SetWeight(sngWeight);

}
//Destructor
CTrainedDog::~CTrainedDog() {
	CleanUp();
}
//clear memory
void CTrainedDog::CleanUp() {
	DeleteString(m_pstrBreed);
}



