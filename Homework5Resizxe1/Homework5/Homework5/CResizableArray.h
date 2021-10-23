// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: This class represents an array of longs with methods to modify
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

class CResizableArray
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:			 


protected:

	int m_intValue;

private:
	long m_lngArraySize;
	long* m_palngValues;
	

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:
	// Initialize
	void Initialize();

	//Size
	void SetSize(long lngNewSize);
	long GetSize();

	// Bracket operator overload
	unsigned long operator [](long i) const {
		return *(m_palngValues + i);
	}
	unsigned const long & operator [](long i) {
		return *(m_palngValues + i);
	}

	// Value
	void SetValueAt(long lngValue, long lngIndex);
	long GetValueAt(long lngIndex);

	//Insertions
	void AddValueToFront(long lngValue);
	void AddValueToEnd(long lngValue);
	void InsertValueAt(long lngValue, long lngIndex);

	//Deletion
	void RemoveAt(long lngIndex);

	//Display
	void Print();
	void Print( char* pstrMessage);
	

protected:

private:

};
