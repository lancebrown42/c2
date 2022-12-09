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
	char strSource[20] = "";
	sprintf_s(strSource, "%i", intIntegerToCopy);
	*this = strSource;
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
// --------------------------------------------------------------------------------
// method: Print
// description: Prints the instance of the CSuperString to the console with formatting
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: CloneString
// description: Returns a copy of the instance of the CSuperString
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: operator=
// description: Overloads the assignment operator to assign the given CSuperString instance to the current CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString& CSuperString::operator=(const CSuperString &ssStringToCopy)
{
	DeepCopy(ssStringToCopy.ToString());

	return *this;
}
// --------------------------------------------------------------------------------
// method: operator=
// description: Overloads the assignment operator to assign the given character to the current CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString& CSuperString::operator=(const char chrLetterToCopy)
{
	char chrLetter[2] = { chrLetterToCopy, 0 };
	*this = chrLetter;
	return *this;
}

// --------------------------------------------------------------------------------
// method: operator=
// description: Overloads the assignment operator to assign the given char* to the current CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString& CSuperString::operator=(const char *pstrStringToCopy)
{
	

	DeepCopy(pstrStringToCopy);

	return *this;
}

// --------------------------------------------------------------------------------
// method: operator=
// description: Overloads the assignment operator to assign the given int to the current CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString& CSuperString::operator=(const int intIntegerToCopy)
{

	char strSource[20] = "";
	sprintf_s(strSource, "%i", intIntegerToCopy);
	DeepCopy(strSource);
	return *this;
}

// --------------------------------------------------------------------------------
// method: operator+=
// description: Overloads the concatenation assignment operator to assign the given char* to the current CSuperString instance.
// --------------------------------------------------------------------------------

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

// --------------------------------------------------------------------------------
// method: operator+=
// description: Overloads the concatenation assignment operator to assign the given char to the current CSuperString instance.
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: operator+=
// description: Overloads the concatenation assignment operator to assign the given CSuperString instance to the current CSuperString instance.
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: operator+
// description: Overloads the concatenation operator to concatenate a given CSuperString instance with a given CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString operator + (const CSuperString &ssLeft, const CSuperString &ssRight)
{
	CSuperString ssResult;

	ssResult = ssLeft;
	ssResult += ssRight;

	return ssResult;
}

// --------------------------------------------------------------------------------
// method: operator+
// description: Overloads the concatenation operator to concatenate a given char* with a given CSuperString instance.
// --------------------------------------------------------------------------------
CSuperString operator + (const char * pstrLeftSide, const CSuperString &ssRightString)
{
	CSuperString ssResult;

	ssResult += pstrLeftSide;
	ssResult += ssRightString;

	return ssResult;
}

// --------------------------------------------------------------------------------
// method: operator+
// description: Overloads the concatenation operator to concatenate a given CSuperString instance with a given char*.
// --------------------------------------------------------------------------------
CSuperString operator + (const CSuperString &ssLeftString, const char * pstrRightSide)
{
	CSuperString ssResult;

	ssResult += ssLeftString;
	ssResult += pstrRightSide;

	return ssResult;
}
// --------------------------------------------------------------------------------
// method: operator[]
// description: Overloads the subscript operator to return the character at the given index
// --------------------------------------------------------------------------------
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
// --------------------------------------------------------------------------------
// method: operator[]
// description: Overloads the subscript operator to return the character at the given index
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: operator<<
// description: Overloads the output stream operator
// --------------------------------------------------------------------------------
ostream& operator << (ostream& osOut, const CSuperString& ssOutput)
{
	if (ssOutput.m_pstrSuperString != nullptr)
	{
		osOut << ssOutput.ToString();
	}

	return osOut;
}

// --------------------------------------------------------------------------------
// method: operator>>
// description: Overloads the input stream operator
// --------------------------------------------------------------------------------
istream& operator >> (istream& isIn, CSuperString& ssInput)
{
	char* pstrBuffer = new char[256];

	isIn >> pstrBuffer;

	long lngLength = strlen(pstrBuffer);

	if (lngLength > 0)
	{
		ssInput = pstrBuffer;
	}

	delete[] pstrBuffer;

	return isIn;
}
#pragma endregion

