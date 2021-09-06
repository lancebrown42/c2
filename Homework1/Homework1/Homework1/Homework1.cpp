//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 1. This program demonstrates basic knowledge of C/C++
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Includes - built-in libraries
//-----------------------------------------------------------------------
#include <iostream>

//-----------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------
const long lngARRAY_SIZE = 5;

//------------------------------------------------------------------------
// Name:SumWholeNumbers
// Problem #1
// Abstract:  Add Numbers 1 to 100
//------------------------------------------------------------------------

int SumWholeNumbers() {
	int intSum = 0;
	for (int i = 0; i < 100; i++) {
		intSum += i + 1;
	}
	return intSum;
}
//------------------------------------------------------------------------
// Name:SumEveryFourthCube
// Problem #2
// Abstract:  Add Cube of every fourth number descending
//------------------------------------------------------------------------
long SumEveryFourthCube() {
	long lngSum = 0;
	for (long i = 100; i >= -213; i -= 4) {
		lngSum += i * i * i;
	}
	return lngSum;
}
//------------------------------------------------------------------------
// Name: SumCrazyDecimals
// Problem #3
// Abstract:  Add Decimals with irrational increment descending
//------------------------------------------------------------------------
float SumCrazyDecimals() {
	float fltSum = 0;
	for (float i = 7.95; i >= -2167754; i = i- (4.5 / 1.987)) {
		fltSum += i;
	}
	return fltSum;
}
//------------------------------------------------------------------------
// Name:DecileInput
// Problem #4
// Abstract:  User input between 1 and 100
//------------------------------------------------------------------------
float DecileInput() {
	float fltInput = 0;
	while (fltInput < 1 || fltInput > 100) {
		printf("Enter a number between 1 and 100: \n");
		scanf_s("%f", &fltInput);
	}
	return fltInput;
}
//------------------------------------------------------------------------
// Name: AverageInput
// Problem #5
// Abstract:  Find Avg of user provided numbers
//------------------------------------------------------------------------
float AverageInput() {
	float fltTotal = 0;
	int intCount = 0;
	float fltInput = 0;
	float fltAverage = 0;
	printf("Enter one number at a time. Enter '0' to exit:");
	do {
		fltInput = 0;
		printf("Entry %d: \n", intCount+1);
		scanf_s("%f", &fltInput);
		if (fltInput > 0) {
			fltTotal += fltInput;
			intCount++;
		}
		 
	} while (fltInput != 0);
	if (intCount != 0) {
		fltAverage = fltTotal / intCount;
	}
	return fltAverage;
}
//------------------------------------------------------------------------
// Name: AverageIntArray
// Problem #6
// Abstract:  Find Avg of array of ints
//------------------------------------------------------------------------
float AverageIntArray(long alngValues[]) {
	long lngTotal = 0;
	float fltAverage = 0;
	for (int i = 0; i < lngARRAY_SIZE; i++) {
		lngTotal += alngValues[i];
	}
	fltAverage = (float) lngTotal / lngARRAY_SIZE;
	return fltAverage;

}
//------------------------------------------------------------------------
// Name:MinimumOfLngArray
// Problem #7
// Abstract:  Finds minimum value of array of longs
//------------------------------------------------------------------------
long MinimumOfLngArray(long alngValues[]) {
	long lngMin = alngValues[0];
	for (int i = 1; i < lngARRAY_SIZE; i++) {
		if (alngValues[i] < lngMin) {
			lngMin = alngValues[i];
		}
	}
	return lngMin;
}

//------------------------------------------------------------------------
// Name: StringLength
// Problem #8
// Abstract:  Find length of string without strlen
//------------------------------------------------------------------------
long StringLength(char* pstrString) {
	long lngCount = 0;
	for (int i = 0; pstrString[i] != '\0'; i++) {
		lngCount++;
	}
	return lngCount;
}

//------------------------------------------------------------------------
// Name: IndexOf
// Problem #9
// Abstract:  find first occurence of character in string
//------------------------------------------------------------------------
long IndexOf(char* pstrString, char chrQuery) {
	long lngIndex = -1;
	for (int i = 0; pstrString[i] != '\0'; i++) {
		if (pstrString[i] == chrQuery || pstrString[i] == chrQuery + 32 || pstrString[i] + 32 == chrQuery) {
			lngIndex = i;
			break;
		}
	}
	return lngIndex;
}

//------------------------------------------------------------------------
// Name: CopyString
// Problem #10
// Abstract:  copies string pointer to another pointer location
//------------------------------------------------------------------------
void CopyString(char* pstrDestination, char* pstrSource) {
	int intMaxIndex = 0;
	for (int i = 0; pstrSource[i] != '\0'; i++) {
		pstrDestination[i] = pstrSource[i];
		intMaxIndex = i;
	}
	pstrDestination[intMaxIndex + 1] = '\0';
}
//------------------------------------------------------------------------
// Name: AppendString
// Problem #11
// Abstract:  appends string to another
//------------------------------------------------------------------------
void AppendString(char* pstrDestination, char* pstrSource) {
	long lngInsertIndex = StringLength(pstrDestination);
	int intMaxIndex = 0;
	for (int i = 0; pstrSource[i] != '\0'; i++) {
		pstrDestination[i+lngInsertIndex] = pstrSource[i];
		intMaxIndex = i + lngInsertIndex;
	}
	pstrDestination[intMaxIndex + 1] = '\0';
}
//------------------------------------------------------------------------
// Name: ReverseString
// Problem #12
// Abstract:  reverses a string
//------------------------------------------------------------------------

