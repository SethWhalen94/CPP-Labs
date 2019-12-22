#include "TNode.h"
#include "../CBulb.h"
#include "../CSwitch.h"


int main()
{
	List <int> L1; // a list that holds integers
	L1.Insert(5);
	L1.Print();
	CBulb b1(100); // create a 100 watt bulb
	List <CBulb*> L2; // A list that holds pointers to CBulb objects
	L2.Insert(&b1); // Correct: add a pointer to bulb ‘b1’ to the list
	L2.Print();

	//int i = 5;
	//CBulb b2(100);
	//CSwitch s1();
	//L2.Insert(5); // Error cannot add an int to a list that only accepts CBulb pointers
	//L2.Insert(&s1); // Error cannot add a switch pointer to this list

	return 0;
}