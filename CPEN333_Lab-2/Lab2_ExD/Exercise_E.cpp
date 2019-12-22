#include "Thread.h"

typedef struct
{
	int myint;
	double myfloat;
	std::string mystring;
}ThreadData;


UINT __stdcall NewThread1(void* args)
{
	ThreadData data1 = *(ThreadData*)(args); //Cast args to type ThreadData * then dereference to get Struct items


	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from New process 1....\n";
		cout << "My integer data is " << data1.myint << '\n';
		cout << "My double data is " << data1.myfloat << '\n';
		cout << "My string data is " << data1.mystring << '\n';
		Sleep(50);
	}
	return 0;

}

UINT __stdcall NewThread2(void* args)
{
	ThreadData data2 = *(ThreadData*)(args); //Cast args to type ThreadData * then dereference to get Struct items

	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from New process 2....\n";
		cout << "My integer data is " << data2.myint << '\n';
		cout << "My double data is " << data2.myfloat << '\n';
		cout << "My string data is " << data2.mystring << '\n';
		Sleep(50);
	}
	return 0;

}

UINT __stdcall NewThread3(void* args)
{
	ThreadData data3 = *(ThreadData*)(args); //Cast args to type ThreadData * then dereference to get Struct items

	int i;
	for (i = 0; i < 200; i++) {
		cout << "Hello from New process 3....\n";
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
//	ThreadData d1 = { 1, 1.1, "New1" };	//New1 thread data
//	ThreadData d2 = { 2, 2.2, "New2" }; //New2 thread data
//	ThreadData d3 = { 3, 3.3, "New3" }; //New3 thread data
//
//	//const ThreadData* ptr1 = &d1;				//Pointer to New1 data
//	//const ThreadData* ptr2 = &d2;				//Pointer to New2 data
//	//const ThreadData* ptr3 = &d3;				//Pointer to New3 data
//
//
//	cout << "Creating New processes...\n";
//
//	Thread t1(NewThread1, ACTIVE, &d1);		//Create 3 active secondary New threads with ptr to structs
//	Thread t2(NewThread2, ACTIVE, &d2);
//	Thread t3(NewThread3, ACTIVE, &d3);
//
//	cout << "Waiting for New1 thread to terminate....\n";
//	t1.WaitForThread();
//
//	cout << "Waiting for New2 thread to terminate....\n";
//	t2.WaitForThread();
//
//	cout << "Waiting for New3 thread to terminate....\n";
//	t3.WaitForThread();
//
//
//	return 0;
//}