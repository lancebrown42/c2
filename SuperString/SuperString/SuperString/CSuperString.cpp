#include "CSuperString.h"
#include <string.h>


CSuperString::CSuperString()
{
	Initialize("", false, '', 0,0,0,0f, 0, new CSuperString())
}

CSuperString::CSuperString(const char * pstrStringToCopy)
{
}

CSuperString::CSuperString(const bool blnBooleanToCopy)
{
}

CSuperString::CSuperString(const char chrLetterToCopy)
{
}

CSuperString::CSuperString(const short shtShortToCopy)
{
}

CSuperString::CSuperString(const int intIntegerToCopy)
{
}

CSuperString::CSuperString(const long lngLongToCopy)
{
}

CSuperString::CSuperString(const float sngFloatToCopy)
{
}

CSuperString::CSuperString(const double dblDoubleToCopy)
{
}

CSuperString::CSuperString(const CSuperString & ssStringToCopy)
{
}
CSuperString CSuperString::Initialize(const char * pstrStringToCopy, const bool blnBooleanToCopy, const char chrLetterToCopy, const short shtShortToCopy, const int intIntegerToCopy, const long lngLongToCopy, const float sngFloatToCopy, const double dblDoubleToCopy, const CSuperString & ssStringToCopy){
	return new CSuperString();
}
CSuperString::~CSuperString() {
	CleanUp();
}

void CSuperString::CleanUp()
{
}

long CSuperString::Length() const
{
	return 0;
}

void CSuperString::operator=(const char * pstrStringToCopy)
{
}

void CSuperString::operator=(const char chrLetterToCopy)
{
}

void CSuperString::operator=(const CSuperString & ssStringToCopy)
{
}

void CSuperString::operator+=(const char * pstrStringToAppend)
{
}

void CSuperString::operator+=(const char chrCharacterToAppend)
{
}

void CSuperString::operator+=(const CSuperString & ssStringToAppend)
{
}

long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	return 0;
}

long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	return 0;
}

long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	return 0;
}

long CSuperString::FindFirstIndexOf(const char * pstrSubStringToFind)
{
	return 0;
}

long CSuperString::FindFirstIndexOf(const char * pstrSubStringToFind, long lngStartIndex)
{
	return 0;
}

long CSuperString::FindLastIndexOf(const char * pstrSubStringToFind)
{
	return 0;
}

const char * CSuperString::ToUpperCase()
{
	return nullptr;
}

const char * CSuperString::ToLowerCase()
{
	return nullptr;
}

const char * CSuperString::TrimLeft()
{
	return nullptr;
}

const char * CSuperString::TrimRight()
{
	return nullptr;
}

const char * CSuperString::Trim()
{
	return nullptr;
}

const char * CSuperString::Reverse()
{
	return nullptr;
}

const char * CSuperString::Left(long lngCharactersToCopy)
{
	return nullptr;
}

const char * CSuperString::Right(long lngCharactersToCopy)
{
	return nullptr;
}

const char * CSuperString::Substring(long lngStart, long lngSubStringLength)
{
	return nullptr;
}

const char * CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	return nullptr;
}

const char * CSuperString::Replace(const char * pstrFind, const char * pstrReplace)
{
	return nullptr;
}

const char * CSuperString::Insert(const char chrLetterToInsert, long lngIndex)
{
	return nullptr;
}

const char * CSuperString::Insert(const char * pstrSubString, long lngIndex)
{
	return nullptr;
}

char & CSuperString::operator[](long lngIndex)
{
	// TODO: insert return statement here
}

const char & CSuperString::operator[](long lngIndex) const
{
	// TODO: insert return statement here
}

const char * CSuperString::ToString()
{
	return nullptr;
}

bool CSuperString::ToBoolean()
{
	return false;
}

short CSuperString::ToShort()
{
	return 0;
}

int CSuperString::ToInteger()
{
	return 0;
}

long CSuperString::ToLong()
{
	return 0;
}

float CSuperString::ToFloat()
{
	return 0.0f;
}

double CSuperString::ToDouble()
{
	return 0.0;
}


CSuperString operator+(const CSuperString & ssLeft, const CSuperString & ssRight)
{
	return CSuperString();
}

CSuperString operator+(const char * pstrLeftSide, const CSuperString & ssRightString)
{
	return CSuperString();
}

CSuperString operator+(const CSuperString & ssLeftString, const char * pstrRightSide)
{
	return CSuperString();
}

ostream & operator<<(ostream & osOut, const CSuperString & ssOutput)
{


}

istream & operator>>(istream & isIn, CSuperString & ssInput)
{

}

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

