#ifndef __Jacks__
#define __Jacks__
#include "Semaphores.h"
//#include "..\rt.h"
//
//CSemaphore light("Pit_entry_light", 15, 15);
//
//CSemaphore StartJacks("Start_Jacks", 0, 2);
//CSemaphore jackFup("Raise_Front", 0, 2);	//Raise front of car
//CSemaphore jackBup("Raise_Back", 0, 2);		//Raise back
//CSemaphore jackFdown("Lower_Front", 0, 2);	//Lower front of car
//CSemaphore jackBdown("Lower_Back", 0, 2);		//Lower back
class Jacks : public ActiveClass
{
private:

	int MyNumber;		//Number of Jacker since we have more than 1

	int main(void)
	{
		//If MyNumber == 1, Then Be Front jack technician
		if (MyNumber == 1)
		{
			while (1)
			{
				StartJacks.Wait();		//Wait for supervisor to signal

				cout << "Jacking Up Front..\n";
				SLEEP(5000);
				jackFup.Signal();		//Signal Front wheel 1 to start process
				jackFup.Signal();		//Signal Front wheel 2 to start process

				//Wait for wheel change
				cout << "Front is jacked up..\n";
				cout << "Waiting for Wheel change...\n";

				jackFdown.Wait();
				jackFdown.Wait();
				//LOWER FRONT
				cout << "Lowering Front..\n";
				SLEEP(3000);
				//Signal That Front Jack tech is done
				light.Signal();

			}
		}

		//If MyNumber == 2, Then Be Rear jack technician
		else//MyNumber == 2
		{
			while (1)
			{
				StartJacks.Wait();		//Wait for supervisor to signal

				cout << "Jacking Up Rear..\n";
				SLEEP(5000);
				jackBup.Signal();		//Signal Rear wheel 3 to start process
				jackBup.Signal();		//Signal Rear wheel 4 to start process

				//Wait for wheel change
				cout << "Rear is jacked up..\n";
				cout << "Waiting for Wheel change...\n";

				jackBdown.Wait();
				jackBdown.Wait();
				//LOWER REAR
				cout << "Lowering Rear..\n";
				SLEEP(3000);
				//Signal That Rear Jack tech is done
				light.Signal();

			}
		}

		return 0;
	}

public:

	//Constructor
	Jacks(int number) : MyNumber(number)
	{

	}
};
#endif // !__Jacks__

