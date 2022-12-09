//// --------------------------------------------------------------------------------
//  SuperString.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Lance Brown
// --------------------------------------------------------------------------------



#include <iostream>
#include "CSuperString.h"

void MuahahahTest1()
{
	CSuperString ssTest;
	cout << "Muahahah Test #1: " << ssTest << endl;
}
void MuahahahTest2()
{
	CSuperString ssTest = "I Love Star Wars and I Love Star Trek";

	ssTest = ssTest.Replace("Love", "Really Love Love");

	cout << "Muahahah Test #2: " << ssTest << endl;
}

void TestConstructors()
{
	const char* pstrTestName = "TestConstructors";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;
	CSuperString ssTest;
	ssTest.Print("Empty");
	CSuperString ssTest2("I Love Star Trek");
	ssTest2.Print("String");
	CSuperString ssTest3('I');
	ssTest3.Print("Char");
	CSuperString ssTest4(true);
	ssTest4.Print("bool");
	CSuperString ssTest5((short) 32767);
	ssTest5.Print("short");
	int intTest = 32767;
	CSuperString ssTest6(intTest);
	ssTest6.Print("int");
	CSuperString ssTest7((long) 32767);
	ssTest7.Print("long");
	CSuperString ssTest8((float) 32767);
	ssTest8.Print("float");
	CSuperString ssTest9((double) 32767);
	ssTest9.Print("double");

	
}

