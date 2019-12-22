#include "..\rt.h"
#include "Monitor.h"

//For this part of the lab you are asked to write a “Named” monitor class (see RTExamples Q8 for ideas)
//to encapsulate the single integer variable ‘x’ as seen in Part A above.The monitor should provide simple
//interface functions such as read(), write(), increment() etc.and a constructor to initialise the data.

int main()
{
	Monitor M1("Bill");
	M1.write(0);	//Initalize x to 0

	CProcess p1("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_lab-5\\Lab5_C\\Debug\\Lab5_c_Child.exe",
		NORMAL_PRIORITY_CLASS,
		PARENT_WINDOW,
		ACTIVE
	);

	for (int i = 0; i < 30000; i++)
		M1.increment_x();

	p1.WaitForProcess();		//Wait for child proccess to terminate

	cout << "The final value of X is " << M1.read() << endl;

	return 0;
}