#include "..\rt.h"

//======================
//			Structures
//======================
struct struct1 {
	int integer;
	double dub;
	int array[4];

};
struct struct2 {
	int integer;
	double dub;
	int array[4];
};
struct struct3 {
	int integer;
	double dub;
	int array[4];
};
struct struct4 {
	int integer;
	double dub;
	int array[4];
};
//========================
// End of structures
//=======================

//========================
// Child Threads
//=======================
UINT __stdcall Thread1(void*)
{
	cout << "Child Thread Creating the Pipeline #1.....\n";
	CTypedPipe<struct1>	pipe1("Pipe1", 100);

	//Create local instance of class to hold data from pipeline
	struct1 pipe1data;

	while (1) {
		pipe1.Read(&pipe1data);
		cout << "Thead1 read from Child 1 :\n"
			<< "Integer = " << pipe1data.integer << '\n'
			<< "Double = " << pipe1data.dub << '\n'
			<< "Array = ";
		for (int i = 0; i < std::size(pipe1data.array); i++)
			cout << pipe1data.array[i] << " ";
		cout << '\n';
	}

	return 0;
}

UINT __stdcall Thread2(void*)
{
	cout << "Child Thread Creating the Pipeline #2.....\n";
	CTypedPipe<struct2>	pipe2("Pipe2", 100);
	struct2 pipe2data;

	while (1)
	{
		pipe2.Read(&pipe2data);
		cout << "Thead1 read from Child 2 :\n"
			<< "Integer = " << pipe2data.integer << '\n'
			<< "Double = " << pipe2data.dub << '\n'
			<< "Array = ";
		for (int i = 0; i < std::size(pipe2data.array); i++)
			cout << pipe2data.array[i] << " ";
		cout << '\n';

	}

	return 0;
}

UINT __stdcall Thread3(void*)
{
	cout << "Child Thread Creating the Pipeline #3.....\n";
	CTypedPipe<struct3>	pipe3("Pipe3", 100);

	struct3 pipe3data;

	while (1)
	{
		pipe3.Read(&pipe3data);
		cout << "Thead1 read from Child 3 :\n"
			<< "Integer = " << pipe3data.integer << '\n'
			<< "Double = " << pipe3data.dub << '\n'
			<< "Array = ";
		for (int i = 0; i < std::size(pipe3data.array); i++)
			cout << pipe3data.array[i] << " ";
		cout << '\n';

	}

	return 0;
}

UINT __stdcall Thread4(void*)
{
	cout << "Child Thread Creating the Pipeline #4.....\n";
	CTypedPipe<struct4>	pipe4("Pipe4", 100);

	struct4 pipe4data;

	while (1)
	{
		pipe4.Read(&pipe4data);
		cout << "Thead1 read from Child 4 :\n"
			<< "Integer = " << pipe4data.integer << '\n'
			<< "Double = " << pipe4data.dub << '\n'
			<< "Array = ";
		for (int i = 0; i < std::size(pipe4data.array); i++)
			cout << pipe4data.array[i] << " ";
		cout << '\n';

	}

	return 0;
}

//========================
// End of Child Threads
//=======================

int main()
{
	char Keyboard;

	cout << "Parent Process Creating Child Thread to read to Pipeline #1.....\n";

	CProcess p1("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child1\\Debug\\Child1.exe",
		NORMAL_PRIORITY_CLASS,		//Priority
		OWN_WINDOW,					//Process has own window
		ACTIVE						//Process begins active
	);

	cout << "Parent Process Creating Child Thread to read to Pipeline #2.....\n";

	CProcess p2("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child2\\Debug\\Child2.exe",
		NORMAL_PRIORITY_CLASS,		//Priority
		OWN_WINDOW,					//Process has own window
		ACTIVE						//Process begins active
	);

	cout << "Parent Process Creating Child Thread to read to Pipeline #3.....\n";

	CProcess p3("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child3\\Debug\\Child3.exe",
		NORMAL_PRIORITY_CLASS,		//Priority
		OWN_WINDOW,					//Process has own window
		ACTIVE						//Process begins active
	);

	cout << "Parent Process Creating Child Thread to read to Pipeline #4.....\n";

	CProcess p4("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child4\\Debug\\Child4.exe",
		NORMAL_PRIORITY_CLASS,		//Priority
		OWN_WINDOW,					//Process has own window
		ACTIVE						//Process begins active
	);

	CThread	t1(Thread1, ACTIVE, NULL);
	CThread	t2(Thread2, ACTIVE, NULL);
	CThread	t3(Thread3, ACTIVE, NULL);
	CThread t4(Thread4, ACTIVE, NULL);

	while (1) {

		Keyboard = _getch();					// read next character from keyboard
		cout << "Parent Thread Read " << Keyboard << " from keyboard\n";
	}

	return 0;
}