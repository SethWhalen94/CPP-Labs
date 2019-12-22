#include "..\..\rt.h"

struct struct3 {
	int integer;
	double dub;
	int array[4];

};

int main()
{
	CTypedPipe<struct3> p3("Pipe3", 100);

	struct3 data3 = { 3, 3.3, {30, 31, 32, 33} };

	for (int i = 0; i < 300; i++)
	{
		cout << "Child 3 wrote data to Pipe1: \n"
			<< "integer = " << data3.integer << '\n'
			<< "double = " << data3.dub << '\n'
			<< "array = " << data3.array << '\n';
		p3.Write(&data3);
		SLEEP(1200);

	}

	return 0;
}