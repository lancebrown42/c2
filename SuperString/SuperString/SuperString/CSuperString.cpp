#include "CSuperString.h"
#include <sstream>
/*
Constructors
*/
#pragma region
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to an empty string.
// --------------------------------------------------------------------------------
CSuperString::CSuperString()
{
	Initialize();
}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Copy constructor that initializes the CSuperString instance to the given CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const CSuperString &ssOriginalToCopy)
{
	Initialize();
	*this = ssOriginalToCopy;

}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given string.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char * pstrStringToCopy)
{
	Initialize();
	*this = pstrStringToCopy;
}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given boolean value.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	Initialize();
	if (blnBooleanToCopy) {
		*this = "true";
	}
	else {
		*this = "false";
	}
}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given character.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const char chrLetterToCopy)
{
	Initialize();
	*this = chrLetterToCopy;

}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given short integer.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const short shtShortToCopy)
{
	Initialize();
	char strSource[9] = "";
	sprintf_s(strSource, "%hd", shtShortToCopy);
	*this = strSource;
}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given integer.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const int intIntegerToCopy)
{
	Initialize();
	//char strSource[20] = "";
	//sprintf_s(strSource, "%i", intIntegerToCopy);
	*this = intIntegerToCopy;
}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given long integer.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const long lngLongToCopy)
{
	Initialize();
	char strSource[50] = "";
	sprintf_s(strSource, "%d", lngLongToCopy);
	*this = strSource;
}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given single-precision floating-point value.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const float sngFloatToCopy)
{
	Initialize();
	char strSource[50] = "";
	sprintf_s(strSource, "%f", sngFloatToCopy);
	*this = strSource;

}
// --------------------------------------------------------------------------------
// method: CSuperString
// description: Constructor that initializes the CSuperString instance to the given double-precision floating-point value.
// --------------------------------------------------------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy)
{
	Initialize();
	char strSource[50] = "";
	sprintf_s(strSource, "%f", dblDoubleToCopy);
	*this = strSource;

}

#pragma endregion

/*
Utility methods
*/
#pragma region
// --------------------------------------------------------------------------------
// method: Initialize
// description: Initializes the CSuperString instance to an empty string.
// --------------------------------------------------------------------------------
void CSuperString::Initialize(){

	m_pstrSuperString = 0;
	
}
// --------------------------------------------------------------------------------
// method: ~CSuperString
// description: Destructor for the CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString::~CSuperString() {
	CleanUp();
}
// --------------------------------------------------------------------------------
// method: DeepCopy
// description: Deep-copies the given string to the CSuperString instance.
// --------------------------------------------------------------------------------
void CSuperString::DeepCopy(const char * pstrSource)
{
	char* pstrCopy = 0;
	pstrCopy = CloneString(pstrSource);
	CleanUp();
	m_pstrSuperString = pstrCopy;
}
// --------------------------------------------------------------------------------
// method: CleanUp
// description: Cleans up the CSuperString instance.
// --------------------------------------------------------------------------------
void CSuperString::CleanUp()
{
	DeleteString(m_pstrSuperString);
}
// --------------------------------------------------------------------------------
// method: DeleteString
// description: Deletes the given string.
// --------------------------------------------------------------------------------
void CSuperString::DeleteString(char *& pstrSource)
{
	if (pstrSource != 0) {
		delete pstrSource;
		pstrSource = 0;
	}
}
// --------------------------------------------------------------------------------
// method: Length
// description: Returns the length of the CSuperString instance.
// --------------------------------------------------------------------------------
long CSuperString::Length() const
{
	if (m_pstrSuperString != nullptr) {
		return strlen(m_pstrSuperString);

	}
	else {
		return 0;
	}
	
}
void CSuperString::Print(const char* pstrCaption) const
{
	cout << endl;
	cout << pstrCaption << endl;
	cout << "-----------------------" << endl;
	if (Length() > 0) {
		cout << m_pstrSuperString << endl;
	}
	else {
		cout << "No string to print!" << endl;
	}
	cout << endl;
}

