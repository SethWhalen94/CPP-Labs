#include "CSwitch.h"
#include "CBulb.h"
#ifndef __CLamp3Bulb__
#define __CLamp3Bulb__

class CLamp
{
private:
	CSwitch *m_switch;
	CBulb *m_bulbs[3];

public:
	//Constructors
	//CLamp();						
	CLamp(int w1, int w2, int w3);	//Default Constructor
	CLamp(const CLamp&);					//Copy Constructor
	/* End of Constructors*/

	void lampOn();					//turn switch and all 3 bulbs on
	void lampOff();					//turn switch and 3 bulbs off
	int getState();					// return the state of the switch in the Lamp
	void print();					// to print state of lamp i.e.on or off
	int getpower();					// return power currently actually being consumed by the lamp
	CBulb* exchange(CBulb*, int);	//Exchange a bulb for a new one and return pointer of old bulb
	~CLamp();
};


#endif // !__CLamp3Bulb__

