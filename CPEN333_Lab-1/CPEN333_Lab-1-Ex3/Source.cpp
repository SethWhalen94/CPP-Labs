#include "Header.h"
//#include "CSwitch.h"
//#include "CLamp3Bulb.h"
//#include "CPullLamp.h"
//#include <iostream>
//#include <stdio.h>

//Constructors
CBulb::CBulb()
{
	m_state = 0;
	m_watts = 0;
	std::cout << "CBulb Default Constructor being called..\n\n";
}

CBulb::CBulb(int watts) :m_watts(watts) { m_state = 0; std::cout << "CBulb Constructor being called..\n\n"; }
/*End of Constructors*/


/*Definition of class CBulb functions*/
void CBulb::printState()
{
	if (m_state == 1)
	{
		std::cout << "The bulb is on \n\n";
		std::cout << "The Power is " << m_watts << "\n\n";
	}
	else
	{
		std::cout << "The bulb is off \n\n";
		std::cout << "The Power is 0 \n\n";
	}
}
//void CBulb::setState(int state){ m_state =state; }
void CBulb::on()
{
	if (m_state == 1)
		std::cout << "Bulb is already on..\n";
	else
		m_state = 1;
}
void CBulb::off()
{
	if (m_state == 0)
		std::cout << "Bulb is already off..\n";
	else
		m_state = 0;
}

int CBulb::getState() { return m_state; }

void CBulb::setWatts(int watts) { m_watts = watts; }

int CBulb::getPower()
{
	if (m_state == 1)
		return m_watts;
	else
		return 0;
}

/*End of class CBulb function definitions*/

CBulb::~CBulb() { std::cout << "CBulb destructor being called..\n\n"; }


//int main() {
//
//	/*********** Exercise 1,2 testing code ******************/
//	/*CBulb bulb;
//	bulb.printState();
//	bulb.setWatts(100);
//	bulb.getPower();
//	bulb.on();
//	std::cout << bulb.getPower() << "\n\n";
//	CBulb bulb2(60);
//	bulb2.on();
//	bulb2.printState();
//	std::cout << bulb2.getPower() << "\n\n";*/
//	/******** End of Exercise 1,2 testing code **************/
//
//	/*********** Exercise 3 testing code ******************/
//	/*CSwitch sw1;
//	sw1.print();
//	sw1.turnOn();
//	sw1.print();
//	sw1.turnOff();
//	sw1.turnOff();*/
//	/******** End of Exercise 3 testing code **************/
//
//	/*********** Exercise 4 testing code ******************/
//	/*CLamp lamp1(20, 40, 60);
//	lamp1.print();
//	std::cout << lamp1.getpower() << std::endl;
//	std::cout << lamp1.getState() << std::endl;
//	lamp1.lampOn();
//	std::cout << lamp1.getpower() << std::endl;
//	lamp1.print();
//	std::cout << lamp1.getState() << std::endl;
//	lamp1.lampOff();
//	lamp1.print();*/
//	/******** End of Exercise 4 testing code **************/
//
//	/*********** Exercise 5 testing code ******************/
//	//CLamp L1(100, 100, 100); // create a new Lamp with a 3x100 w bulbs
//	//CLamp L2(L1);
//	//L1.print();
//	//std::cout << L1.getpower() << std::endl;
//	//std::cout << L1.getState() << std::endl;
//	//L1.lampOn();
//	//std::cout << L1.getpower() << std::endl;
//	//CBulb* b1 = new CBulb(60); // create a new 60w bulb and a pointer to it
//
//
//	//b1 = L1.exchange(b1, 0); // give new bulb and save pointer to old bulb
//	//L1.print();
//	//std::cout << L1.getpower() << std::endl;
//	//std::cout << L1.getState() << std::endl;
//	//L2.print();
//	//std::cout << L2.getpower() << std::endl;
//	//std::cout << L2.getState() << std::endl;
//	/******** End of Exercise 5 testing code **************/
//
//	//delete b1; // main destroys old bulb
//
//	/*********** Exercise 6 testing code ******************/
//	//CPullLamp L1(100, 100, 100); // create a Pull Lamp with 3 x 100 watt bulbs
//	//L1.lampOn();
//	//printf("Power of Lamp = %d\n", L1.getpower()); // print power
//	//CBulb* bulb1 = new CBulb(50); // create new 50 watt bulb
//	//bulb1 = L1.exchange(bulb1, 0); // swap bulb 0 for 50 watt bulb
//	//printf("Power of Lamp = %d\n", L1.getpower()); // print power
//	//L1.lampOff();
//	//printf("Power of Lamp = %d\n", L1.getpower()); // print power
//
//	//CPullLamp L1(100, 100, 100); // create a Pull Lamp with 3 x 100 watt bulbs
//	//L1.toggle();
//	//printf("Power of Lamp = %d\n", L1.getpower()); // print power
//	//L1.toggle();
//	//printf("Power of Lamp = %d\n", L1.getpower()); // print power
//	/******** End of Exercise 6 testing code **************/
//
//
//
//	return 0;
//}
