#include "..\..\rt.h"

int main()
{

	

	for (int i = 0; i < 1000; i++)
	{
		MOVE_CURSOR(20, 20); // move cursor to cords [x,y] = 10,10
		cout << "Hello from Thread 2\n";
		cout.flush(); // force output to be written to screen
	}

	return 0;
}