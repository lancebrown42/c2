// SuperString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSuperString.h"

void MuahahahTest1()
{
	//CSuperString ss1;
	//CSuperString ss2("Test");
	//CSuperString ss3(true);
	//CSuperString ss4('A');
	//CSuperString ss5(5);
	//CSuperString ss6(5l);
	//CSuperString ss7(5.5f);
	//CSuperString ss8(5.5);
	//CSuperString ss9(ss2);
	//std::cout << ss1 << std::endl;
	//std::cout << ss2 << std::endl;
	//std::cout << ss3 << std::endl;
	//std::cout << ss4 << std::endl;
	//std::cout << ss5 << std::endl;
	//std::cout << ss6 << std::endl;
	//std::cout << ss7 << std::endl;
	//std::cout << ss8 << std::endl;
	//std::cout << ss9 << std::endl;
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
	CSuperString ssTest6((int) 32767);
	ssTest6.Print("int");
	CSuperString ssTest7((long) 32767);
	ssTest7.Print("long");
	CSuperString ssTest8((float) 32767);
	ssTest8.Print("float");
	CSuperString ssTest9((double) 32767);
	ssTest9.Print("double");
	ssTest2 = ssTest2.ToUpperCase();
	ssTest2.Print("To upper");
	ssTest2 = ssTest2.Reverse();
	ssTest2.Print("Reverse");
	
}

void MuahahahTest2()
{
	CSuperString ssTest("I Love Star Wars and I Love Star Trek");
	ssTest.Print("Initial string");
	ssTest = ssTest.Replace('r', 'l');
	ssTest.Print("Replace char");
	ssTest = ssTest.Replace("Love", "Really Love Love");
	ssTest.Print("Replace string");
	ssTest = ssTest.Substring(3, 15);
	ssTest.Print("Substring 3, 15");

}
void Test3() {
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
	CSuperString ssTest("Irish Wristwatch");
	ssTest.Print("FindIndexOf for string:");
	cout << "First S: "<< ssTest.FindFirstIndexOf('s') << endl;
	cout << "First S after index 4: "<<ssTest.FindFirstIndexOf('s', 4) << endl;
	cout << "Last S: "<<ssTest.FindLastIndexOf('s') << endl;
	

}
int main()
{
    std::cout << "Hello World!\n";
	MuahahahTest1();
	//MuahahahTest2();
	//Test3();
	//TestIndices();
}


