/*
**	Win32 code program to solve the graphical problem illustrated previously. The single Producer
**	Single Consumer arrangement. Let's assume this is both the Producer and the Parent program
*/

#include 	<stdio.h>
#include	"..\rt.h"			// change pathlist to "rt.h" to suit location on disk

struct		mydatapooldata1 {		// template for the data in a datapool
	int 	x ;						// just a single int
} ;

//struct		mydatapooldata2 {		// template for the data in a datapool
//	double 	y;						// just a single double
//};

mydatapooldata1 	*PS1DataPointer;		// pointer to the actual data pool
//mydatapooldata2* PS2DataPointer;

int 	main()
{
	CSemaphore		ps1("PS1", 0, 1) ;    // semaphore with initial value 0 and max value 1
	//CSemaphore		ps2("PS2", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs1("CS1", 1, 1) ;    // semaphore with initial value 1 and max value 1

//	Create a datapool and then get a pointer to it

	CDataPool dp1("DataPoolPS1", sizeof(struct mydatapooldata1));
	//CDataPool dp2("DatapoolPS2", sizeof(struct mydatapooldata2));
	PS1DataPointer = (mydatapooldata1 *)dp1.LinkDataPool() ;	// get pointers to data pools
	//PS2DataPointer = (mydatapooldata2*)(dp2.LinkDataPool());

//
//	Now that we have created the semaphores, let's create the child process
//"E:\Panda\Desktop\CPEN_333_Projects\CPEN333_lab-5\Q9 - ProducerConsumerProblem\Q9Child\debug\Q9Child.exe"

	CProcess p1("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_lab-5\\Q9 - ProducerConsumerProblem\\Q9Child\\debug\\Q9Child.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,					// process has its own window
		ACTIVE							// process is active immediately
	) ;

	CProcess p2("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_lab-5\\Q9 - ProducerConsumerProblem\\Debug\\Q9Producer2.exe",
		NORMAL_PRIORITY_CLASS,
		OWN_WINDOW,
		ACTIVE);

	printf("Producer one Process Running.....\n") ;

	for(int i = 0; i < 100; i ++)	 {	// Produce 10 lots of data
		cs1.Wait() ;			// wait for consumer process to signal consumer semaphore
//		cout << "Hit RETURN to Produce Data.....\n";
//		getchar() ;
		PS1DataPointer->x = i+10 ;	// generate data and store in datapool
		ps1.Signal() ;			// signal the producer semaphore to wake up the consumer
		cout << "Produced 1 Produced " << i << ".....\n";
	}

//	p1.WaitForProcess() ;		// wait for the child process to terminate if necessary

	return 0 ;				// sempahores destroyed here
}