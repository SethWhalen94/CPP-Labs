#ifndef __Car__
#define __Car__
#include "..\\rt.h"

class Car : public ActiveClass
{
private:
	int MyNumber;		//Private integer that will hold the instance number of class Car
	int MyAccTo;			//Acceleration variable, reperesents a speed increase
	//int MyDecelTo;		//Slow down to a certain speed
	int MySpeed;			//Speed of the car, or cruise speed

	BOOL MyCruise;
	BOOL MyStopped;		//either 0 or 1, tells whether the car is stopped or not

	int main(void);		// Must override function main() inherited from ActiveClass. The base
						//class constructor then creates a thread running through the function main()



public:
	//Car class constructor
																						//============NOTE============
	Car(int _MyNumber, int Speed = 0, BOOL stopped = FALSE, BOOL cruise = FALSE);		//Default values for contructor must be 
																						//set in constructor function declaration NOT
																						//the definition in the .cpp file
																						//======== End of NOTE =========

	//Car class member functions
	void Accelerate(int acc);			//Set acc/deceleration value
	void Cruise(BOOL cruise);			//Set cruise to be True or false
	void Stop(BOOL stopped);			//Set stopped to be true or false
	int PrintSpeed(void* ThreadArgs);					//Spedometer function




};

#endif // !__Car__

