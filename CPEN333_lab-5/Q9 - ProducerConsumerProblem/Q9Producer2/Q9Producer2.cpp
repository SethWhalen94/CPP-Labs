#include "..\..\rt.h"

struct		mydatapooldata2 {		// template for the data in a datapool
	double 	y;						// just a single double
};

int main()
{
	CSemaphore		ps2("PS2", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs2("CS2", 1, 1);    // semaphore with initial value 1 so it is ready to read data and max value 1

	mydatapooldata2* PS2DataPointer;	//pointer to struct data
	//CDataPool dp2("DatapoolPS2", sizeof(mydatapooldata2));
	CDataPool dp2("DataPoolPS2", sizeof(mydatapooldata2));

	PS2DataPointer = (mydatapooldata2*)(dp2.LinkDataPool());

	printf("Producer two Process Running.....\n");

	for (int i = 0; i < 100; i++) {	// Produce 10 lots of data
		cs2.Wait();			// wait for consumer process to signal consumer semaphore
//		cout << "Hit RETURN to Produce Data.....\n";
//		getchar() ;
		PS2DataPointer->y = i + 1.1;	// generate data and store in datapool
		ps2.Signal();			// signal the producer semaphore to wake up the consumer
		cout << "Producer 2 Produced " << PS2DataPointer->y << ".....\n";
	}
		return 0;

}