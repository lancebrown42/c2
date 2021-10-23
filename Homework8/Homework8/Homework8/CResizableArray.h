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
	// Constructors
	// --------------------------------------------------------------------------------
public:
	CResizableArray();
	CResizableArray(long lngInitialSize);
	CResizableArray(long lngInitialSize, long lngDefaultValue);
	CResizableArray(const CResizableArray &clsOriginal);
	~CResizableArray();


protected:
private:




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


	//Size
	void SetSize(long lngNewSize);
	void SetSize(long lngNewSize, long lngValue);
	const long GetSize() const;
	//const long GetSize();

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
	void Print(char* pstrMessage);

	//Assignment
	void operator = (const CResizableArray &clsOriginal);
	
	//Bracket Operator
	long& operator[] (long index);
	const long& operator[] (long index) const;

	//PlusEqual
	void operator += (const CResizableArray &clsOriginal);

	//Plus
	CResizableArray operator + (const CResizableArray &clsRight) const;

protected:
	// Initialize
	void Initialize(long lngInitialSize, long lngDefaultValue);
	// CleanUp
	void CleanUp();
	//DeepCopy
	void DeepCopy(const CResizableArray &clsOriginal);
private:

};
