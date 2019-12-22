//#pragma once
#ifndef __CBulb__
#define __CBulb__


class CBulb {

private:
	/*Declaration of Class CBulb variables*/
	int m_state, m_watts;

public:
	/*Declaration of Class CBulb Constructors*/
	CBulb(int watts);//Default
	CBulb();
	/*End of CBulb Constructor declarations*/

	/*Declaration of Class CBulb functions*/
	void printState();
	//void setState(int state);
	void on();
	void off();
	int getState();
	void setWatts(int watts);
	int getPower();
	/*End of CBulb function declarations*/

	~CBulb();



};

#endif
