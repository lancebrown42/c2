#include "CSuperString.h"
#include <string.h>

char* CSuperString::CloneString(const char* pstrSource) {
	char* pstrClone = 0;
	long lngLength = 0;

	if (pstrSource != 0) {
		lngLength = strlen(pstrSource);
		pstrClone = new char[lngLength + 1];
		strcpy_s(pstrClone, lngLength + 1, pstrSource);
	}
	else
	{
		pstrClone = new char[1];
		*(pstrClone + 0) = 0;
	}
	return pstrClone;
}

CSuperString::~CSuperString() {
	CleanUp();
}

CSuperString::CleanUp() {

}