// --------------------------------------------------------------------------------
// Name: CDog
// Abstract: Defines a dog with weight and name properties and bark method
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CDog.h"


// --------------------------------------------------------------------------------
// Name: SetWeight
// Abstract: Set the weight
// --------------------------------------------------------------------------------
void CDog::SetWeight(float sngWeight)
{
	// Boundary check
	if (sngWeight < 0)
	{
		// Clip to prevent negative value
		sngWeight = 0;
	}

	m_sngWeight = sngWeight;
}


// --------------------------------------------------------------------------------
// Name: GetWeight
// Abstract: Get the weight
// --------------------------------------------------------------------------------
float  CDog::GetWeight()
{
	return m_sngWeight;
}

// --------------------------------------------------------------------------------
// Name: SetName
// Abstract: Set the name
// --------------------------------------------------------------------------------
void CDog::SetName(string strName)
{
	// Boundary check
	if (strName.length() <= 0)
	{
		strName = "";
	}

	m_strName = strName;
}


// --------------------------------------------------------------------------------
// Name: GetName
// Abstract: Get the Name
// --------------------------------------------------------------------------------
string CDog::GetName()
{
	return m_strName;
}

// --------------------------------------------------------------------------------
// Name: DoSomething
// Abstract: Do something
// --------------------------------------------------------------------------------
void CDog::Bark()
{
	if (this->GetWeight() < 15.0f) {
		cout << "Yip, yip, yip\n";
	}
	else {
		cout << "Woof, woof\n";
	}
	
}

