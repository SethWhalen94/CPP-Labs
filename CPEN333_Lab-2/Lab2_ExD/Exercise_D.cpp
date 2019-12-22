#include "..\rt.h"

typedef struct
{
	int myint;
	double myfloat;
	std::string mystring;
}ThreadData;


UINT __stdcall ChildThread1(void* args)
{
	ThreadData data1 = *(ThreadData*)(args); //Cast args to type ThreadData * then dereference to get Struct items
	

	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from child process 1....\n";
		cout << "My integer data is " << data1.myint << '\n';
		cout << "My double data is " << data1.myfloat << '\n';
		cout << "My string data is " << data1.mystring << '\n';
		Sleep(50);
	}
	return 0;

}

UINT __stdcall ChildThread2(void* args)
{
	ThreadData data2 = *(ThreadData*)(args); //Cast args to type ThreadData * then dereference to get Struct items

	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from child process 2....\n";
		cout << "My integer data is " << data2.myint << '\n';
		cout << "My double data is " << data2.myfloat << '\n';
		cout << "My string data is " << data2.mystring << '\n';
		Sleep(50);
	}
	return 0;

}

UINT __stdcall ChildThread3(void* args)
{
	ThreadData data3 = *(ThreadData*)(args); //Cast args to type ThreadData * then dereference to get Struct items

	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from child process 3....\n";
		cout << "My integer data is " << data3.myint << '\n';
		cout << "My double data is " << data3.myfloat << '\n';
		cout << "My string data is " << data3.mystring << '\n';
		Sleep(50);
	}
	return 0;

}



//int main()
//{
//
//	ThreadData d1 = { 1, 1.1, "Child1" };	//Child1 thread data
//	ThreadData d2 = { 2, 2.2, "Child2" }; //Child2 thread data
//	ThreadData d3 = { 3, 3.3, "Child3" }; //Child3 thread data
//
//	//const ThreadData* ptr1 = &d1;				//Pointer to child1 data
//	//const ThreadData* ptr2 = &d2;				//Pointer to child2 data
//	//const ThreadData* ptr3 = &d3;				//Pointer to child3 data
//
//
//	cout << "Creating child processes...\n";
//
//	CThread t1(ChildThread1, ACTIVE, &d1);		//Create 3 active secondary child threads with ptr to structs
//	CThread t2(ChildThread2, ACTIVE, &d2);
//	CThread t3(ChildThread3, ACTIVE, &d3);
//
//	cout << "Waiting for Child1 thread to terminate....\n";
//	t1.WaitForThread();
//	
//	cout << "Waiting for Child2 thread to terminate....\n";
//	t2.WaitForThread();
//
//	cout << "Waiting for Child3 thread to terminate....\n";
//	t3.WaitForThread();
//
//
//	return 0;
//}