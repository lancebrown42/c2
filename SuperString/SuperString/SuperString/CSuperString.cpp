#include "CSuperString.h"
#include <string.h>
#include <sstream>



CSuperString::CSuperString()
{
	char* ssStringToCopy;
	Initialize("", NULL, '0', NULL,NULL,NULL,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const char * pstrStringToCopy)
{
	char* ssStringToCopy;
	Initialize(pstrStringToCopy, NULL, '0', NULL,NULL,NULL,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	char* ssStringToCopy;
	Initialize("", blnBooleanToCopy, '0', NULL,NULL,NULL,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const char chrLetterToCopy)
{
	char* ssStringToCopy;
	Initialize("", NULL, chrLetterToCopy, NULL,NULL,NULL,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const short shtShortToCopy)
{
	char* ssStringToCopy;
	Initialize("", NULL, '0', shtShortToCopy,NULL,NULL,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const int intIntegerToCopy)
{
	char* ssStringToCopy;
	Initialize("", NULL, '0', NULL,intIntegerToCopy,NULL,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const long lngLongToCopy)
{
	char* ssStringToCopy;
	Initialize("", NULL, '0', NULL,NULL,lngLongToCopy,NULL, NULL, ssStringToCopy);
}

CSuperString::CSuperString(const float sngFloatToCopy)
{
	char* ssStringToCopy;
	Initialize("", NULL, '0', NULL,NULL,NULL,sngFloatToCopy, NULL, ssStringToCopy);

}

CSuperString::CSuperString(const double dblDoubleToCopy)
{
	char* ssStringToCopy;
	Initialize("", NULL, '0', NULL,NULL,NULL,NULL, dblDoubleToCopy, ssStringToCopy);

}

CSuperString::CSuperString(const CSuperString & ssStringToCopy)
{
	char* sstring = ssStringToCopy.m_pstrSuperString;
		Initialize("", NULL, '0', NULL,NULL,NULL,NULL, NULL, sstring);
}
void CSuperString::Initialize(const char * pstrStringToCopy, const bool blnBooleanToCopy, const char chrLetterToCopy, const short shtShortToCopy, const int intIntegerToCopy, const long lngLongToCopy, const float sngFloatToCopy, const double dblDoubleToCopy, char* & ssStringToCopy){
	char const* strValue;
	if(pstrStringToCopy != ""){
		strValue = (char*) pstrStringToCopy;
	}
	else if(blnBooleanToCopy != NULL){
		if(blnBooleanToCopy == true){
			strValue = "true";
		}
		else{
			strValue = "false";
		}
	}else if(chrLetterToCopy != '0'){
		strValue = (char*) &chrLetterToCopy;
	}else if(shtShortToCopy != NULL){
		stringstream ss;
		ss<<shtShortToCopy;
		strValue = ss.c_str();
	}
	
	this->m_pstrSuperString = (char*) strValue;
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
	return osOut << ssOutput.m_pstrSuperString;
}

istream & operator>>(istream & isIn, CSuperString & ssInput)
{
	isIn >> ssInput.m_pstrSuperString;
	return isIn;
}

char* CSuperString::CloneString(const char* pstrSource) {
	char* pstrClone = 0;
	long lngLength = 0;

	if (pstrSource != 0) {
		lngLength = strlen(pstrSource);
		pstrClone = new char[lngLength + 1];
		strcpy(pstrClone, lngLength + 1, pstrSource);
	}
	else
	{
		pstrClone = new char[1];
		*(pstrClone + 0) = 0;
	}
	return pstrClone;
}

