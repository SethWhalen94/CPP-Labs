#ifndef __Car__
#define __Car__
#include"Semaphores.h"


class Car : public ActiveClass
{
private:
	int MyNumber;		//Private integer that will hold the instance number of class Car
	int MyLap;			//Lapv variable
	int MyFuel;			//Fuel in car, initialize to 100

	//BOOL MyPitStop;		//either 0 or 1, tells whether the car is stopped or not

	int main(void)
	{

		//ClassThread<Car> Speedometer(this, &Car::PrintSpeed, ACTIVE, NULL);

		// Must override function main() inherited from ActiveClass. The base
		//class constructor then creates a thread running through the function main()
		while (MyLap < 60)
		{
			cout << "I am car #" << MyNumber << " and I am on lap " << MyLap << '\n';
			MyLap = MyLap + 1;
			MyFuel = MyFuel - 2 * MyNumber;

			SLEEP(3000);
			if (MyFuel <= 10)
			{
				cout << "Car #" << MyNumber << " Needs to use the Pitstop for more gas and tires...\n";
				PitStop();
				MyFuel = 100;
			}
			else if (MyLap % (MyNumber + 5) == 0)
			{
				cout << "Car #" << MyNumber << " Needs to use the Pitstop for more gas and tires...\n";
				PitStop();
				MyFuel = 100;
			}
			/*else
			{
				MyLap = MyLap + 1;
				MyFuel = MyFuel - 2 * MyNumber;
			}*/

		}		// Must override function main() inherited from ActiveClass. The base
		return 0;					//class constructor then creates a thread running through the function main()
	}


public:
	//Car class constructor
																						//============NOTE============
																						//Default values for contructor must be 
																						//set in constructor function declaration NOT
																						//the definition in the .cpp file
																						//======== End of NOTE =========
	Car(int _MyNumber, int lap = 0, int fuel = 100) : MyNumber(_MyNumber),
		MyLap(lap),
		MyFuel(fuel)
	{
		//Other constructor statements go here...

	}

	//Car class member functions
	void PitStop()
	{
		pitstop.Signal();		//Wait for pitstop to open

		cout << "Car #" << MyNumber << " Is it the pitstop.......\n";

		finished.Wait();		//Wait for pitstop to finish

		cout << "Car #" << MyNumber << " Is Leaving the pitstop.......\n";
	}




};

#endif // !__Car__


////======================
////    Constructors
////======================
//Car::Car(int _MyNumber, int lap, int fuel) : MyNumber(_MyNumber),
//MyLap(lap),
//MyFuel(fuel)
//{
//	//Other constructor statements go here...
//
//}
////===========================================
////          End of constructors
////===========================================
//
//
////===========================================
////       Member function definitions
////===========================================
//
//int Car::main(void)
//{
//
//
//	//ClassThread<Car> Speedometer(this, &Car::PrintSpeed, ACTIVE, NULL);
//
//	// Must override function main() inherited from ActiveClass. The base
//	//class constructor then creates a thread running through the function main()
//	while (MyLap < 60)
//	{
//		cout << "I am car #" << MyNumber << " and I am on lap " << MyLap;
//
//		SLEEP(3000);
//		if (MyFuel <= 10)
//		{
//			cout << "Car #" << MyNumber << " Needs to use the Pitstop for more gas and tires...\n";
//			Car::PitStop();
//			MyFuel = 100;
//		}
//		else if (MyLap % (MyNumber + 5) == 0)
//		{
//			cout << "Car #" << MyNumber << " Needs to use the Pitstop for more gas and tires...\n";
//			Car::PitStop();
//			MyFuel = 100;
//		}
//		else
//		{
//			MyLap = MyLap + 1;
//			MyFuel = MyFuel - 2 * MyNumber;
//		}
//
//	}
//
//	//Wait for the actuve thread to complete
//	//Speedometer.WaitForThread();
//
//
//	return 0;
//
//}
//
//
//void Car::Lap()
//{
//
//	if (MyLap < 60)
//		MyLap = MyLap + 1;
//
//	else
//		cout << "I am car #" << MyNumber << " and I am done racing!\n";
//
//}
//
//
//
//void Car::PitStop()
//{
//	pitstop.Signal();		//Wait for pitstop to open
//
//	cout << "Car #" << MyNumber << " Is it the pitstop.......\n";
//
//	finished.Wait();		//Wait for pitstop to finish
//
//	cout << "Car #" << MyNumber << " Is Leaving the pitstop.......\n";
//}
