/***************************************************************************************
**	Program 2 - Example use of a CMutex object to enforce mutual exclusion
****************************************************************************************/

#include "..\..\rt.h"				// change pathlist to "rt.h" to suit location on your disk

struct 		mydatapooldata {		// data to be stored in a datapool
	unsigned long long int 	x;
};


int main()
{
	unsigned long long int a;

	//
	//	Start off with a datapool to represent our non-sharable resource. Now we need to make sure
	//	that only one process uses the datapool so we will need a binary semaphore to protect it
	//

	CDataPool	dp1("MyDataPoolName", sizeof(struct mydatapooldata));				// make datapool
	struct 		mydatapooldata	*DataPtr = (struct mydatapooldata  *)dp1.LinkDataPool();	// link to datapool
	//Creating MUTEX
	CSemaphore T("Mutex1", 1);
																						// Create a semaphore 'mutex1' with initial value 1 meaning the resource is free
	cout << "Child Process Updating Resource.....\n";

	for (unsigned long long int i = 0; i < 400000ULL; i++) 		// access resource note REDUCE SIZE OF LOOP WHEN USING MUTEX OTHERWISE IT TAKES FOREVER
	{
		T.Wait();
		a = DataPtr->x;
		a = a + 1;
		DataPtr->x = a;	// update resource
		T.Signal();
	}

	return 0;
}