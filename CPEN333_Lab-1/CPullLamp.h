#include "CLamp3Bulb.h"
#include "CLamp3Bulb.h"
#include "CBulb.h"
#include "CSwitch.h"
#ifndef __CPullLamp__
#define __CPullLamp__


class CPullLamp : public CLamp
{
private:

public:
	/*Constructors*/
	CPullLamp(int w1, int w2, int w3);

	/*End of Constructors*/

	/*Declaration of Class functions*/
	void toggle();

	/*End of function declarations*/

private:
	void lampOn() { } // empty private function
	void lampOff() { } // empty private function



};



#endif
