// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Compiler Directives
// --------------------------------------------------------------------------------

#pragma once

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;
class CSuperString
{

private:
	char* m_pstrSuperString;

public:
	// Constructors
	CSuperString();
	// Parameterized/Copy constructors
	// CSuperString ssBuffer( "I Love Star Trek" );
	// CSuperString ssBuffer( 3.14159f );
	CSuperString(const char *pstrStringToCopy);
	CSuperString(const bool blnBooleanToCopy);
	CSuperString(const char chrLetterToCopy);
	CSuperString(const short shtShortToCopy);
	CSuperString(const int intIntegerToCopy);
	CSuperString(const long lngLongToCopy);
	CSuperString(const float sngFloatToCopy);
	CSuperString(const double dblDoubleToCopy);
	CSuperString(const CSuperString &ssStringToCopy);
	

	// Destructor
	virtual ~CSuperString();


	long Length() const;

	// Assignment Operators
	CSuperString &operator = (const char *pstrStringToCopy);
	CSuperString &operator = (const char chrLetterToCopy);
	CSuperString &operator = (const CSuperString &ssStringToCopy);
	// Extra credit for numeric parameters

	// Concatenate operator
	CSuperString& operator += (const char *pstrStringToAppend);
	CSuperString& operator += (const char chrCharacterToAppend);
	CSuperString& operator += (const CSuperString &ssStringToAppend);
	// Extra credit for numeric parameters

	friend CSuperString operator + (const CSuperString &ssLeft,
		const CSuperString &ssRight);
	friend CSuperString operator + (const char * pstrLeftSide,
		const CSuperString &ssRightString);
	friend CSuperString operator + (const CSuperString &ssLeftString,
		const char * pstrRightSide);

	long FindFirstIndexOf(const char chrLetterToFind);
	long FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex);
	long FindLastIndexOf(const char chrLetterToFind);

	long FindFirstIndexOf(const char *pstrSubStringToFind);
	long FindFirstIndexOf(const char *pstrSubStringToFind, long lngStartIndex);
	long FindLastIndexOf(const char *pstrSubStringToFind);

	// Do not change original string.  For example:
	// cout << ssBuffer.ToString( ) << endl;		// I Love Star Trek
	// cout << ssBuffer.ToUpperCase( ) << endl;	// I LOVE STAR TREK
	// cout << ssBuffer.ToString( ) << endl;		// I Love Star Trek
	const char* ToUpperCase();
	const char* ToLowerCase();
	const char* TrimLeft();
	const char* TrimRight();
	const char* Trim();
	const char* Reverse();

	const char* Left(long lngCharactersToCopy);
	const char* Right(long lngCharactersToCopy);
	const char* Substring(long lngStart, long lngSubStringLength);

	const char* Replace(char chrLetterToFind, char chrReplace);
	// Hard
	const char* Replace(const char *pstrFind, const char* pstrReplace);
	const char* Insert(const char chrLetterToInsert, long lngIndex);
	const char* Insert(const char *pstrSubString, long lngIndex);

	// Subscript operator
	char& operator [ ] (long lngIndex);
	const char& operator [ ] (long lngIndex) const;

	const char* ToString() const;
	bool ToBoolean();
	short ToShort();
	int ToInteger();
	long ToLong();
	float ToFloat();
	double ToDouble();

	// cin >> ssBuffer;
	// cout << ssBuffer;
	friend ostream& operator << (ostream &osOut, const CSuperString &ssOutput);
	friend istream& operator >> (istream &isIn, CSuperString &ssInput);

	// Don�t forget the comparison operators!!!

	void Print(const char* pstrCaption) const;



	protected:
		void Initialize();
		void DeepCopy(const char* pstrSource);
		void CleanUp();
		void DeleteString(char* &pstrSource);
		char* CloneString(const char* pstrSource);
		
};
