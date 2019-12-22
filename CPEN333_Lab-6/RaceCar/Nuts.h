#ifndef __Nuts__
#define __Nuts__
//#include "..\rt.h"
#include "Semaphores.h"
//CSemaphore light("Pit_entry_light", 15, 15);
//
////Nut techs
//CSemaphore Nut1("Nut1", 0, 1);			//Nut technician waiting for Front jacked up
//CSemaphore Nut2("Nut2", 0, 1);			//Nut technician waiting for Front jacked up
//CSemaphore Nut3("Nut3", 0, 1);			//Nut technician waiting for Back be jacked up
//CSemaphore Nut4("Nut4", 0, 1);			//Nut technician waiting for Back be jacked up
//
//CSemaphore Off1("Off1", 0, 1);			//Wheel removal waiting until NUT tech is done
//CSemaphore Off2("Off2", 0, 1);			//Wheel removal waiting until NUT tech is done
//CSemaphore Off3("Off3", 0, 1);			//Wheel removal waiting until NUT tech is done
//CSemaphore Off4("Off4", 0, 1);			//Wheel removal waiting until NUT tech is done
////Wheel securing
//CSemaphore On1("On1", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//CSemaphore On2("On2", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//CSemaphore On3("On3", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//CSemaphore On4("On4", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//
//CSemaphore jackFup("Raise_Front", 0, 1);	//Raise front of car
//CSemaphore jackBup("Raise_Back", 0, 1);		//Raise back
//CSemaphore jackFdown("Lower_Front", 0, 1);	//Lower front of car
//CSemaphore jackBdown("Lower_Back", 0, 1);		//Lower back

class Nuts : public ActiveClass
{

private:
	int MyNumber;		//Number to keep track of each Nut technician

	int main(void)
	{
		//=================
		// FRONT WHEEL #1
		//================
		if (MyNumber == 1)		
		{
			while (1)
			{
				jackFup.Wait();			//Wait for front to jack up

				cout << "Removing nut from Wheel #" << MyNumber << '\n';
				SLEEP(1000);
				cout << "Wheel #" << MyNumber << "Nut removed..\n";
				Off1.Signal();			//Signal to take wheel off
				Nut1.Wait();				//Wait for new wheel to be put on
				
				cout << "Replacing nut onto Wheel #" << MyNumber << '\n';
				SLEEP(2000);
				jackFdown.Signal();		//Signal jack to lower

			}
		}
		//=================
		// FRONT WHEEL #2
		//================
		else if (MyNumber == 2)
		{
			while (1)
			{
				jackFup.Wait();				//Wait for front to jack up

				cout << "Removing nut from Wheel #" << MyNumber << '\n';
				SLEEP(1000);
				cout << "Wheel #" << MyNumber << "Nut removed..\n";
				Off2.Signal();			//Signal to take wheel off
				Nut2.Wait();				//Wait for new wheel to be put on

				cout << "Replacing nut onto Wheel #" << MyNumber << '\n';
				SLEEP(2000);
				jackFdown.Signal();		//Signal jack to lower
			}
		}
		//=================
		// BACK WHEEL #3
		//================
		else if (MyNumber == 3)
		{
			while (1)
			{
				jackBup.Wait();		//Wait for rear to jack up

				cout << "Removing nut from Wheel #" << MyNumber << '\n';
				SLEEP(1000);
				cout << "Wheel #" << MyNumber << "Nut removed..\n";
				Off3.Signal();			//Signal to take wheel off
				Nut3.Wait();				//Wait for new wheel to be put on

				cout << "Replacing nut onto Wheel #" << MyNumber << '\n';
				SLEEP(2000);
				jackBdown.Signal();		//Signal jack to lower
			}
		}
		//=================
		// BACK WHEEL #4
		//================
		else  //MyNumber == 4
		{
			while (1)
			{
				jackBup.Wait();		//Wait for rear to jack up

				cout << "Removing nut from Wheel #" << MyNumber << '\n';
				SLEEP(1000);
				cout << "Wheel #" << MyNumber << "Nut removed..\n";
				Off4.Signal();			//Signal to take wheel off
				Nut4.Wait();				//Wait for new wheel to be put on

				cout << "Replacing nut onto Wheel #" << MyNumber << '\n';
				SLEEP(2000);
				jackBdown.Signal();		//Signal jack to lower
			}


		}

		return 0;
	}

public:
	//Constructor for Nuts class
	Nuts(int nut) : MyNumber(nut)
	{

	}
};

#endif // !__Nuts__

