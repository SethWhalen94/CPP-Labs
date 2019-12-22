#include "Car.h"

//======================
//    Constructors
//======================
Car::Car(int _MyNumber, int Speed, BOOL stopped, BOOL cruise) : MyNumber(_MyNumber), 
																MySpeed(Speed), 
																MyStopped(stopped),
																MyCruise(cruise)
{
	//Other constructor statements go here...

}
//===========================================
//          End of constructors
//===========================================


//===========================================
//       Member function definitions
//===========================================

int Car::main(void)
{
	

	ClassThread<Car> Speedometer(this, &Car::PrintSpeed, ACTIVE, NULL);

										// Must override function main() inherited from ActiveClass. The base
										//class constructor then creates a thread running through the function main()
		for (int i = 0; i < 100; i++)
		{
			cout << "Hello I am a Car " << MyNumber << '\n';
			SLEEP(50);
		}

		//Wait for the actuve thread to complete
		Speedometer.WaitForThread();


		return 0;

}


void Car::Accelerate(int acc)
{

	for (int i = 0; i < 10; i++)
	{
		if (MySpeed == acc)
			cout << "I am car " << MyNumber << " and I am already at " << MySpeed << " Km/h...\n";

		if (MySpeed < acc)
		{
			MyAccTo = acc;
			cout << "I am car " << MyNumber << " and I am accelerating to" << MyAccTo << " Km/h !!!\n";
			MySpeed = MyAccTo;
		}
		else
		{
			MyAccTo = acc;
			cout << "I am car " << MyNumber << " and I am decelerating to" << MyAccTo << " Km/h ...\n";
			MySpeed = MyAccTo;

		}
	}
}

void Car::Cruise(BOOL cruise)
{
	MyCruise = cruise;
	if (MyCruise == TRUE)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "I am car " << MyNumber << " and I am cruising at " << MySpeed << " ..........\n";
		}
	}

	else
		cout << "I am car " << MyNumber << " and I am NOT cruising.....\n";
	
}

void Car::Stop(BOOL stopped)
{
	MyStopped = stopped;
	if (MyStopped == TRUE)
	{
		MySpeed = 0;
		for (int i = 0; i < 10; i++)
			cout << "I am car " << MyNumber << " and I am stopping!!!\n";
	}
	else
	{
		for (int i = 0; i < 10; i++)
			cout << "I am car " << MyNumber << " and I am already stopped!!!\n";
	}
}

int Car::PrintSpeed(void *ThreadArgs)
{
	for (int i = 0; i < 100; i++)
	{
		cout << "I am car " << MyNumber << " and I my speed is " << MySpeed << " Km/h...\n";
		SLEEP(50);
	}

	return 0;

}

//void Car::Accelerate()
//{
//	cout << "I am car " << MyNumber << " and I am accelerating!!!\n";
//}
//
//void Car::Cruise()
//{
//	cout << "I am car " << MyNumber << " and I am cruising...\n";
//}
//
//void Car::Stop()
//{
//	cout << "I am car " << MyNumber << " and I am stopping!!!\n";
//}
//===========================================
//    End of member function definitions
//===========================================











//===========================================
//Extra if statements for clarity if needed
//===========================================
//if (MyStopped == TRUE)
//cout << " I am Stopped \n";
//else
//{
//	cout << "I am not stopped and ";
//
//	if (MySpeed > MyAccTo)
//	{
//		MySpeed = MyAccTo;
//		cout << "Decelerating to " << MyAccTo << " Km/h \n";
//	}
//	else if (MySpeed < MyAccTo)
//	{
//		MySpeed = MyAccTo;
//		cout << "accelerating to " << MyAccTo << " Km/h \n";
//	}
//	else if (MySpeed == MyAccTo && MyCruise == FALSE)
//		cout << "already at " << MyAccTo << " Km/h \n";
//	else
//		cout << "cruising at " << MyAccTo << " Km/h \n";
//
//}