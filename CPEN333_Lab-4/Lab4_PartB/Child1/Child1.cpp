#include "..\..\rt.h"

struct struct1 {
	int integer;
	double dub;
	int array[4];

};

int main()
{
	CTypedPipe<struct1> p1("Pipe1", 100);

	struct1 data1 = { 1, 1.1, {10, 11, 12, 13} };

	for (int i = 0; i < 100; i++)
	{
		cout << "Child 1 wrote data to Pipe1: \n"
			<< "integer = " << data1.integer << '\n'
			<< "double = " << data1.dub << '\n'
			<< "array = " << data1.array << '\n';
		p1.Write(&data1);

		SLEEP(2000);

	}

	return 0;
}