// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: This class represents an array of longs with methods to modify
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#ifndef CRESIZABLE_ARRAY_H
#define CRESIZABLE_ARRAY_H


// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;

template <typename GenericDataType>
class CResizableArray
{
	// --------------------------------------------------------------------------------
	// Constructors
	// --------------------------------------------------------------------------------
public:
	CResizableArray();
	CResizableArray(long lngInitialSize);
	CResizableArray(long lngInitialSize, GenericDataType lngDefaultValue);
	~CResizableArray();


protected:
private:




	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
public:


protected:

	int m_intValue;
	long m_lngArraySize;
	GenericDataType* m_palngValues;

private:


	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
public:


	//Size
	void SetSize(long lngNewSize);
	void SetSize(long lngNewSize, GenericDataType lngValue);
	long GetSize();

	// Bracket operator overload
	GenericDataType &operator [](long i)  {
		return (GenericDataType) *(m_palngValues + i);
	}
	const GenericDataType & operator [](long i) const {
		return (GenericDataType) *(m_palngValues + i);
	}

	// Value
	void SetValueAt(GenericDataType lngValue, long lngIndex);
	GenericDataType GetValueAt(long lngIndex);

	//Insertions
	void AddValueToFront(GenericDataType lngValue);
	void AddValueToEnd(GenericDataType lngValue);
	void InsertValueAt(GenericDataType lngValue, long lngIndex);

	//Deletion
	void RemoveAt(long lngIndex);

	//Display
	void Print();
	void Print(const char* pstrMessage) const;


protected:
	// Initialize
	void Initialize(long lngInitialSize, GenericDataType lngDefaultValue);
	// CleanUp
	void CleanUp();
private:

};
#include "CResizableArray.cpp"
#endif // !CRESIZABLE_ARRAY_H
