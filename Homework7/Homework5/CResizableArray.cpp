// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Object representing an array of longs with methods to modify it
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CResizableArray.h"
using namespace std;
// --------------------------------------------------------------------------------
// Name: Constructors
// Abstract: Constructors
// --------------------------------------------------------------------------------

CResizableArray::CResizableArray() {

	Initialize(0, 0);
}
CResizableArray::CResizableArray(long lngInitialSize) {
	Initialize(lngInitialSize, 0);

}
CResizableArray::CResizableArray(long lngInitialSize, long lngDefaultValue) {
	Initialize(lngInitialSize, lngDefaultValue);
}

// --------------------------------------------------------------------------------
// Name: Destructor
// Abstract: Destructor
// --------------------------------------------------------------------------------

CResizableArray::~CResizableArray() {
	CleanUp();
}

// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: Garbage Collecting
// --------------------------------------------------------------------------------
void CResizableArray::CleanUp() {
	SetSize(0, 0);
}

// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Initializes object
// --------------------------------------------------------------------------------
void CResizableArray::Initialize(long lngInitialSize, long lngDefaultValue) {
	m_lngArraySize = 0;
	m_palngValues =  0;
	SetSize(lngInitialSize, lngDefaultValue);
	
}
// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints array contents with default header
// --------------------------------------------------------------------------------

void CResizableArray::Print() {
	if (m_lngArraySize > 0) {
		Print((char*) "Array");

	}
}
// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints array contents with parameterized header
// --------------------------------------------------------------------------------

void CResizableArray::Print(char* pstrMessage) {
	printf("----------%s---------\n", pstrMessage);
	if (m_lngArraySize > 0) {
		
		for (int i = 0; i < m_lngArraySize; i++) {
			printf("Index: %ld\tValue: %ld\n", i, *(m_palngValues + i));
		}

	}
}

// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Sets size of array
// --------------------------------------------------------------------------------

void CResizableArray::SetSize(long lngNewSize) {
	SetSize(lngNewSize, 0);
}
// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Sets size of array
// --------------------------------------------------------------------------------

void CResizableArray::SetSize(long lngNewSize, long lngDefaultValue) {
	long* palngNewValues = 0;
	long lngTerm = 0;
	
	if (lngNewSize < 0) lngNewSize = 0;
	if (lngNewSize > 100000) lngNewSize = 100000;
	if (lngNewSize != m_lngArraySize) {
		if (lngNewSize > 0)
		{
			palngNewValues = new long[lngNewSize];

		}
		for (int i = 0; i < lngNewSize; i++) {
			*(palngNewValues + i) = lngDefaultValue;
		}
		if (lngNewSize < m_lngArraySize) {
			lngTerm = lngNewSize;
		}
		else {
			lngTerm = m_lngArraySize;
		}
		for (int i = 0; i < lngTerm; i++) {
			*(palngNewValues + i) = *(m_palngValues + i);
		}
		if (m_palngValues != 0) {
			delete[] m_palngValues;
			m_palngValues = 0;

		}

		m_palngValues = palngNewValues;
		m_lngArraySize = lngNewSize;
		
	}
	




}
// --------------------------------------------------------------------------------
// Name: GetSize
// Abstract: Returns size of array
// --------------------------------------------------------------------------------

long CResizableArray::GetSize() {
	return m_lngArraySize;
}

// --------------------------------------------------------------------------------
// Name: SetValueAt
// Abstract: Sets the value at given index
// --------------------------------------------------------------------------------

void CResizableArray::SetValueAt(long lngValue, long lngIndex) {
	if (m_lngArraySize > 0) {
		if (lngIndex < 0) {
			lngIndex = 0;
		}
		if (lngIndex > m_lngArraySize - 1) {
			lngIndex = m_lngArraySize - 1;
		}
		*(m_palngValues + lngIndex) = lngValue;
	}
	m_palngValues[lngIndex] = lngValue;
}
// --------------------------------------------------------------------------------
// Name: GetValueAt
// Abstract: Gets value at given index
// --------------------------------------------------------------------------------

long CResizableArray::GetValueAt(long lngIndex) {
	long lngValue = 0;
	if (m_lngArraySize > 0) {
		if (lngIndex < 0) {
			lngIndex = 0;
		}
		if (lngIndex > m_lngArraySize - 1) {
			lngIndex = m_lngArraySize - 1;
		}
		lngValue = *(m_palngValues + lngIndex);
	}
	return lngValue;
}
// --------------------------------------------------------------------------------
// Name: AddValueToFront
// Abstract: Prepends value to array
// --------------------------------------------------------------------------------

void CResizableArray::AddValueToFront(long lngValue) {
	long* palngNewVals = 0;

	palngNewVals = new long[GetSize() + 1];

	*palngNewVals = lngValue;
	for (long i = 0; i < GetSize(); i++) {
		*(palngNewVals + i + 1) = GetValueAt(i);
	}
	delete[] m_palngValues;
	m_palngValues = 0;

	m_palngValues = palngNewVals;
	m_lngArraySize++;
}
// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: Appends value to array
// --------------------------------------------------------------------------------

void CResizableArray::AddValueToEnd(long lngValue) {
	long* palngNewVals = 0;

	palngNewVals = new long[GetSize() + 1];

	*(palngNewVals + GetSize()) = lngValue;
	for (long i = GetSize()-1; i >= 0; i--) {
		*(palngNewVals + i) = GetValueAt(i);
	}
	delete[] m_palngValues;
	m_palngValues = 0;

	m_palngValues = palngNewVals;
	m_lngArraySize++;
}
// --------------------------------------------------------------------------------
// Name: InsertValueAt
// Abstract: Inserts given value at given index
// --------------------------------------------------------------------------------

void CResizableArray::InsertValueAt(long lngValue, long lngIndex) {
	long* palngNewVals = 0;
	
	if (lngIndex < 0) {
		lngIndex = 0;
	}
	if (lngIndex > m_lngArraySize - 1) {
		lngIndex = m_lngArraySize - 1;
	}
	palngNewVals = new long[GetSize() + 1];

	for (long i = 0; i < lngIndex; i++) {
		*(palngNewVals + i) = GetValueAt(i);
	}
	*(palngNewVals + lngIndex) = lngValue;
	for (long i = lngIndex; i < GetSize(); i++) {
		*(palngNewVals + i + 1) = GetValueAt(i);
	}
	delete[] m_palngValues;
	m_palngValues = 0;

	m_palngValues = palngNewVals;
	m_lngArraySize++;
}
// --------------------------------------------------------------------------------
// Name: RemoveAt
// Abstract: Removes value at given index.
// --------------------------------------------------------------------------------

void CResizableArray::RemoveAt(long lngIndex) {
	long* palngNewVals = 0;

	if (lngIndex < 0) {
		lngIndex = 0;
	}
	if (lngIndex > m_lngArraySize - 1) {
		lngIndex = m_lngArraySize - 1;
	}
	palngNewVals = new long[GetSize() - 1];

	for (long i = 0; i < lngIndex; i++) {
		*(palngNewVals + i) = GetValueAt(i);
	}
	for (long i = lngIndex+1; i < GetSize(); i++) {
		*(palngNewVals + i - 1) = GetValueAt(i);
	}
	delete[] m_palngValues;
	m_palngValues = 0;

	m_palngValues = palngNewVals;
	m_lngArraySize--;
}