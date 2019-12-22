#ifndef __Wheel_Securing__
#define __Wheel_Securing__
#include "Semaphores.h"

class Wheel_Securing : public ActiveClass
{
private:
	int MyNumber;		//Number to keep track of Wheel Removal Technicians

	int main(void)
	{
		if (MyNumber == 1)
		{
			while (1)
			{
				On1.Wait();		//Wait for old wheel to be removed
				cout << "Replacing wheel #" << MyNumber << '\n';
				SLEEP(3000);
				Nut1.Signal();		//Tell Nut technician 1 to put NUT back on


			}
		}

		else if (MyNumber == 2)
		{
			while (1)
			{
				On2.Wait();		//Wait for old wheel to be removed
				cout << "Replacing wheel #" << MyNumber << '\n';
				SLEEP(3000);
				Nut2.Signal();		//Tell Nut technician 1 to put NUT back on
			}
		}

		else if (MyNumber == 3)
		{
			while (1)
			{
				On3.Wait();		//Wait for old wheel to be removed
				cout << "Replacing wheel #" << MyNumber << '\n';
				SLEEP(3000);
				Nut3.Signal();		//Tell Nut technician 1 to put NUT back on
			}
		}

		else
		{
			while (1)
			{
				On4.Wait();		//Wait for old wheel to be removed
				cout << "Replacing wheel #" << MyNumber << '\n';
				SLEEP(3000);
				Nut4.Signal();		//Tell Nut technician 1 to put NUT back on

			}
		}

		return 0;
	}

public:
	Wheel_Securing(int wheel) : MyNumber(wheel)
	{

	}
};

#endif // !__Wheel_Securing__

