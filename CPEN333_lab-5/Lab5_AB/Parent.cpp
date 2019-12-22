#include "..\rt.h"
#include <atomic>
atomic_flag flag;

//=========================
//	Child Thread
//=========================
UINT __stdcall Thread1(void* args)
{
	CSemaphore T("Mutex1", 1);	//Creating a Mutex

	for (int i = 0; i < 100000L; i++)
	{
		//while (flag.test_and_set() == TRUE)
		//{
		//	MOVE_CURSOR(20, 20); // move cursor to cords [x,y] = 20,20
		//	cout << "Hello from Thread 2\n";
		//	cout.flush(); // force output to be written to screen
		//}
		//flag.clear();

		T.Wait();
		MOVE_CURSOR(20, 20); // move cursor to cords [x,y] = 20,20
		cout << "Hello from Thread 2\n";
		cout.flush(); // force output to be written to screen
		T.Signal();
	}

	return 0;
}

//=========================
//	Parent Thread
//=========================
int main()
{
	CSemaphore T("Mutex1", 1);	//Creating a Mutex

	flag.clear();

	CThread t1(Thread1, ACTIVE,NULL);	//Creating child thread
	
	for (int i = 0; i < 100000L; i++)
	{
		//ATOMIC FLAG SOLUTION
		//while (flag.test_and_set() == TRUE)
		//{
		//	MOVE_CURSOR(10, 10); // move cursor to cords [x,y] = 10,10
		//	cout << "Hello from Thread 1\n";
		//	cout.flush(); // force output to be written to screen
		//}
		//flag.clear();

		//MUTEX SOLUTION
		T.Wait();
		MOVE_CURSOR(10, 10); // move cursor to cords [x,y] = 20,20
		cout << "Hello from Thread 1\n";
		cout.flush(); // force output to be written to screen
		T.Signal();
	}

	t1.WaitForThread();
	return 0;
}