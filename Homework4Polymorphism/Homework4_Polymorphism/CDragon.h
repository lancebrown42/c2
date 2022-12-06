#pragma once
#include "CAnimal.h"
class CDragon :
	public CAnimal
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:

	int m_intGoldCoins;

private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	void SetGoldCoins(int intGoldCoins);
	int GetGoldCoins();

	virtual void MakeNoise();

	void BreatheFire();

protected:

private:

};