/*
 FindIndexOf
*/
#pragma region
// --------------------------------------------------------------------------------
// method: FindFirstIndexOf
// description: Returns the index of the first instance of a given character
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char chrLetterToFind)
{
	return FindFirstIndexOf(chrLetterToFind, 0);
}

// --------------------------------------------------------------------------------
// method: FindFirstIndexOf
// description: Returns the index of the first instance of a given character after a given index
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: FindLastIndexOf
// description: Returns the index of the last instance of a given character
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: FindFirstIndexOf
// description: Returns the index of the first instance of a given substring
// --------------------------------------------------------------------------------
long CSuperString::FindFirstIndexOf(const char *pstrSubStringToFind)
{
	return FindFirstIndexOf(pstrSubStringToFind, 0);
}

// --------------------------------------------------------------------------------
// method: FindFirstIndexOf
// description: Returns the index of the first instance of a given string after a given index
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: FindLastIndexOf
// description: Returns the index of the last instance of a given string
// --------------------------------------------------------------------------------
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
// --------------------------------------------------------------------------------
// method: ToUpperCase
// description: Returns a Upper case copy of the CSuperString instance
// --------------------------------------------------------------------------------
CSuperString CSuperString::ToUpperCase()
{
	CSuperString strUpper;
	strUpper = m_pstrSuperString;
	_strupr(strUpper.m_pstrSuperString);

	return strUpper;
}
// --------------------------------------------------------------------------------
// method: ToLowerCase
// description: Returns a lower case copy of the CSuperString instance
// --------------------------------------------------------------------------------
CSuperString CSuperString::ToLowerCase()
{
	CSuperString ssLower;
	ssLower = m_pstrSuperString;
	_strlwr(ssLower.m_pstrSuperString);

	return ssLower;
}

// --------------------------------------------------------------------------------
// method: TrimLeft
// description: Trims whitespace from the left of the CSuperString instance
// --------------------------------------------------------------------------------
CSuperString CSuperString::TrimLeft()
{
	CSuperString ssResult;

	if (m_pstrSuperString != nullptr)
	{
		long lngStartIndex = 0;
		while (isspace(m_pstrSuperString[lngStartIndex]))
		{
			lngStartIndex++;
		}

		long lngLength = strlen(m_pstrSuperString);
		long lngTrimmedLength = lngLength - lngStartIndex;
		ssResult = Substring(lngStartIndex, lngTrimmedLength);
	}
	return ssResult;
}
// --------------------------------------------------------------------------------
// method: TrimRight
// description: Trims whitespace from the right of the CSuperString instance
// --------------------------------------------------------------------------------
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

	return pstrResult;
}

// --------------------------------------------------------------------------------
// method: Trim
// description: Trims whitespace from the ends of the CSuperString instance
// --------------------------------------------------------------------------------
CSuperString CSuperString::Trim()
{
	CSuperString pstrResult;

	pstrResult = CloneString(m_pstrSuperString);
	pstrResult = pstrResult.TrimLeft();
	pstrResult = pstrResult.TrimRight();
	return pstrResult;
}

// --------------------------------------------------------------------------------
// method: Reverse
// description: Reverses the order of characters in the CSuperString instance
// --------------------------------------------------------------------------------
CSuperString CSuperString::Reverse()
{
	char* pstrResult = nullptr;
	CSuperString ssResult;
	if (m_pstrSuperString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);
		pstrResult = new char[lngLength + 1];
		strncpy_s(pstrResult, lngLength + 1, m_pstrSuperString, lngLength + 1);
		_strrev(pstrResult);
	}
	ssResult = pstrResult;
	return ssResult;
}

// --------------------------------------------------------------------------------
// method: Left
// description: Copies a given quantity of characters from the left
// --------------------------------------------------------------------------------
CSuperString CSuperString::Left(long lngCharactersToCopy)
{
	CSuperString ssLeft;

	ssLeft = Substring(0, lngCharactersToCopy);
	return ssLeft;
}

