#include "CSwitch.h"
#include <iostream>
#include <stdio.h>

//Constructors
CSwitch::CSwitch() { m_state = 0; std::cout << "CSwitch constructor being called..\n\n"; }
/*End of Constructors*/

/*Definition of class CBulb functions*/
int CSwitch::getState() { return m_state; }		//Return the state of the switch
void CSwitch::turnOn() { m_state = 1; }			//Turn the switch on
void CSwitch::turnOff() { m_state = 0; }		//Turn the switch off
void CSwitch::print()							//Print the state of the switch
{
	if (m_state == 1)
		std::cout << "The switch is on..\n\n";
	else
		std::cout << "The switch is off..\n\n";
}
/*End of class CBulb function definitions*/

CSwitch::~CSwitch() {std::cout << "CSwitch destructor being called..\n\n"; }	//CSwitch destructor
/*
int main()
{
	CSwitch sw1;
	sw1.print();
	sw1.turnOn();
	sw1.print();
	sw1.turnOff();
	sw1.turnOff();
	//sw1.~CSwitch();
	return 0;

}

*/