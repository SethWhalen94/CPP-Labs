#include "..\..\rt.h"

struct struct4 {
	int integer;
	double dub;
	int array[4];

};

int main()
{
	CTypedPipe<struct4> p4("Pipe4", 100);

	struct4 data4 = { 4, 4.4, {40, 41, 42, 43} };

	for (int i = 0; i < 400; i++)
	{
		cout << "Child 4 wrote data to Pipe1: \n"
			<< "integer = " << data4.integer << '\n'
			<< "double = " << data4.dub << '\n'
			<< "array = " << data4.array << '\n';
		p4.Write(&data4);
		SLEEP(1000);

	}

	return 0;
}