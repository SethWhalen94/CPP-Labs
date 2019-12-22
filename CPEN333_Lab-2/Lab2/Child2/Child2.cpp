#include <iostream>
#include"/RTExamples/rt.h"

int main()
{
	int i;

	for (i = 0; i < 200; i++)
	{
		std::cout << "Hello from Child process 2 \n\n";
		Sleep(50);
	}
	return 0;


}