char* CSuperString::CloneString(const char* pstrSource) {
	char* pstrClone = 0;
	long lngLength = 0;


	lngLength = strlen(pstrSource);
	pstrClone = new char[lngLength + 1];
	strcpy_s(pstrClone, lngLength + 1, pstrSource);


	return pstrClone;
}


#pragma endregion

/*
 Operator overloads
*/
#pragma region
CSuperString& CSuperString::operator=(const char chrLetterToCopy)
{
	char chrLetter[2] = { chrLetterToCopy, 0 };
	*this = chrLetter;
	return *this;
}

CSuperString& CSuperString::operator=(const char *pstrStringToCopy)
{
	

	DeepCopy(pstrStringToCopy);

	return *this;
}

// --------------------------------------------------------------------------------
// method: operator=
// description: Overloads the assignment operator to assign the given CSuperString instance to the current CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString& CSuperString::operator=(const CSuperString &ssStringToCopy)
{
	DeepCopy(ssStringToCopy.ToString());

	return *this;
}
CSuperString& CSuperString::operator+=(const char *pstrStringToAppend)
{
	long lngLength = 0;
	char* pstrTemp = nullptr;

	if (m_pstrSuperString != nullptr)
	{
		lngLength = strlen(m_pstrSuperString);
	}

	pstrTemp = new char[lngLength + strlen(pstrStringToAppend) + 1];
	pstrTemp[0] = '\0';

	if (m_pstrSuperString != nullptr)
	{
		strcpy_s(pstrTemp, lngLength + 1, m_pstrSuperString);
	}
	strcat_s(pstrTemp, lngLength + strlen(pstrStringToAppend) + 1, pstrStringToAppend);

	if (m_pstrSuperString != nullptr)
	{
		CleanUp();
	}
	m_pstrSuperString = pstrTemp;

	return *this;
}

CSuperString& CSuperString::operator+=(const char chrCharacterToAppend)
{
	long lngLength = 0;
	char* pstrTemp = nullptr;

	if (m_pstrSuperString != nullptr)
	{
		lngLength = strlen(m_pstrSuperString);
	}

	pstrTemp = new char[lngLength + 2];
	pstrTemp[0] = '\0';

	if (m_pstrSuperString != nullptr)
	{
		strcpy_s(pstrTemp, lngLength + 1, m_pstrSuperString);
	}
	pstrTemp[lngLength] = chrCharacterToAppend;
	pstrTemp[lngLength + 1] = '\0';

	if (m_pstrSuperString != nullptr)
	{
		delete[] m_pstrSuperString;
	}
	m_pstrSuperString = pstrTemp;

	return *this;
}
CSuperString& CSuperString::operator+=(const CSuperString &ssStringToAppend)
{
	long lngLength = 0;
	char* pstrTemp = nullptr;

	if (m_pstrSuperString != nullptr)
	{
		lngLength = strlen(m_pstrSuperString);
	}

	pstrTemp = new char[lngLength + strlen(ssStringToAppend.m_pstrSuperString) + 1];
	pstrTemp[0] = '\0';

	if (m_pstrSuperString != nullptr)
	{
		strcpy_s(pstrTemp, lngLength + 1, m_pstrSuperString);
	}
	strcat_s(pstrTemp, lngLength + strlen(ssStringToAppend.m_pstrSuperString) + 1, ssStringToAppend.m_pstrSuperString);

	if (m_pstrSuperString != nullptr)
	{
		CleanUp();
	}
	m_pstrSuperString = pstrTemp;

	return *this;
}
CSuperString operator + (const CSuperString &ssLeft, const CSuperString &ssRight)
{
	CSuperString ssResult;

	ssResult = ssLeft;
	ssResult += ssRight;

	return ssResult;
}

CSuperString operator + (const char * pstrLeftSide, const CSuperString &ssRightString)
{
	CSuperString ssResult;

	ssResult += pstrLeftSide;
	ssResult += ssRightString;

	return ssResult;
}

