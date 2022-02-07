// SuperString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSuperString.h"

int main()
{
    std::cout << "Hello World!\n";
}

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

