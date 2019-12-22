#include "..\..\rt.h"

int main(int argc, char* argv[])
{
	float myfloat = atof(argv[1]);		//Convert second arguement to float, since argv[0] is a file path to child EXE file

	cout << "I was passed the float " << myfloat << '\n';
	cout << "myfloat * 2 = " << myfloat * 2 << '\n';
	getch();

	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from child process 1....\n";
		Sleep(50);
	}
	return 0 ;		// exit child program by returning status value 0
				// Note we could also call exit(0) to achieve the same thing
}