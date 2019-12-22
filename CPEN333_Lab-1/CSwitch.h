//#pragma once
#ifndef __CSwitch__
#define __CSwitch__

class CSwitch {

private:
	int m_state;

public:

	/*Declaration of Class CBulb Constructors*/
	CSwitch();
	/*End of CBulb Constructor declarations*/


	/*Declaration of Class CBulb functions*/
	void turnOn();
	void turnOff();
	void print();
	int getState();
	/*End of CBulb function declarations*/

	~CSwitch();


};

#endif