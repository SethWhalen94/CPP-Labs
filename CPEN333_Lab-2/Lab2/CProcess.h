#ifndef __Process__
#define __Process__
#include <process.h>	// for spawnl and createthread
#include <windows.h>	// for perror and sleep
#include <stdio.h>		// for printf
#include <limits.h>		// for UINT_MAX
#include <conio.h>		// for _kbhit(), getch() and getche()
#include <iostream>
#include <string>

class Process {

private:
	PROCESS_INFORMATION pinfo;



};

#endif // __CProcess__
