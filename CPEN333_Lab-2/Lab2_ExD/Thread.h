#ifndef	__Thread__
#define __Thread__

#include <process.h>	// for spawnl and createthread
#include <windows.h>	// for perror and sleep
#include <stdio.h>		// for printf
#include <limits.h>		// for UINT_MAX
#include <conio.h>		// for _kbhit(), getch() and getche()
#include <iostream>
#include <string>

using namespace std;

#define SUSPENDED			101000		// for threads
#define ACTIVE				101001		// for thread
#define OWN_WINDOW			101002		// for FORK_PROCESS
#define PARENT_WINDOW		101003		// ditto
#define MAXMESSAGEVALUE		32000		// maximum value of a user generated message

class Thread
{

private:
	//##ModelId=3DE6123A0164
	HANDLE	ThreadHandle;	// handle to thread
	//##ModelId=3DE6123A016E
	UINT	ThreadID;		// id of thread

public:
	//##ModelId=3DE6123A0182
	Thread(UINT __stdcall Function(void*),	// name/pointer to function that is to be the new thread
		BOOL bCreateState = ACTIVE,			// use SUSPENDED thread created in suspended state
											// use ACTIVE to make thread active
		void* ThreadArgs = NULL);			// any args to the thread


	//##ModelId=3DE6123A018C
	inline virtual ~Thread() { ::TerminateThread(ThreadHandle, 0); }


	//##ModelId=3DE6123A018E
	inline HANDLE	GetThreadHandle() const { return ThreadHandle; }
	//##ModelId=3DE6123A0197
	inline UINT	GetThreadID() const { return ThreadID; }

	//##ModelId=3DE6123A01A0
	inline operator HANDLE() const { return ThreadHandle; }
	//##ModelId=3DE6123A01A2
	inline operator UINT()	const { return ThreadID; }

	//##ModelId=3DE6123A01AA
	BOOL Suspend() const;					// can be used to suspend the thread
	//##ModelId=3DE6123A01B4
	BOOL Resume() const;					// can be used to activate a suspended thread
	//##ModelId=3DE6123A01B6
	UINT WaitForThread(DWORD Time = INFINITE) const;			// caller waits for the thread to terminate
	//##ModelId=3DE6123A01BF
	BOOL SetPriority(UINT Priority) const;	// caller sets thread priority, see SET_THREAD_PRORITY() in rt.cpp
	//##ModelId=3DE6123A01CA
	BOOL Post(UINT Message) const;		// caller sends a signal/message to the thread

private:
	//##ModelId=3DE6123A01D4
	void Exit(UINT ExitCode = 0) const;		// called by thread to terminate itself

	inline BOOL TerminateThread(DWORD ExitStatus = 0) { return ::TerminateThread(ThreadHandle, ExitStatus); }
};




#endif
