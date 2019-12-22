#ifndef __Wheel_Removal__
#define __Wheel_Removal__
#include "Semaphores.h"

class Wheel_Removal : public ActiveClass
{
private:
	int MyNumber;		//Number to keep track of Removal Technicians

	int main(void)
	{
		if (MyNumber == 1)
		{
			while (1)
			{
				Off1.Wait();		//Wait for NUT to be removed

				//Remove tire
				cout << "Removing Wheel #" << MyNumber << '\n';
				SLEEP(3000);
				On1.Signal();

			}
		}

		else if (MyNumber == 2)
		{
			while (1)
			{
				Off2.Wait();		//Wait for NUT to be removed

				//Remove tire
				cout << "Removing Wheel #" << MyNumber << '\n';
				SLEEP(3000);
				On2.Signal();

			}
		}

		else if (MyNumber == 3)
		{
			while (1)
			{
				Off3.Wait();		//Wait for NUT to be removed

				//Remove tire
				cout << "Removing Wheel #" << MyNumber << '\n';
				SLEEP(3000);
				On3.Signal();

			}
		}

		else
		{
			while (1)
			{
				Off4.Wait();		//Wait for NUT to be removed

				//Remove tire
				cout << "Removing Wheel #" << MyNumber << '\n';
				SLEEP(3000);
				On4.Signal();

			}
		}


		return 0;
	}

public:
	Wheel_Removal(int wheel) : MyNumber(wheel)
	{

	}

};
#endif // !__Wheel_Removal