CSuperString operator + (const CSuperString &ssLeftString, const char * pstrRightSide)
{
	CSuperString ssResult;

	ssResult += ssLeftString;
	ssResult += pstrRightSide;

	return ssResult;
}
#pragma endregion

/*
 FindIndexOf
*/
#pragma region
long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	return FindFirstIndexOf(chrLetterToFind, 0);
}

long CSuperString::FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex)
{
	long lngResult = -1;

	if (m_pstrSuperString != nullptr && lngStartIndex >= 0)
	{
		char chrToFind[2] = { chrLetterToFind, '\0' };
		const char* pstrFound = strstr(m_pstrSuperString + lngStartIndex, chrToFind);
		if (pstrFound != nullptr)
		{
			lngResult = pstrFound - m_pstrSuperString;
		}
	}

	return lngResult;
}

long CSuperString::FindLastIndexOf(const char chrLetterToFind)
{
	long lngResult = -1;

	if (m_pstrSuperString != nullptr)
	{
		char chrToFind[2] = { chrLetterToFind, '\0' };
		long lngStartIndex = 0;
		while (true)
		{
			const char* pstrFound = strstr(m_pstrSuperString + lngStartIndex, chrToFind);
			if (pstrFound != nullptr)
			{
				lngResult = pstrFound - m_pstrSuperString;
				lngStartIndex = lngResult + 1;
			}
			else
			{
				break;
			}
		}
	}

	return lngResult;
}

long CSuperString::FindFirstIndexOf(const char *pstrSubStringToFind)
{
	return FindFirstIndexOf(pstrSubStringToFind, 0);
}

long CSuperString::FindFirstIndexOf(const char *pstrSubStringToFind, long lngStartIndex)
{
	long lngResult = -1;

	if (m_pstrSuperString != nullptr && pstrSubStringToFind != nullptr && lngStartIndex >= 0)
	{
		const char* pstrFound = strstr(m_pstrSuperString + lngStartIndex, pstrSubStringToFind);
		if (pstrFound != nullptr)
		{
			lngResult = pstrFound - m_pstrSuperString;
		}
	}

	return lngResult;
}

long CSuperString::FindLastIndexOf(const char *pstrSubStringToFind)
{
	long lngResult = -1;

	if (m_pstrSuperString != nullptr && pstrSubStringToFind != nullptr)
	{
		long lngStartIndex = 0;
		while (true)
		{
			const char* pstrFound = strstr(m_pstrSuperString + lngStartIndex, pstrSubStringToFind);
			if (pstrFound != nullptr)
			{
				lngResult = pstrFound - m_pstrSuperString;
				lngStartIndex = lngResult + 1;
			}
			else
			{
				break;
			}
		}
	}

	return lngResult;
}
#pragma endregion
/*
Mutators
*/
#pragma region
CSuperString CSuperString::ToUpperCase()
{
	CSuperString strUpper;
	strUpper = m_pstrSuperString;
	_strupr(strUpper.m_pstrSuperString);

	return strUpper;
}

CSuperString CSuperString::ToLowerCase()
{
	char* strLower = new char[Length() + 1];
	for (int i = 0; i < Length(); i++) {
		strLower[i] = tolower(m_pstrSuperString[i]);
	}

	return strLower;
}

CSuperString CSuperString::TrimLeft()
{
	CSuperString pstrResult;

	if (m_pstrSuperString != nullptr)
	{
		long lngStartIndex = 0;
		while (isspace(m_pstrSuperString[lngStartIndex]))
		{
			lngStartIndex++;
		}

		long lngLength = strlen(m_pstrSuperString);
		long lngTrimmedLength = lngLength - lngStartIndex;
		pstrResult = Substring(lngStartIndex, lngTrimmedLength);
	}
	*this = pstrResult;
	return *this;
}

