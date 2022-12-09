// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Compiler Directives
// --------------------------------------------------------------------------------

#pragma once
#define _CRT_SECURE_NO_WARNINGS

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
	CSuperString ToUpperCase();
	CSuperString ToLowerCase();
	CSuperString TrimLeft();
	CSuperString TrimRight();
	CSuperString Trim();
	CSuperString Reverse();

	CSuperString Left(long lngCharactersToCopy);
	CSuperString Right(long lngCharactersToCopy);
	CSuperString Substring(long lngStart, long lngSubStringLength);

	const char* Replace(char chrLetterToFind, char chrReplace);
	// Hard
	CSuperString Replace(const char *pstrFind, const char* pstrReplace);
	CSuperString Insert(const char chrLetterToInsert, long lngIndex);
	CSuperString Insert(const char *pstrSubString, long lngIndex);

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
	friend bool& operator == (const CSuperString &ssLeft, const CSuperString &ssRight);
	friend bool& operator == (const CSuperString &ssLeft, const char* pstrRight);
	friend bool& operator == (const char* pstrLeft, const CSuperString &ssRight);
	friend bool& operator == (const CSuperString &ssLeft, const char chrRight);
	friend bool& operator == (const char chrLeft, const CSuperString &ssRight);
							 
	friend bool& operator != (const CSuperString &ssLeft, const CSuperString &ssRight);
	friend bool& operator != (const CSuperString &ssLeft, const char* pstrRight);
	friend bool& operator != (const char* pstrLeft, const CSuperString &ssRight);
	friend bool& operator != (const CSuperString& ssLeft, const char chrRight);
	friend bool& operator != (const char chrLeft, const CSuperString& ssRight);
							  
	friend bool& operator >= (const CSuperString &ssLeft, const CSuperString &ssRight);
	friend bool& operator >= (const CSuperString &ssLeft, const char* pstrRight);
	friend bool& operator >= (const char* pstrLeft, const CSuperString &ssRight);
	friend bool& operator >= (const CSuperString& ssLeft, const char chrRight);
	friend bool& operator >= (const char chrLeft, const CSuperString& ssRight);
						
	friend bool& operator <= (const CSuperString &ssLeft, const CSuperString &ssRight);
	friend bool& operator <= (const CSuperString &ssLeft, const char* pstrRight);
	friend bool& operator <= (const char* pstrLeft, const CSuperString &ssRight);
	friend bool& operator <= (const CSuperString& ssLeft, const char chrRight);
	friend bool& operator <= (const char chrLeft, const CSuperString& ssRight);

	friend bool& operator > (CSuperString &ssLeft, const CSuperString &ssRight);
	friend bool& operator > (CSuperString &ssLeft, const char* pstrRight);
	friend bool& operator > (char* pstrLeft, const CSuperString &ssRight);
	friend bool& operator > (const CSuperString& ssLeft, const char chrRight);
	friend bool& operator > (const char chrLeft, const CSuperString& ssRight);

	friend bool& operator < (CSuperString &ssLeft, const CSuperString &ssRight);
	friend bool& operator < (CSuperString &ssLeft, const char* pstrRight);
	friend bool& operator < (char* pstrLeft, const CSuperString &ssRight);
	friend bool& operator < (const CSuperString& ssLeft, const char chrRight);
	friend bool& operator < (const char chrLeft, const CSuperString& ssRight);

	void Print(const char* pstrCaption) const;



	protected:
		void Initialize();
		void DeepCopy(const char* pstrSource);
		void CleanUp();
		void DeleteString(char* &pstrSource);
		char* CloneString(const char* pstrSource);
		
};