void TestMutators()
{
	const char* pstrTestName = "TestMutators";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;

	CSuperString ssTest("I Love Star Wars and I Love Star Trek");
	CSuperString ssTest2;
	ssTest.Print("Initial string");
	ssTest2 = ssTest.ToUpperCase();
	ssTest2.Print("To upper");
	ssTest2 = ssTest.ToLowerCase();
	ssTest2.Print("ToLower");
	ssTest2 = ssTest.Reverse();
	ssTest2.Print("Reverse");
	ssTest2 = ssTest.Replace('r', 'l');
	ssTest2.Print("Replace char");
	ssTest2 = ssTest.Replace("Love", "Really Love Love");
	ssTest2.Print("Replace string");
	ssTest2 = ssTest.Substring(3, 15);
	ssTest2.Print("Substring 3, 15");
	ssTest2 = ssTest.Insert('|', 6);
	ssTest2.Print("Insert '|'");
	ssTest2 = ssTest.Insert("|||||", 6);
	ssTest2.Print("Insert '|||||'");
	ssTest.Print("Initial string unaffected");

}
void TestAssignmentOperators() {
	const char* pstrTestName = "TestAssignmentOperators";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;

	CSuperString ssTest;
	CSuperString ssTest2;
	CSuperString ssTest3;

	ssTest = "banana";
	ssTest.Print("=String");
	ssTest = 'c';
	ssTest.Print("=Char");
	ssTest2 = ssTest;
	ssTest2.Print("=SuperString");
	ssTest += "rike";
	ssTest.Print("+=String");
	ssTest += 'y';
	ssTest.Print("+=char");
	ssTest += ssTest2;
	ssTest.Print("+=Superstring");
	ssTest3 = ssTest2 + ssTest;
	ssTest3.Print("SuperString + Superstring");
	ssTest3 = "blimey " + ssTest;
	ssTest3.Print("string + Superstring");
	ssTest3 = ssTest + " mate";
	ssTest3.Print("Superstring = string");

}
void TestIndices() {
	const char* pstrTestName = "TestIndices";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;

	CSuperString ssTest("  Irish Wristwatch   ");
	ssTest.Print("Trimming: ");
	ssTest = ssTest.TrimLeft();
	ssTest.Print("Trimmed left");
	ssTest = ssTest.TrimRight();
	ssTest.Print("Trimmed right");
	ssTest = "   Irish Wristwatch   ";
	ssTest.Print("Reset whitespace");
	ssTest = ssTest.Trim();
	ssTest.Print("Trim");
	ssTest.Print("FindIndexOf for string:");
	cout << "First S: "<< ssTest.FindFirstIndexOf('s') << endl;
	cout << "First S after index 4: "<<ssTest.FindFirstIndexOf('s', 4) << endl;
	cout << "Last S: "<<ssTest.FindLastIndexOf('s') << endl;
	cout << "First ri: "<< ssTest.FindFirstIndexOf("ri") << endl;
	cout << "First ri after index 4: "<<ssTest.FindFirstIndexOf("ri", 4) << endl;
	cout << "Last ri: "<<ssTest.FindLastIndexOf("ri") << endl;
	cout << "subscript operator ssTest[3]: " << ssTest[3] << endl;
	

}
void TestIO() {
	const char* pstrTestName = "TestIO";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;

	CSuperString ssBuffer;
	cout << "Type stuff: ";
	cin >> ssBuffer;
	cout << ssBuffer << endl;
	printf("Double call:\n Left( 2 ): %s, Left( 4 ): %s\n", ssBuffer.Left(2).ToString(), ssBuffer.Left(4).ToString());

}
void ExtraCredit() {
	const char* pstrTestName = "Extra Credit";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;

	CSuperString ssTest1;
	CSuperString ssTest2;
	CSuperString ssTest3;
	CSuperString ssTest4;
	CSuperString ssTest5;
	CSuperString ssTest6;
	ssTest1 = (int)123;
	ssTest1.Print(" = int");
	ssTest2 = (short)123;
	ssTest2.Print(" = short");
	ssTest3 = (long)123;
	ssTest3.Print(" = long");
	ssTest4 = (float)123;
	ssTest4.Print(" = float");
	ssTest5 = (double)123;
	ssTest5.Print(" = double");
	ssTest6 = ssTest1 + 73;
	ssTest6.Print("+ int");
	ssTest6 = ssTest1 + ssTest1.ToShort();
	ssTest6.Print("+ short");
	ssTest6 = ssTest1 + ssTest1.ToLong();
	ssTest6.Print("+ long");
	ssTest6 = ssTest1 + ssTest1.ToFloat();
	ssTest6.Print("+ float");
	ssTest6 = ssTest1 + ssTest1.ToDouble();
	ssTest6.Print("+ double");
}
void TestComparison() {
	const char* pstrTestName = "TestComparison";
	cout << "****************" << endl << pstrTestName << endl << "****************" << endl << endl;

	CSuperString ssTest1;
	CSuperString ssTest2;
	CSuperString ssTest3;
	CSuperString ssTest4;
	CSuperString ssTest5;
	bool blnResult;
	CSuperString ssResult;
	ssResult = "This text shouldn't show";
	ssTest1 = "I'm Left";
	ssTest2 = "I'm Right";
	ssTest3 = "I'm Left";
	ssTest4 = "I'm Right";
	ssTest5 = 'I';
	const char chrTest = 'I';

	ssResult = CSuperString(ssTest1 == ssTest2);
	ssResult.Print("1 This should be false");
	ssResult = CSuperString(ssTest1 == ssTest3);
	ssResult.Print("2 This should be true");
	ssResult = CSuperString(ssTest1 == "I'm Left");
	ssResult.Print("3 This should be true");
	ssResult = CSuperString(ssTest1 == "I'm Right");
	ssResult.Print("4 This should be false");
	ssResult = CSuperString(ssTest1 == chrTest);
	ssResult.Print("5 This should be false");
	ssResult = CSuperString(ssTest5 == chrTest);
	ssResult.Print("6 This should be true");

	ssResult = CSuperString(ssTest1 != ssTest2);
	ssResult.Print("7 This should be true");
	ssResult = CSuperString(ssTest1 != ssTest3);
	ssResult.Print("8 This should be false");
	ssResult = CSuperString(ssTest1 != "I'm Left");
	ssResult.Print("9 This should be false");
	ssResult = CSuperString(ssTest1 != "I'm Right");
	ssResult.Print("10 This should be true");
	ssResult = CSuperString(ssTest1 != chrTest);
	ssResult.Print("11 This should be true");
	ssResult = CSuperString(ssTest5 != chrTest);
	ssResult.Print("12 This should be false");


	ssResult = CSuperString(ssTest1 >= ssTest3);
	ssResult.Print("13 This should be true");
	ssResult = CSuperString(ssTest1 >= ssTest2);
	ssResult.Print("14 This should be false");
	ssResult = CSuperString(ssTest2 >= ssTest1);
	ssResult.Print("15 This should be true");
	ssResult = CSuperString(ssTest1 >= "ABC");
	ssResult.Print("16 This should be true");
	ssResult = CSuperString(ssTest1 >= "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
	ssResult.Print("17 This should be false");


	ssResult = CSuperString(ssTest1 <= ssTest3);
	ssResult.Print("18 This should be true");
	ssResult = CSuperString(ssTest1 <= ssTest2);
	ssResult.Print("19 This should be true");
	ssResult = CSuperString(ssTest2 <= ssTest1);
	ssResult.Print("20 This should be false");
	ssResult = CSuperString(ssTest1 <= "ABC");
	ssResult.Print("21 This should be false");
	ssResult = CSuperString(ssTest1 <= "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
	ssResult.Print("22 This should be true");


	ssResult = CSuperString(ssTest1 > ssTest3);
	ssResult.Print("23 This should be false");
	ssResult = CSuperString(ssTest1 > ssTest2);
	ssResult.Print("24 This should be false");
	ssResult = CSuperString(ssTest2 > ssTest1);
	ssResult.Print("25 This should be true");
	ssResult = CSuperString(ssTest1 > "ABC");
	ssResult.Print("26 This should be true");
	ssResult = CSuperString(ssTest1 > "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
	ssResult.Print("27 This should be false");



	ssResult = CSuperString(ssTest1 < ssTest3);
	ssResult.Print("28 This should be false");
	ssResult = CSuperString(ssTest1 < ssTest2);
	ssResult.Print("29 This should be true");
	ssResult = CSuperString(ssTest2 < ssTest1);
	ssResult.Print("30 This should be false");
	ssResult = CSuperString(ssTest1 < "ABC");
	ssResult.Print("31 This should be false");
	ssResult = CSuperString(ssTest1 < "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
	ssResult.Print("32 This should be true");


}
int main()
{
    std::cout << "Hello World!\n";
	TestConstructors();
	TestMutators();
	TestAssignmentOperators();
	TestComparison();
	TestIndices();
	TestIO();
	MuahahahTest1();
	MuahahahTest2();
	ExtraCredit();
}


