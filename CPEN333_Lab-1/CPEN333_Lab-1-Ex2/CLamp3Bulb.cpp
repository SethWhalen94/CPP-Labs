#include <iostream>
#include <stdio.h>
#include "CLamp3Bulb.h"

/*********** Constructors ************/
//CLamp::CLamp(){}

//Constructor
CLamp::CLamp(int w1 = 0, int w2 = 0, int w3 = 0)
{
	m_switch = new CSwitch();		// create new switch in off state
	m_bulbs[0] = new CBulb(w1);		// create new wattage bulbs in off state
	m_bulbs[1] = new CBulb(w2);
	m_bulbs[2] = new CBulb(w3);
}


CLamp::CLamp(const CLamp &copy)		//Copy constructor, ?? How do I copy using Direct initialization??
{
	m_switch = new CSwitch(*copy.m_switch);			//NOTE:::: Since we are dealing with pointers, we need to 
	m_bulbs[0] = new CBulb(*copy.m_bulbs[0]);		//allocate new memory with the values we want to copy, otherwise 
													//we will be pointing to the same objects as the "copy" which means
													//when one object is deleted or changed, both the new object and copied
													//object will be affected

}


/********** End of Constructor Definitions**********/

void CLamp::lampOn()			//turn switch AND all 3 bulbs on
{
	m_switch->turnOn();
	m_bulbs[0]->on();
	m_bulbs[1]->on();
	m_bulbs[2]->on();
}					
void CLamp::lampOff()					//turn switch AND 3 bulbs off
{
	m_switch->turnOff();
	m_bulbs[0]->off();
	m_bulbs[1]->off();
	m_bulbs[2]->off();
}
int CLamp::getState()				// return the state of the switch in the Lamp
{
	return m_switch->getState();
}
void CLamp::print() 				// to print state of lamp i.e.on or off
{
	if (m_switch->getState() == 1)
		std::cout << "The lamp is on..\n\n";
	else
		std::cout << "The lamp is off..\n\n";
}
int CLamp::getpower()				// return power currently actually being consumed by the lamp
{
	return m_bulbs[0]->getPower() + m_bulbs[1]->getPower() + m_bulbs[2]->getPower();
}

CBulb* CLamp::exchange(CBulb* newBulb, int bulbNumber)	//replace old bulb with new one
{
	std::cout << "Exchanging bulb " << bulbNumber << " with new "; 
	newBulb->on();
	std::cout << newBulb->getPower() << " Watt bulb \n\n";
	newBulb->off();

	CBulb* temp = m_bulbs[bulbNumber];
	m_bulbs[bulbNumber] = newBulb;	

	if (temp->getState() == 1)
		m_bulbs[bulbNumber]->on();

	return temp;
}
CLamp::~CLamp()
{
	std::cout << "CLamp3Switch destructor being called..\n\n";
	delete m_bulbs[0];
	delete m_bulbs[1];
	delete m_bulbs[2];
	delete m_switch;

}