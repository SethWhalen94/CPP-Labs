#include <iostream>
#include"/RTExamples/rt.h"

int main()
{
	int i;

	for (i = 0; i < 300; i++)
	{
		std::cout << "Hello from Child process Test \n\n";
		Sleep(50);
	}

	return 0;


}