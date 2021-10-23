//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 6. This program demonstrates overloading and const
//-----------------------------------------------------------------------
#include <iostream>
#include"CDog.h"
#include"CTrainedDog.h"

int main()
{
    CDog udtDog = *new CDog("Fido", 4, 25.0f);
    CTrainedDog udtTrainedDog = *new CTrainedDog("Buster", 8, 5.0f, "Pomeranian");
    udtDog.Print();
    udtTrainedDog.Print();
}

