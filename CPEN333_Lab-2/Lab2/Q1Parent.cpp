#include <iostream>
//#include "../..//RTExamples/RTExamples/rt.h"

//int main()
//{
//
//	std::cout << "Creating child processes...\n";
//
//	CProcess Child1("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-2\\Lab2\\Child1\\Debug\\Child1.exe",	// pathlist to child program executable, Change between Desktop and Laptop				
//		NORMAL_PRIORITY_CLASS,			// priority
//		PARENT_WINDOW,						// process shares parent window					
//		ACTIVE							// process is active immediately
//	);
//	CProcess Child2("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-2\\Lab2\\Child2\\Debug\\Child2.exe",	// pathlist to child program executable				
//		NORMAL_PRIORITY_CLASS,			// priority
//		OWN_WINDOW,						// process has its own window					
//		ACTIVE							// process is active immediately
//	);
//	CProcess Child3("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-2\\Lab2\\Child3\\Debug\\Child3.exe",	// pathlist to child program executable				
//		NORMAL_PRIORITY_CLASS,			// priority
//		OWN_WINDOW,						// process has its own window					
//		ACTIVE							// process is active immediately
//	);
//
//	SLEEP(2000);								//Wait for Child1 process to start
//	SLEEP(0);									//Give up remander of time slot
//	Child1.Suspend();							//Suspend Child1 process
//	cout << "Child1 process Suspended...\n";
//	SLEEP(5000);								//Sleep for a bit
//	cout << "Child1 process resumed...\n";
//	Child1.Resume();							//Resume Child1 process
//	
//	cout << "Child Processes Activated.....\n";
//	Child1.WaitForProcess();					//Pause parent process and wait for Child1 to finish
//	
//	cout << "Child1 process Terminated.....\n";
//	
//	
//
//	cout << "Waiting For Child2 to Terminate.....\n";
//	Child2.WaitForProcess();					// wait for the child process to end
//	cout << "Child2 process terminated...\n";
//	
//
//	cout << "Waiting For Child3 to Terminate.....\n";
//	Child3.WaitForProcess();					// wait for the child process to end
//	cout << "Child3 process terminated...\n";
//
//	return 0;
//}

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

//void _tmain(int argc, TCHAR* argv[])
//{
//	STARTUPINFO si;
//	PROCESS_INFORMATION pi;
//
//	ZeroMemory(&si, sizeof(si));
//	si.cb = sizeof(si);
//	ZeroMemory(&pi, sizeof(pi));
//
//	if (argc != 2)				//Check to make sure an arguement process is given
//	{
//		printf("Usage: %s [cmdline]\n", argv[0]);
//		return;
//	}
//
//	// Start the child process. 
//	if (!CreateProcess(NULL,   // No module name (use command line)
//		argv[1],        // Command line
//		NULL,           // Process handle not inheritable
//		NULL,           // Thread handle not inheritable
//		TRUE,          // Set handle inheritance to FALSE
//		0,              // No creation flags
//		NULL,           // Use parent's environment block
//		NULL,           // Use parent's starting directory 
//		&si,            // Pointer to STARTUPINFO structure
//		&pi)           // Pointer to PROCESS_INFORMATION structure
//		)
//	{
//		printf("CreateProcess failed (%d).\n", GetLastError());
//		return;
//	}
//
//	// Wait until child process exits.
//	WaitForSingleObject(pi.hProcess, INFINITE);
//
//	// Close process and thread handles. 
//	CloseHandle(pi.hProcess);
//	CloseHandle(pi.hThread);
//}

