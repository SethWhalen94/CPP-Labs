
//#include <winnt.h>
#include <iostream>
#include <thread>

void foo(double y)
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << "I am child thread foo and my data is " << y << '\n';

	}
}

void bar(int x)
{

	for (int i = 0; i < 200; i++)
	{
		std::cout << "I am child thread bar and my data is " << x << '\n';

	}

}


int main()
{
	std::thread t1(foo,3.14);		//Spawn new thread that calls foo funtion with argument = 3.14
	std::thread t2(bar, 23);		//Spawn new thread that calls bar funtion with argument = 23

	std::cout << "main, foo and bar are now executing concurrently...\n";

	//Synchronoze threads
	t1.join();				//Pause parent until t1 finishes
	std::cout << "child thread foo is now terminated...\n";
	//Sleep(5000);
	t2.join();				//Pause parent until t2 finishes
	std::cout << "child thread bar is now terminated...\n";

	return 0;

}