#include "Car.h"
#include <vector>

int main()
{
	/*vector<Car> *cars[10];
	int Num[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
	{
		cars[i] = new Car car(Num[i]);
	}*/

	Car car1(1), car2(2), car3(3), car4(4), car5(5), car6(6), car7(7), car8(8), car9(9), car10(10);

	//Resume since all threads are initially suspended
	car1.Resume();				//Start car 1
	car1.Accelerate(10);		//Accelerate car 1
	SLEEP(100);
	car1.Accelerate(100);
	SLEEP(100);
	car1.Accelerate(1000);
	SLEEP(100);
	car1.Cruise(TRUE);		//Cruise car 1
	SLEEP(100);
	car1.Stop(TRUE);		//Stop car 1
	_getch();				//wait for return key

	car2.Resume();				//Start car 2
	car2.Accelerate(20);
	SLEEP(100);
	car2.Accelerate(50);
	SLEEP(100);
	car2.Accelerate(100);
	SLEEP(100);
	car2.Cruise(TRUE);	
	SLEEP(500);
	car2.Stop(TRUE);
	_getch();				//wait for return key

	car3.Resume();				//Start car 3
	car3.Accelerate(10);
	SLEEP(100);
	car3.Accelerate(50);
	SLEEP(100);
	car3.Accelerate(100);
	SLEEP(100);
	car3.Cruise(TRUE);
	SLEEP(500);
	car3.Stop(TRUE);
	_getch();				//wait for return key

	car4.Resume();				//Start car 4
	car4.Accelerate(20);
	SLEEP(100);
	car4.Accelerate(75);
	SLEEP(100);
	car4.Accelerate(100);
	SLEEP(100);
	car4.Cruise(TRUE);
	SLEEP(500);
	car4.Stop(TRUE);
	_getch();				//wait for return key

	car5.Resume();				//Start car 5
	car5.Accelerate(20);
	SLEEP(100);
	car5.Accelerate(50);
	SLEEP(100);
	car5.Accelerate(100);
	SLEEP(100);
	car5.Cruise(TRUE);
	SLEEP(500);
	car5.Stop(TRUE);
	_getch();				//wait for return key

	car6.Resume();				//Start car 6
	car6.Accelerate(20);
	SLEEP(100);
	car6.Accelerate(50);
	SLEEP(100);
	car6.Accelerate(100);
	SLEEP(100);
	car6.Cruise(TRUE);
	SLEEP(500);
	car6.Stop(TRUE);
	_getch();				//wait for return key
	

	//Wait for threads to terminate
	car1.WaitForThread();
	car2.WaitForThread();
	car3.WaitForThread();
	car4.WaitForThread();
	car5.WaitForThread();
	car6.WaitForThread();
	/*car7.WaitForThread();
	car8.WaitForThread();
	car9.WaitForThread();
	car10.WaitForThread();*/

	cout << "all threads have finished..\n";


	return 0;
}

//car1.Resume();			//Start car 1
//car1.Accelerate(10);		//Accelerate car 1
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car2.Resume();			//start car 2
//car1.Cruise(TRUE);			//Cruise car 1
//car2.Accelerate(20);		//Accelerate car 2
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car3.Resume();			//Start car 3
//car1.Stop(TRUE);			//Stop car 1
//car2.Cruise(TRUE);			//Cruise car 2
//car3.Accelerate(30);		//Accelerate car 3
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car4.Resume();			//Start car 4
//car2.Stop(TRUE);			//Stop car 2
//car3.Cruise(TRUE);			//Cruise car 3
//car4.Accelerate(40);		//Accelerate car 4
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car5.Resume();			//Start car 5
//car3.Stop(TRUE);			//Stop car 3
//car4.Cruise(TRUE);			//Cruise car 4
//car5.Accelerate(50);		//Accelerate car 5
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car6.Resume();			//Start car 6
//car4.Stop(TRUE);			//Stop car 4
//car5.Cruise(TRUE);			//Cruise car 5
//car6.Accelerate(60);		//Accelerate car 6
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//
//car7.Resume();			//Start car 7
//car5.Stop(TRUE);			//Stop car 5
//car6.Cruise(TRUE);			//Cruise car 6
//car7.Accelerate(70);		//Accelerate car 7
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car8.Resume();			//Start car 8
//car6.Stop(TRUE);			//Stop car 6
//car7.Cruise(TRUE);			//Cruise car 7
//car8.Accelerate(80);		//Accelerate car 8
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car9.Resume();			//Start car 9
//car7.Stop(TRUE);			//Stop car 7
//car8.Cruise(TRUE);			//Cruise car 8
//car9.Accelerate(90);		//Accelerate car 9
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car10.Resume();			//Start car 10
//car8.Stop(TRUE);			//Stop car 8
//car9.Cruise(TRUE);			//Cruise car 9
//car10.Accelerate(100);		//Accelerate car 10
//			////SLEEP main for 2 seconds
//_getch();				//wait for return key
//
//car9.Stop(TRUE);			//Stop car 9
//car10.Cruise(TRUE);			//Cruise car 10
//car10.Stop(TRUE);			//Stop car 10