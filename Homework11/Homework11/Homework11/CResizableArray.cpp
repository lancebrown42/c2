// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Object representing an array of longs with methods to modify it
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#ifndef CRESIZABLE_ARRAY_CPP
#define CRESIZABLE_ARRAY_CPP
// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CResizableArray.h"
using namespace std;
// --------------------------------------------------------------------------------
// Name: Constructors
// Abstract: Constructors
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray() {

	Initialize(0, 0);
}
template <typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray(long lngInitialSize) {
	Initialize(lngInitialSize, 0);

}
template <typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray(long lngInitialSize, GenericDataType lngDefaultValue) {
	Initialize(lngInitialSize, lngDefaultValue);
}

// --------------------------------------------------------------------------------
// Name: Destructor
// Abstract: Destructor
// --------------------------------------------------------------------------------
template <typename GenericDataType>
CResizableArray<GenericDataType>::~CResizableArray() {
	CleanUp();
}

// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: Garbage Collecting
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::CleanUp() {
	Initialize(0, 0);
}

// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Initializes object
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::Initialize(long lngInitialSize, GenericDataType lngDefaultValue) {
	m_lngArraySize = 0;
	m_palngValues = 0;
	SetSize(lngInitialSize, lngDefaultValue);

}
// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints array contents with default header
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::Print() {
	if (m_lngArraySize > 0) {
		Print((char*) "Array");

	}
}
// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Prints array contents with parameterized header
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::Print(const char* pstrMessage) {
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
template <typename GenericDataType>
void CResizableArray<GenericDataType>::SetSize(long lngNewSize) {
	SetSize(lngNewSize, 0);
}
// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Sets size of array
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::SetSize(long lngNewSize, GenericDataType lngDefaultValue) {
	GenericDataType* palngNewValues = 0;
	long lngTerm = 0;

	if (lngNewSize < 0) lngNewSize = 0;
	if (lngNewSize > 100000) lngNewSize = 100000;
	if (lngNewSize != m_lngArraySize) {
		if (lngNewSize > 0)
		{
			palngNewValues = new GenericDataType[lngNewSize];

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
template <typename GenericDataType>
long CResizableArray<GenericDataType>::GetSize() {
	return m_lngArraySize;
}

// --------------------------------------------------------------------------------
// Name: SetValueAt
// Abstract: Sets the value at given index
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::SetValueAt(GenericDataType lngValue, long lngIndex) {
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
template <typename GenericDataType>
GenericDataType CResizableArray<GenericDataType>::GetValueAt(long lngIndex) {
	GenericDataType lngValue = 0;
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
template <typename GenericDataType>
void CResizableArray<GenericDataType>::AddValueToFront(GenericDataType lngValue) {
	GenericDataType* palngNewVals = 0;

	palngNewVals = new GenericDataType[GetSize() + 1];

	*palngNewVals = lngValue;
	for (long i = 0; i < GetSize(); i++) {
		*(palngNewVals + i + 1) = GetValueAt(i);
	}
	/*delete[] m_palngValues;*/
	m_palngValues = 0;

	m_palngValues = palngNewVals;
	m_lngArraySize++;
}
// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: Appends value to array
// --------------------------------------------------------------------------------
template <typename GenericDataType>
void CResizableArray<GenericDataType>::AddValueToEnd(GenericDataType lngValue) {
	GenericDataType* palngNewVals = 0;

	palngNewVals = new GenericDataType[GetSize() + 1];

	*(palngNewVals + GetSize()) = lngValue;
	for (long i = GetSize() - 1; i >= 0; i--) {
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
template <typename GenericDataType>
void CResizableArray<GenericDataType>::InsertValueAt(GenericDataType lngValue, long lngIndex) {
	GenericDataType* palngNewVals = 0;

	if (lngIndex < 0) {
		lngIndex = 0;
	}
	if (lngIndex > m_lngArraySize - 1) {
		lngIndex = m_lngArraySize - 1;
	}
	palngNewVals = new GenericDataType[GetSize() + 1];

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
template <typename GenericDataType>
void CResizableArray<GenericDataType>::RemoveAt(long lngIndex) {
	GenericDataType* palngNewVals = 0;

	if (lngIndex < 0) {
		lngIndex = 0;
	}
	if (lngIndex > m_lngArraySize - 1) {
		lngIndex = m_lngArraySize - 1;
	}
	palngNewVals = new GenericDataType[GetSize() - 1];

	for (long i = 0; i < lngIndex; i++) {
		*(palngNewVals + i) = GetValueAt(i);
	}
	for (long i = lngIndex + 1; i < GetSize(); i++) {
		*(palngNewVals + i - 1) = GetValueAt(i);
	}
	delete[] m_palngValues;
	m_palngValues = 0;

	m_palngValues = palngNewVals;
	m_lngArraySize-=1;
}
#endif