//------------------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Polymorphism exercise
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
#include<stdlib.h>
#include<iostream>
#include "CCow.h"
#include "CDog.h"
#include "CDragon.h"
using namespace std;

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// User Defined Types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Name: Main
// Abstract: Program entry
//------------------------------------------------------------------------------
void main()
{
	CCow clsCow;
	clsCow.SetName("Bessie");
	clsCow.SetType("Cow");
	clsCow.SetColor("Black Angus");

	CDog clsDog;
	clsDog.SetName("Fido");
	clsDog.SetType("Dog");
	clsDog.SetBreed("Mutt");

	CDragon clsDragon;
	clsDragon.SetName("Vexillanthus");
	clsDragon.SetType("Dragon");
	clsDragon.SetGoldCoins(123123);

	CAnimal* paclsZoo[5];
	paclsZoo[0] = (CAnimal*) &clsCow;
	paclsZoo[1] = 0;
	paclsZoo[2] = (CAnimal*)&clsDog;
	paclsZoo[3] = 0;
	paclsZoo[4] = (CAnimal*)&clsDragon;

	for (int i = 0; i < 5; i++) {
		if (paclsZoo[i] != 0) {
			cout << "Name: " << paclsZoo[i]->GetName() << endl;
			cout << "Type: " << paclsZoo[i]->GetType() << endl;
			paclsZoo[i]->MakeNoise();
			cout << endl;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (paclsZoo[i] != 0) {
			if (strcmp(paclsZoo[i]->GetType(), "Cow") == 0) {
				((CCow*)paclsZoo[i])->Graze();
			}
			else if (strcmp(paclsZoo[i]->GetType(), "Dog") == 0) {
				((CDog*)paclsZoo[i])->Fetch();
			}
			else if(strcmp(paclsZoo[i]->GetType(), "Dragon") == 0)
			{
				((CDragon*)paclsZoo[i])->BreatheFire();
			}
		}
	}


}
