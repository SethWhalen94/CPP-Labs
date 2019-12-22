#ifndef __Monitor__
#define __Monitor__

#include "..\rt.h"

class Monitor {

private:
	int x;
	CDataPool* theDataPool;	// a datapool containing the data to be protected double balance; 
	CMutex* theMutex;	// a pointer to a hidden mutex protecting the x variable above
	int* x_ptr;			//Pointer to the data in the datapool

public:

	//==================
	//Constructor
	//==================
	Monitor(string Name)
	{
		theMutex = new CMutex(string("__Mutex__") + string(Name));
		theDataPool = new CDataPool(string("__DataPool__") + string(Name), sizeof(x));
		x_ptr = (int*)(theDataPool->LinkDataPool());		//Link x to datapool
	}

	//==================
	// Member Functions
	//==================
	int read()
	{
		int temp;

		theMutex->Wait();
		temp = *x_ptr;
		theMutex->Signal();

		return temp;
	}

	void write(int new_x)
	{
		theMutex->Wait();

		*x_ptr = new_x;

		theMutex->Signal();

	}

	void increment_x()
	{
		theMutex->Wait();
		*x_ptr = *x_ptr + 1;
		theMutex->Signal();
	}

	//==================
	// End of Member Functions
	//==================

	//==================
	//Destructor
	//==================
	~Monitor()
	{
		delete theMutex;
		delete theDataPool;
		x_ptr = NULL;

	}
};



#endif // !__Monitor__