// --------------------------------------------------------------------------------
// method: Right
// description: Copies a given quantity of characters from the right
// --------------------------------------------------------------------------------
CSuperString CSuperString::Right(long lngCharactersToCopy)
{
	CSuperString ssRight;

	ssRight = Substring(Length() - lngCharactersToCopy, lngCharactersToCopy);

	return ssRight;
}

// --------------------------------------------------------------------------------
// method: Substring
// description: Copies a given quantity of characters from a given index
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: Replace
// description: Replaces all of a selected character with a given character
// --------------------------------------------------------------------------------
CSuperString CSuperString::Replace(char chrLetterToFind, char chrReplace)
{
	CSuperString ssReplaced;
	if (m_pstrSuperString != nullptr)
	{
		ssReplaced = *this;
		long lngLength = ssReplaced.Length();

		for (long i = 0; i < lngLength; i++)
		{
			if (ssReplaced[i] == chrLetterToFind)
			{
				ssReplaced[i] = chrReplace;
			}
		}
	}

	return ssReplaced;
}

// --------------------------------------------------------------------------------
// method: Replace
// description: Replaces all instances of a selected substring with a given substring
// --------------------------------------------------------------------------------
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

// --------------------------------------------------------------------------------
// method: Insert
// description: Inserts a character at a given index
// --------------------------------------------------------------------------------
CSuperString CSuperString::Insert(const char chrLetterToInsert, long lngIndex)
{
	CSuperString ssInserted;
	if (m_pstrSuperString != nullptr)
	{
		ssInserted = *this;
		long lngLength = ssInserted.Length();

		if (lngIndex > lngLength)
		{
			lngIndex = lngLength;
		}
		ssInserted = Left(lngIndex);
		ssInserted += chrLetterToInsert;
		ssInserted+= Right(lngIndex);

		
	}

	return ssInserted;
}

// --------------------------------------------------------------------------------
// method: Insert
// description: Inserts a substring at a given index
// --------------------------------------------------------------------------------
CSuperString CSuperString::Insert(const char *pstrSubString, long lngIndex)
{
	CSuperString ssNewString;
	if (m_pstrSuperString != nullptr && pstrSubString != nullptr)
	{
		long lngLength = strlen(m_pstrSuperString);
		long lngSubStringLength = strlen(pstrSubString);

		if (lngIndex > lngLength)
		{
			lngIndex = lngLength;
		}


		ssNewString = Left(lngIndex);

		ssNewString += pstrSubString;

		ssNewString += Right(Length() - lngIndex);

		
	}

	return ssNewString;
}
#pragma endregion

/*
ToType
*/
#pragma region
// --------------------------------------------------------------------------------
// method: ToString
// description: Returns the value of the CSuperString instance as a string
// --------------------------------------------------------------------------------
const char * CSuperString::ToString() const
{
	return m_pstrSuperString;
}
// --------------------------------------------------------------------------------
// method: ToBoolean
// description: Returns the value of the CSuperString instance as a bool
// --------------------------------------------------------------------------------
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
// --------------------------------------------------------------------------------
// method: ToShort
// description: Returns the value of the CSuperString instance as a short
// --------------------------------------------------------------------------------
short CSuperString::ToShort()
{
	short shtValue = 0;
	shtValue = (short)atoi(m_pstrSuperString);
	return shtValue;
}
// --------------------------------------------------------------------------------
// method: ToInteger
// description: Returns the value of the CSuperString instance as an integer
// --------------------------------------------------------------------------------
int CSuperString::ToInteger()
{
	int intValue = 0;
	intValue = (int)atoi(m_pstrSuperString);
	return intValue;
}
// --------------------------------------------------------------------------------
// method: ToLong
// description: Returns the value of the CSuperString instance as a long
// --------------------------------------------------------------------------------
long CSuperString::ToLong()
{
	long lngValue = 0;
	lngValue = (long)atol(m_pstrSuperString);
	return lngValue;
}
// --------------------------------------------------------------------------------
// method: ToFloat
// description: Returns the value of the CSuperString instance as a float
// --------------------------------------------------------------------------------
float CSuperString::ToFloat()
{
	float sngValue = 0;
	sngValue = (float)atof(m_pstrSuperString);
	return sngValue;
}

