// --------------------------------------------------------------------------------
// Name: CClassName
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CAnimal.h"


// --------------------------------------------------------------------------------
// Name: SetValue
// Abstract: Set the value
// --------------------------------------------------------------------------------

void CAnimal::SetName(const char * pstrName)
{
	if (strlen(pstrName) < 50) {
		strcpy_s(m_strName, pstrName);
	}
}

char * CAnimal::GetName()
{
	return m_strName;
}

void CAnimal::SetType(const char * pstrType)
{
	if (strlen(pstrType) < 50) {
		strcpy_s(m_strType, pstrType);
	}
}

char * CAnimal::GetType()
{
	return m_strType;
}

void CAnimal::MakeNoise()
{
	cout << "Undefined\n";
}