void ReverseString(char* pstrDestination, char* pstrSource) {
	int intMaxIndex = 0;
	long lngLength = StringLength(pstrSource);
	for(int i =lngLength; i>0; i--){
		pstrDestination[lngLength - i] = pstrSource[i - 1];
		intMaxIndex = lngLength - i;
	}
	pstrDestination[intMaxIndex + 1] = '\0';
}
//------------------------------------------------------------------------
// Name: FindAndReplace
// Problem #13
// Abstract:  Finds substring and replaces with another
//------------------------------------------------------------------------
void FindAndReplace(char* pstrDestination, char* pstrSource, char* pstrToFind, char* pstrReplaceWith) {
	int intMaxIndex = 0;
	long lngSourceLength = StringLength(pstrSource);
	long lngSubstLength = StringLength(pstrToFind);
	long lngNewSubLength = StringLength(pstrReplaceWith);
	long lngInsertPoint = -1;
	long lngInsertionCount = 0;
	long lngInsertionsComplete = 0;
	long alngInsertionPoints[50];
	for (int i = 0; i < lngSourceLength; i++) {
		if (pstrSource[i] == pstrToFind[0]) {
			lngInsertPoint = i;
			for (int j = 0; j < lngSubstLength; j++) {
				if ((pstrSource[i+j] != pstrToFind[j])) {
					lngInsertPoint = -1;
					break;
				}	
			}
			if (lngInsertPoint >= 0) {
				alngInsertionPoints[lngInsertionCount] = lngInsertPoint;
				lngInsertionCount++;
			}
			
		}

	}
	for (int i = 0; pstrSource[i] != '\0'; i++) {
		if (i == alngInsertionPoints[lngInsertionsComplete]) {
			for (int j = i; j < i + lngNewSubLength; j++) {
				pstrDestination[j] = pstrReplaceWith[j - i];
			}
			lngInsertionsComplete++;
			
			continue;
		}
		pstrDestination[i+(lngNewSubLength * lngInsertionsComplete)] = pstrSource[i + (lngSubstLength * lngInsertionsComplete)];
		intMaxIndex = i + (lngNewSubLength * lngInsertionsComplete);
	}
	pstrDestination[lngSourceLength + ((lngNewSubLength - lngSubstLength) * lngInsertionsComplete)] = '\0';
}
//------------------------------------------------------------------------
// Name: Main
// Abstract: Program start 
//------------------------------------------------------------------------

void main()
{
	int intTotal = 0;
	long lngTotal = 0;
	float fltTotal = 0;
	float fltInput = 0;
	float fltAverage = 0;
	long alngValues[lngARRAY_SIZE] = { 9, 310, 5, 1, 64 };
	long lngMin = 0;
	char strString[] = "This is a String";
	long lngCount = 0;
	long lngIndex = 0;

	//Problem 1- Add Numbers 1 to 100
	intTotal = SumWholeNumbers();
	printf("Problem 1: Total = %d\n",intTotal);
	
	//Problem 2- Add Cube of every fourth number descending
	lngTotal = SumEveryFourthCube();
	printf("Problem 2: Total = %ld\n", lngTotal);


	//Problem 3- Add Decimals with irrational increment descending
	fltTotal = SumCrazyDecimals();
	printf("Problem 3: Total = %f\n", fltTotal);
	

	//Problem 4- User input between 1 and 100
	fltInput = DecileInput();
	printf("Problem 4: Input = %f\n", fltInput);

	//Problem 5- Find Avg of user provided numbers
	fltAverage = AverageInput();
	printf("Problem 5: Average = %f\n", fltAverage);

	//Problem 6- Find Avg of array of ints
	
	
	fltAverage = AverageIntArray(alngValues);
	printf("Problem 6: Average = %f\n", fltAverage);

	//Problem 7-Find minimum value of array of longs
	lngMin = MinimumOfLngArray(alngValues);
	printf("Problem 7: Minimum = %ld\n", lngMin);

	//Problem 8-Find length of string without strlen
	lngCount = StringLength(strString);
	printf("Problem 8: Length = %ld\n", lngCount);

	//Problem 9-Find index of given character
	lngIndex = IndexOf(strString, 'S');
	printf("Problem 9: Index = %ld\n", lngIndex);

	//Problem 10- Copy String
	char strCopy[100];
	CopyString(strCopy, strString);
	printf("Problem 10: Destination = %s\n", strCopy);

	//Problem 11- Append Strings
	AppendString(strCopy, strString);
	printf("Problem 11: Destination = %s\n", strCopy);

	//Problem 12- Reverse String
	char strReverse[100];
	ReverseString(strReverse, strString);
	printf("Problem 12: Reversed = %s\n", strReverse);

	//Problem 13- Find and Replace
	char strFind[] = "String";
	char strReplace[] = "trickier problem than expected";
	char strFindReplace[100];
	FindAndReplace(strFindReplace, strString, strFind, strReplace);
	printf("Problem 13: Altered String = %s\n", strFindReplace);


	

}