CSuperString CSuperString::TrimRight()
{
	CSuperString pstrResult;
	if (m_pstrSuperString != nullptr)
	{
		long lngLength = Length();
		long lngEndIndex = lngLength - 1;
		while (isspace(m_pstrSuperString[lngEndIndex]))
		{
			lngEndIndex--;
		}

		long lngTrimmedLength = lngEndIndex + 1;
		pstrResult = Substring(0, lngTrimmedLength);
	}
	*this = pstrResult;
	return *this;
}

CSuperString CSuperString::Trim()
{
	CSuperString pstrResult;

	pstrResult = CloneString(m_pstrSuperString);
	pstrResult = pstrResult.TrimLeft();
	pstrResult = pstrResult.TrimRight();
	*this = pstrResult;
	return *this;
}

CSuperString CSuperString::Reverse()
{
	char* pstrResult = nullptr;

	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);
		pstrResult = new char[lngLength + 1];
		strncpy_s(pstrResult, lngLength + 1, m_pstrSuperString, lngLength + 1);
		_strrev(pstrResult);
	}
	*this = pstrResult;
	return *this;
}

CSuperString CSuperString::Left(long lngCharactersToCopy)
{
	CSuperString ssLeft;

	ssLeft = Substring(0, lngCharactersToCopy);
	return ssLeft;
}

CSuperString CSuperString::Right(long lngCharactersToCopy)
{
	CSuperString ssRight;

	ssRight = Substring(Length() - lngCharactersToCopy, lngCharactersToCopy);

	return ssRight;
}

CSuperString CSuperString::Substring(long lngStart, long lngSubStringLength)
{
	CSuperString ssSub;
	char* pstrSub = 0;
	long lngLength = 0;
	lngLength = Length();

	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);

		if (lngStart < 0) {
			lngStart = 0;
		}

		if (lngStart > lngLength)
		{
			lngStart = lngLength;
		}

		if (lngSubStringLength > lngLength - lngStart)
		{
			lngSubStringLength = lngLength - lngStart;
		}

		pstrSub = new char[lngSubStringLength + 1];
		strncpy_s(pstrSub, lngSubStringLength + 1, m_pstrSuperString + lngStart, lngSubStringLength);
	}
	ssSub.CleanUp();
	ssSub.m_pstrSuperString = pstrSub;
	return ssSub;
}

const char* CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);

		for (long i = 0; i < lngLength; i++)
		{
			if (m_pstrSuperString[i] == chrLetterToFind)
			{
				m_pstrSuperString[i] = chrReplace;
			}
		}
	}

	return m_pstrSuperString;
}

CSuperString CSuperString::Replace(const char * pstrFind, const char * pstrReplace)
{
	CSuperString ssReplacedString;
	if (m_pstrSuperString != nullptr && pstrFind != nullptr && pstrReplace != nullptr)
	{
		long lngFindLength = strlen(pstrFind);
		long lngReplaceLength = strlen(pstrReplace);

		if (lngFindLength > 0)
		{
			long lngStart = 0;
			long lngLength = strlen(m_pstrSuperString);

			// Search for the substring in the original string
			char* pstrSubstring = strstr(m_pstrSuperString, pstrFind);

          			while (pstrSubstring != nullptr)
			{
				// Copy the characters before the substring
				long lngBeforeLength = pstrSubstring - m_pstrSuperString;
				ssReplacedString += Substring(lngStart, lngBeforeLength - lngStart);
				// Copy the characters in the replace string
				ssReplacedString += pstrReplace;

				lngStart = lngBeforeLength + lngFindLength;

				// Search for the next substring
				pstrSubstring = strstr(m_pstrSuperString + lngStart, pstrFind);
			}

			ssReplacedString += Substring(lngStart, lngLength - lngStart);
		}
	}

	return ssReplacedString;


}

