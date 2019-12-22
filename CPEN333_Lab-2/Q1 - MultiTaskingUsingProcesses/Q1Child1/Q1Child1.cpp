#include "..\..\rt.h"

int main(int argc, char* argv[])
{
	int myint = atoi(argv[1]);		//Convert second arguement to int, since argv[0] is a file path to child EXE file

	cout << "I was passed the integer " << myint << '\n';
	cout << "myint * 2 = " << myint * 2 << '\n';
	getch();


	int i ;
	for( i = 0; i < 200; i ++) {
		cout << "Hello from child process 1....\n";
		Sleep(50);
	}

	return 0 ;		// exit child program by returning status value 0
				// Note we could also call exit(0) to achieve the same thing
}