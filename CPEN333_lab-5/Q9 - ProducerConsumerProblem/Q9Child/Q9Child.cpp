//////////////////////////////////////////////////////////////////////////////////
//	The Consumer Process
//////////////////////////////////////////////////////////////////////////////////

#include 	<stdio.h>
#include	"..\..\rt.h"			// change pathlist to "rt.h" to suit location on disk

struct		mydatapooldata1 {			// template for data in a datapool
	int x ;						// just a single int
} ;

struct		mydatapooldata2 {		// template for the data in a datapool
	double 	y;						// just a single double
};


mydatapooldata1* TheDataPointer ;		// pointer to the data pool
mydatapooldata2* PS2DataPointer;
int main()
{
	CSemaphore		ps1("PS1", 0, 1) ;    // semaphore with initial value 0 and max value 1
	CSemaphore		ps2("PS2", 0, 1);
	CSemaphore		cs1("CS1", 1, 1) ;    // semaphore with initial value 1 and max value 1
	CSemaphore		cs2("CS2", 1, 1);

//	Create a datapool and then get a pointer to it

	CDataPool dp1("DataPoolPS1", sizeof(struct mydatapooldata1));
	CDataPool dp2("DataPoolPS2", sizeof(mydatapooldata2));
	TheDataPointer = (struct mydatapooldata1 *)(dp1.LinkDataPool()) ; // get pointer to data pool
	PS2DataPointer = (mydatapooldata2*)(dp2.LinkDataPool());

	cout << "Consumer Process Running.....\n";

		while(1)
		{
			cout << "Hit RETURN to Consume Data.....\n";
			getchar();

			if (ps2.Read() > 0)
			{
				ps2.Wait();		// wait for producer process to signal producer semaphore
				cout << "Consumed: " << PS2DataPointer->y << '\n';
				cs2.Signal();		// signal the consumer semaphore to wake up the producer
			}

			if (ps1.Read() > 0)
			{
				ps1.Wait();		// wait for producer process to signal producer semaphore
				cout << "Consumed: " << TheDataPointer->x << '\n';
				cs1.Signal();		// signal the consumer semaphore to wake up the producer
			}

			

		}

	getchar() ;
	return 0 ;
}
