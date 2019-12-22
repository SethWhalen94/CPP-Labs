#include "..\..\rt.h"

struct struct2 {
	int integer;
	double dub;
	int array[4];

};

int main()
{
	CTypedPipe<struct2> p2("Pipe2", 100);

	struct2 data2 = { 2, 2.2, {20, 21, 22, 23} };

	for (int i = 0; i < 200; i++)
	{
		cout << "The size of struct is " << sizeof(data2) << '\n';
		cout << "Child 2 wrote data to Pipe1: \n"
			<< "integer = " << data2.integer << '\n'
			<< "double = " << data2.dub << '\n'
			<< "array = " << data2.array << '\n';
		p2.Write(&data2);
		SLEEP(1100);

	}

	return 0;
}