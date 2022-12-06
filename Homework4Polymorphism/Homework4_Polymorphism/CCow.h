#pragma once
#include "CAnimal.h"
class CCow :
	public CAnimal
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:

	char m_strColor[50];

private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:

	void SetColor(const char* pstrColor);
	char* GetColor();

	virtual void MakeNoise();

	void Graze();

protected:

private:

};