// --------------------------------------------------------------------------------
// method: ToDouble
// description: Returns the value of the CSuperString instance as a double
// --------------------------------------------------------------------------------
double CSuperString::ToDouble()
{
	double dblValue = 0;
	dblValue = (double)atof(m_pstrSuperString);
	return dblValue;
}
#pragma endregion


/*
Comparison Operator Overloads
*/
#pragma region
bool& operator==(const CSuperString& ssLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) == 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator==(const CSuperString& ssLeft, const char* pstrRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, pstrRight) == 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator==(const char* pstrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(pstrLeft, ssRight.m_pstrSuperString)== 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator==(const CSuperString& ssLeft, const char chrRight)
{
	bool blnReturn = false;
	if (ssLeft.Length() == 1 && ssLeft.m_pstrSuperString[0] == chrRight) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator==(const char chrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (ssRight.Length() == 1 && ssRight.m_pstrSuperString[0] == chrLeft) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator!=(const CSuperString& ssLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) != 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator!=(const CSuperString& ssLeft, const char* pstrRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, pstrRight) != 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator!=(const char* pstrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(pstrLeft, ssRight.m_pstrSuperString) != 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator!=(const CSuperString& ssLeft, const char chrRight)
{
	bool blnReturn = false;
	if ((ssLeft.Length() == 1 && ssLeft.m_pstrSuperString[0] != chrRight) || ssLeft.Length() != 1) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator!=(const char chrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if ((ssRight.Length() == 1 && ssRight.m_pstrSuperString[0] != chrLeft) || ssRight.Length() != 1) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>=(const CSuperString& ssLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) >= 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>=(const CSuperString& ssLeft, const char* pstrRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, pstrRight) >= 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>=(const char* pstrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(pstrLeft, ssRight.m_pstrSuperString) >= 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>=(const CSuperString& ssLeft, const char chrRight)
{
	bool blnReturn = false;
	if ((ssLeft.Length() == 1 && ssLeft.m_pstrSuperString[0] >= chrRight) || ssLeft.Length() != 1) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>=(const char chrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (ssRight.Length() == 1 && chrLeft >= ssRight.m_pstrSuperString[0]) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<=(const CSuperString& ssLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) <= 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<=(const CSuperString& ssLeft, const char* pstrRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, pstrRight) <= 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<=(const char* pstrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(pstrLeft, ssRight.m_pstrSuperString) <= 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<=(const CSuperString& ssLeft, const char chrRight)
{
	bool blnReturn = false;
	if (ssLeft.Length() == 1 && ssLeft.m_pstrSuperString[0] <= chrRight) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<=(const char chrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (ssRight.Length() == 1 && chrLeft <= ssRight.m_pstrSuperString[0]) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>(CSuperString& ssLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) > 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>(CSuperString& ssLeft, const char* pstrRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, pstrRight) > 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>(char* pstrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(pstrLeft, ssRight.m_pstrSuperString) > 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>(const CSuperString& ssLeft, const char chrRight)
{
	bool blnReturn = false;
	if (ssLeft.Length() == 1 && ssLeft.m_pstrSuperString[0] > chrRight) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator>(const char chrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (ssRight.Length() == 1 && chrLeft > ssRight.m_pstrSuperString[0]) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<(CSuperString& ssLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, ssRight.m_pstrSuperString) < 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<(CSuperString& ssLeft, const char* pstrRight)
{
	bool blnReturn = false;
	if (strcmp(ssLeft.m_pstrSuperString, pstrRight) < 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<(char* pstrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (strcmp(pstrLeft, ssRight.m_pstrSuperString) < 0) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<(const CSuperString& ssLeft, const char chrRight)
{
	bool blnReturn = false;
	if (ssLeft.Length() == 1 && ssLeft.m_pstrSuperString[0] < chrRight) {
		blnReturn = true;
	}
	return blnReturn;
}

bool& operator<(const char chrLeft, const CSuperString& ssRight)
{
	bool blnReturn = false;
	if (ssRight.Length() == 1 && chrLeft < ssRight.m_pstrSuperString[0]) {
		blnReturn = true;
	}
	return blnReturn;
}


#pragma endregion
