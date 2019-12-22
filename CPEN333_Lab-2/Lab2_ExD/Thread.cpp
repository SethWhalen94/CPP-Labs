#include "Thread.h"

HANDLE	GET_STDOUT()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

//	moves the cursor to the x,y coord on the screen. [0,0] is top left
//	all calls to printf cause output to occur at the current cursor position
//	obviously, the cursor moves with text output operations

void MOVE_CURSOR(int x, int y)
{
	COORD	c = { (short)x, (short)y };
	SetConsoleCursorPosition(GET_STDOUT(), c);
}

//
//	These two functions turns on/off reverse video, so that text comes black on white background
//	For more details set the SetConsoleTextAttribute() function in on-line
//	help
//

void REVERSE_ON()
{
	SetConsoleTextAttribute(GET_STDOUT(),
		BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}

void REVERSE_OFF()
{
	SetConsoleTextAttribute(GET_STDOUT(),
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void PERR(bool bSuccess, string ErrorMessageString)
{
	UINT LastError = GetLastError();

	if (!(bSuccess)) {
		char buff[512];
		Beep(500, 100);
		MOVE_CURSOR(0, 0);
		REVERSE_ON();
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, LastError,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buff, 1024, NULL);
		printf(" Error %d in Process %s: line %d:\n", LastError, __FILE__, __LINE__);
		printf(" Translation: %s Error: %s", buff, ErrorMessageString.c_str());
		REVERSE_OFF();
		printf("\n\nPress Return to Continue...");
		_getch();
	}
}

Thread::Thread(UINT __stdcall Function(void*),	// name/pointer to function that is to be the new thread
	BOOL bCreateState,			// use SUSPENDED thread created in suspended state
										// use ACTIVE to make thread active
	void* ThreadArgs)

{
	UINT	ThreadControlFlags = 0;

	if (bCreateState == SUSPENDED)		// if caller wants thread initially suspended
		ThreadControlFlags = CREATE_SUSPENDED;

	ThreadHandle = (HANDLE)(_beginthreadex(NULL, 0, Function, ThreadArgs, ThreadControlFlags, &ThreadID));
	PERR(ThreadHandle != 0, string("Unable to Create Thread"));	// check for error and print message if appropriate

}

BOOL Thread::Suspend() const
{
	UINT	Result = SuspendThread(ThreadHandle);
	PERR(Result != 0xffffffff, string("Cannot Suspend Thread\n"));	// check for error and print message if appropriate

	if (Result != 0xffffffff)
		return TRUE;
	else
		return FALSE;

}

BOOL Thread::Resume() const
{
	UINT	Result = ResumeThread(ThreadHandle);
	PERR(Result != 0xffffffff, string("Cannot Resume Thread\n"));	// check for error and print message if appropriate

	if (Result != 0xffffffff)
		return TRUE;
	else
		return FALSE;
}

UINT Thread::WaitForThread(DWORD Time) const
{
	UINT Result = WaitForSingleObject(ThreadHandle, Time);	// return WAIT_FAILED on error
	PERR(Result != WAIT_FAILED, string("Cannot Wait For Thread"));	// check for error and print error message as appropriate

	return Result;
}

BOOL Thread::SetPriority(UINT Priority) const
{
	BOOL Success;

	// check for error in priority value and print message if appropriate

	PERR(((Priority == THREAD_PRIORITY_ABOVE_NORMAL) ||
		(Priority == THREAD_PRIORITY_BELOW_NORMAL) ||
		(Priority == THREAD_PRIORITY_HIGHEST) ||
		(Priority == THREAD_PRIORITY_IDLE) ||
		(Priority == THREAD_PRIORITY_LOWEST) ||
		(Priority == THREAD_PRIORITY_NORMAL) ||
		(Priority == THREAD_PRIORITY_TIME_CRITICAL)),
		string("Illegal Priority value specified for Thread in call to CThread::SetPriority()"));

	Success = SetThreadPriority(ThreadHandle, Priority);	// set priority

	PERR(Success == TRUE, string("Cannot Set Thread Priority\n"));	// check for error and print message if appropriate

	return Success;

}

void Thread::Exit(UINT ExitCode) const
{
	ExitThread(ExitCode);
}