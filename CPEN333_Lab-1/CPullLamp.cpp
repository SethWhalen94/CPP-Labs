#include "CPullLamp.h"
#include <iostream>
#include <stdio.h>

CPullLamp::CPullLamp(int w1, int w2, int w3)
	: CLamp(w1, w2, w3) // call base class constructor with watts
{
	printf("CPullLamp constructor called...\n");
}

void CPullLamp::toggle()
{
	if (getState() == 0) // if lamp is off, i.e. test state of base class
		CLamp::lampOn(); // turn on CPulledLamp using base class functions
	else
		CLamp::lampOff();
}