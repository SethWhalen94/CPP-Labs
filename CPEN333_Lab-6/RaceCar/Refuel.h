#ifndef __Refuel__
#define __Refuel__
#include "Semaphores.h"
//#include "..\rt.h"
//
//CSemaphore fuel("Fuel_car", 0, 1);
//CSemaphore light("Pit_entry_light", 15, 15);

class Refuel : public ActiveClass
{
private:

	int main(void)
	{
		while (1)
		{
			fuel.Wait();		//Wait for supervisor

			cout << "Refueling car...\n";
			SLEEP(6000);

			light.Signal();		//Signal supervisor that refueling is done
		}
		return 0;
	}

};

#endif