CSuperString CSuperString::Insert(const char chrLetterToInsert, long lngIndex)
{
	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);

		if (lngIndex > lngLength)
		{
			lngIndex = lngLength;
		}

		// Create a new string to hold the modified string
		char *pstrNewString = new char[lngLength + 2];
		pstrNewString[0] = '\0';

		// Copy the characters before the insert position
		strncpy_s(pstrNewString, lngLength + 2, m_pstrSuperString, lngIndex);

		// Copy the character to insert
		pstrNewString[lngIndex] = chrLetterToInsert;

		// Copy the characters after the insert position
		strcpy_s(pstrNewString + lngIndex + 1, lngLength + 2, m_pstrSuperString + lngIndex);

		// Update the original string with the modified string
		*this = pstrNewString;
	}

	return *this;
}
CSuperString CSuperString::Insert(const char *pstrSubString, long lngIndex)
{
	if (m_pstrSuperString != nullptr && pstrSubString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);
		long lngSubStringLength = strlen(pstrSubString);

		if (lngIndex > lngLength)
		{
			lngIndex = lngLength;
		}

		// Create a new string to hold the modified string
		//char *pstrNewString = new char[lngLength + lngSubStringLength + 1];
		CSuperString ssNewString;
		//pstrNewString[0] = '\0';

		// Copy the characters before the insert position
		//strncpy_s(pstrNewString, lngLength + lngSubStringLength + 1, m_pstrSuperString, lngIndex);
		ssNewString = Left(lngIndex);

		// Copy the sub-string to insert
		//strcpy_s(pstrNewString + lngIndex, lngLength + lngSubStringLength + 1, pstrSubString);
		ssNewString += pstrSubString;

		// Copy the characters after the insert position
		//strcpy_s(pstrNewString + lngIndex + lngSubStringLength, lngLength + lngSubStringLength + 1, m_pstrSuperString + lngIndex);
		ssNewString += Right(Length() - lngIndex);
		// Update the original string with the modified string
		//delete[] m_pstrSuperString;
		*this = ssNewString;
	}

	return *this;
}
#pragma endregion
char& CSuperString::operator[](long lngIndex)
{
	static char chrEmpty = '\0';

	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);

		if (lngIndex >= 0 && lngIndex < lngLength)
		{
			return m_pstrSuperString[lngIndex];
		}
	}

	return chrEmpty;
}

const char& CSuperString::operator[](long lngIndex) const
{
	static char chrEmpty = '\0';

	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);

		if (lngIndex >= 0 && lngIndex < lngLength)
		{
			return m_pstrSuperString[lngIndex];
		}
	}

	return chrEmpty;
}
/*
ToType
*/
#pragma region
const char * CSuperString::ToString() const
{
	return m_pstrSuperString;
}

bool CSuperString::ToBoolean()
{
	bool blnValue = false;
	if (strcmp(ToLowerCase().m_pstrSuperString, "true") == 0) {
		blnValue = true;
	}
	else if (strcmp(ToLowerCase().m_pstrSuperString, "1") == 0) {
		blnValue = true;
	}
	return blnValue;
}
//
short CSuperString::ToShort()
{
	short shtValue = 0;
	shtValue = (short)atoi(m_pstrSuperString);
	return shtValue;
}
//
int CSuperString::ToInteger()
{
	int intValue = 0;
	intValue = (int)atoi(m_pstrSuperString);
	return intValue;
}

long CSuperString::ToLong()
{
	long lngValue = 0;
	lngValue = (long)atol(m_pstrSuperString);
	return lngValue;
}

float CSuperString::ToFloat()
{
	float sngValue = 0;
	sngValue = (float)atof(m_pstrSuperString);
	return sngValue;
}

double CSuperString::ToDouble()
{
	double dblValue = 0;
	dblValue = (double)atof(m_pstrSuperString);
	return dblValue;
}
#pragma endregion
ostream& operator << (ostream &osOut, const CSuperString &ssOutput)
{
	if (ssOutput.m_pstrSuperString != nullptr)
	{
		osOut << ssOutput.ToString();
	}

	return osOut;
}

istream& operator >> (istream &isIn, CSuperString &ssInput)
{
	char *pstrBuffer = new char[256];

	isIn >> pstrBuffer;

	long lngLength = strlen(pstrBuffer);

	if (lngLength > 0)
	{
		ssInput = pstrBuffer;
	}

	delete[] pstrBuffer;

	return isIn;
}



