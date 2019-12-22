//#include "../rt.h"
//
//struct struct1 {
//	int integer;
//	double dub;
//	int array[4];
//
//};
//struct struct2 {
//	int integer;
//	double dub;
//	int array[4];
//};
//struct struct3 {
//	int integer;
//	double dub;
//	int array[4];
//};
//struct struct4 {
//	int integer;
//	double dub;
//	int array[4];
//};
//
//
//int main()
//{
//	struct1 pipe1data;
//	struct2 pipe2data;
//	struct3 pipe3data;
//	struct4 pipe4data;
//
//	TEXT_COLOUR(4);
//
//	//===== Parent opens 4 different pipelines, 1 for each child ======//
//	cout << "Parent Process Creating the Pipeline #1.....\n";
//	CTypedPipe<struct1>	pipe1("Pipe1", 100);							
//	cout << "Parent Process Creating the Pipeline #2.....\n";
//	CTypedPipe<struct2>	pipe2("Pipe2", 100);
//	cout << "Parent Process Creating the Pipeline #3.....\n";
//	CTypedPipe<struct3>	pipe3("Pipe3", 100);
//	cout << "Parent Process Creating the Pipeline #4.....\n";
//	CTypedPipe<struct4>	pipe4("Pipe4", 100);
//
//	cout << "Parent Process Creating Child Process to write to Pipeline #1.....\n";
//
//	CProcess p1("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child1\\Debug\\Child1.exe",
//		NORMAL_PRIORITY_CLASS,		//Priority
//		OWN_WINDOW,					//Process has own window
//		ACTIVE						//Process begins active
//	);
//
//	cout << "Parent Process Creating Child Process to write to Pipeline #2.....\n";
//
//	CProcess p2("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child2\\Debug\\Child2.exe",
//		NORMAL_PRIORITY_CLASS,		//Priority
//		OWN_WINDOW,					//Process has own window
//		ACTIVE						//Process begins active
//	);
//
//	cout << "Parent Process Creating Child Process to write to Pipeline #3.....\n";
//
//	CProcess p3("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child3\\Debug\\Child3.exe",
//		NORMAL_PRIORITY_CLASS,		//Priority
//		OWN_WINDOW,					//Process has own window
//		ACTIVE						//Process begins active
//	);
//
//	cout << "Parent Process Creating Child Process to write to Pipeline #4.....\n";
//
//	CProcess p4("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-4\\Lab4_PartB\\Child4\\Debug\\Child4.exe",
//		NORMAL_PRIORITY_CLASS,		//Priority
//		OWN_WINDOW,					//Process has own window
//		ACTIVE						//Process begins active
//	);
//
//	while (1)
//	{
//		if ((pipe1.TestForData()) >= sizeof(pipe1data))
//		{
//			pipe1.Read(&pipe1data);
//			cout << "Parent read from Child 1 :\n"
//				<< "Integer = " << pipe1data.integer << '\n'
//				<< "Double = " << pipe1data.dub << '\n'
//				<< "Array = ";
//			for (int i = 0; i < std::size(pipe1data.array); i++)
//				cout << pipe1data.array[i] << " ";
//			cout << '\n';
//		}
//		if ((pipe2.TestForData()) >= 1)
//		{
//			pipe2.Read(&pipe2data);
//			cout << "Parent read from Child 2 :\n"
//				<< "Integer = " << pipe2data.integer << '\n'
//				<< "Double = " << pipe2data.dub << '\n'
//				<< "Array = ";
//			for (int i = 0; i < std::size(pipe2data.array); i++)
//				cout << pipe2data.array[i] << " ";
//			cout << '\n';
//		}
//		if ((pipe3.TestForData()) >=1)
//		{
//			pipe3.Read(&pipe3data);
//			cout << "Parent read from Child 3 :\n"
//				<< "Integer = " << pipe3data.integer << '\n'
//				<< "Double = " << pipe3data.dub << '\n'
//				<< "Array = ";
//			for (int i = 0; i < std::size(pipe3data.array); i++)
//				cout << pipe3data.array[i] << " ";
//			cout << '\n';
//
//		}if ((pipe4.TestForData()) >= sizeof(pipe4data))
//		{
//			pipe4.Read(&pipe4data);
//			cout << "Parent read from Child 4 :\n"
//				<< "Integer = " << pipe4data.integer << '\n'
//				<< "Double = " << pipe4data.dub << '\n'
//				<< "Array = ";
//			for (int i = 0; i < std::size(pipe4data.array); i++)
//				cout << pipe4data.array[i] << " ";
//			cout << '\n';
//		}
//
//		/*p1.WaitForProcess();
//		p2.WaitForProcess();
//		p3.WaitForProcess();
//		p4.WaitForProcess();*/
//	}
//
//	
//
//	return 0;
//}