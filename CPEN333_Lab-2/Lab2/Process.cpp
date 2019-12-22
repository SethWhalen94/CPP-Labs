#include "MyProcess.h"


MyProcess::MyProcess(const string& Name, 
				int Priority,
				BOOL b_windowUse,
				BOOL b_createSuspended,
				const string& ChildProcessArgs)
				:ProcessName(Name)
{

	STARTUPINFO	StartupInfo = {
		sizeof(STARTUPINFO) ,
		NULL ,			// reserved
		NULL ,			// ignored in console applications
		(char*)(Name.c_str()) ,	// displayed in title bar for console applications
		0,0,			// dwx, dwy, offset of top left of new window relative to top left of screen in pixel
						// flags below must specify STARTF_USEPOSITION. Ignored for console apps'
		0,0,			// dwxsize, dwysize: Width and height of the window if new window specified
						// must use flags STARTF_USESIZE. Ignored for console apps'
		0,0,			// size of console in characters, only if STARTF_USECOUNTCHARS flag specified, 
						// Ignored for console apps
		0,				// Colour control, for background and text. Ignored for console apps
		0,				// Flags. Ignored for console applications
		0,				// ignored unless showwindow flag set
		0 ,
		NULL,
		0,0,0			// stdin, stdout and stderr handles (inherited from parent)
	};

	UINT flags = Priority; // Priority,

	if (b_windowUse == OWN_WINDOW)		// if caller has specified that child should have its won window
		flags |= CREATE_NEW_CONSOLE;

	if (b_createSuspended == SUSPENDED)	// if caller has specified that child process should be immediately suspended
		flags |= CREATE_SUSPENDED;

	BOOL Success = CreateProcess(NULL,	// application name
		(char*)(Name.c_str()),			// Command line to the process if you want to pass one to main() in the process
		NULL,			// process attributes
		NULL,			// thread attributes
		TRUE,			// inherits handles of parent
		flags,			// Priority and Window control flags,
		NULL,			// use environent of parent
		NULL,			// use same drive and directory as parent
		&StartupInfo,	// controls appearance of process (see above)
		&pInfo			// Stored process handle and ID into this object
	);


}

BOOL MyProcess::WaitForProcess(DWORD Time) const
{
	UINT Result = WaitForSingleObject(GetProcessHandle(), Time);

	return Result;
}

BOOL MyProcess::Suspend() const
{

	UINT	Result = SuspendThread(GetThreadHandle());
	//PERR(Result != 0xffffffff, string("Cannot Suspend Thread\n"));	// check for error and print message if appropriate

	if (Result != 0xffffffff)
		return TRUE;
	else
		return FALSE;

}

BOOL MyProcess::Resume() const
{
	UINT	Result = ResumeThread(GetThreadHandle());
	//PERR(Result != 0xffffffff, string("Cannot Resume Process: ") + ProcessName);

	if (Result != 0xffffffff)	// if no error
		return TRUE;
	else
		return FALSE;

}



int main()
{
	cout << "Creating child processes....\n";

	MyProcess c1("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-2\\Lab2\\Child1\\Debug\\Child1.exe",	// pathlist to child program executable, Change between Desktop and Laptop				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process shares parent window					
		SUSPENDED							// process is active immediately
	);

	MyProcess c2("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-2\\Lab2\\Child2\\Debug\\Child2.exe",	// pathlist to child program executable, Change between Desktop and Laptop				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process shares parent window					
		ACTIVE							// process is active immediately
	);

	MyProcess c3("E:\\Panda\\Desktop\\CPEN_333_Projects\\CPEN333_Lab-2\\Lab2\\Child3\\Debug\\Child3.exe",	// pathlist to child program executable, Change between Desktop and Laptop				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process shares parent window					
		ACTIVE							// process is active immediately
	);

	cout << "Waiting For Child1 to Terminate.....\n";
	//c1.Resume();

	if (c1.Resume() == FALSE) {
		perror("Cannot Resume Process");
		exit(0);
	}
	else
		cout << "Child1 process resumed....\n";

	Sleep(2000);		//Wait for Child1 process to begin
	//Sleep(0);			//Give up remainder of time slot
	//c1.Suspend();
	if (c1.Suspend() == FALSE) {			//Check if child1 process can be suspended
		perror("Cannot Suspend Process");
		exit(0);
	}
	else 
		cout << "Child1 process suspended....\n";

	Sleep(7000);
	
	if (c1.Resume() == FALSE) {				//Check if child process can be resumed
		perror("Cannot Resume Process");
		exit(0);
	}
	else
		cout << "Child1 process resumed....\n";


	cout << "Waiting For Child2 to Terminate.....\n";
	c2.WaitForProcess();

	cout << "Waiting For Child3 to Terminate.....\n";
	c3.WaitForProcess();

	return 0;
}