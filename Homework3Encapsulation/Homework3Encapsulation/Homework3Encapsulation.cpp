//-----------------------------------------------------------------------
// Name: Lance Brown
// Class: C 2
// Abstract: Homework 3- Encapsulation
//-----------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>
#include "CDog.h"
#include "CTrainedDog.h"

int main()
{
	CDog udtDog1;
	udtDog1.SetName("Butch");
	udtDog1.SetWeight(5.0f);
	CTrainedDog udtTrainedDog1;
	udtTrainedDog1.SetName("Fluffers");
	udtTrainedDog1.SetWeight(95.0f);

	printf("%s weighs %f pounds and says: ", udtDog1.GetName().c_str(), udtDog1.GetWeight());
	udtDog1.Bark();
	printf("%s weighs %f pounds and says: ", udtTrainedDog1.GetName().c_str(), udtTrainedDog1.GetWeight());
	udtTrainedDog1.Bark();
	printf("He can also do tricks. Fetch!\n");
	udtTrainedDog1.Fetch();
	printf("Play dead!\n");
	udtTrainedDog1.PlayDead();
	

}
