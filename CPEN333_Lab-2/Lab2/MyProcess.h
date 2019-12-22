#ifndef __MyProcess__
#define __MyProcess__
#include <process.h>	// for spawnl and createthread
#include <windows.h>	// for perror and sleep
#include <stdio.h>		// for printf
#include <limits.h>		// for UINT_MAX
#include <conio.h>		// for _kbhit(), getch() and getche()
#include <iostream>
#include <string>

#define SUSPENDED			101000		// for threads
#define ACTIVE				101001		// for thread
#define OWN_WINDOW			101002		// for FORK_PROCESS
#define PARENT_WINDOW		101003		// ditto

using namespace std;


class MyProcess {

private:
	PROCESS_INFORMATION pInfo;
	const string ProcessName;
	HANDLE	ThreadHandle;	// handle to thread

public:
	//********Default Constructor that takes 4 arguements******
	//Name: this is the file path to the child process EXE file
	//Priority: Set the priority of the process
	//createSuspended: set whether the child process is suspended or not when being created
	//ChildProcessArgs: Arguements for the child process
	MyProcess(const string &Name,
			int Priority = NORMAL_PRIORITY_CLASS,	//From WinBase.h
			BOOL b_windowUse = PARENT_WINDOW,
			BOOL b_createSuspended = ACTIVE,			// use SUSPENDED to make new child processes main thread suspended when process is created
			const string& ChildProcessArgs = ""	// use ACTIVE to make new child processes main thread active when process iscreated
			);		
	virtual ~MyProcess() {};

	inline HANDLE	GetProcessHandle() const { return pInfo.hProcess; }		// get the process's handle
	inline HANDLE	GetThreadHandle() const { return pInfo.hThread; }		// get the process's main thread handle

	//Process class member function definitions
	BOOL WaitForProcess(DWORD Time = INFINITE) const;
	BOOL Suspend() const;
	BOOL Resume() const;

};

#endif // __MyProcess__
