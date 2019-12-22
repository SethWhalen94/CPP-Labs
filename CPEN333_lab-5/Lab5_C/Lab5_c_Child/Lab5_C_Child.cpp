#include "..\..\rt.h"
#include "..\Monitor.h"
int main()
{
	Monitor M1("Bill");

	for (int i = 0; i < 30000; i++)
		M1.increment_x();

	return 0;
}