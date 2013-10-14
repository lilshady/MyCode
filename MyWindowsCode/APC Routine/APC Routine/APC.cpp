#include <Windows.h>
#include <stdio.h>
#include <process.h>
HANDLE hTimer;
typedef unsigned (__stdcall *PTHREAD_START)(void*);
DWORD WINAPI newThread(PVOID pvParam)
{
	WaitForSingleObject(hTimer,INFINITE);
	printf("this is from new Thread\n");
	return 0;
}

void APIENTRY ApcRoutine(PVOID pvArg,DWORD dwTimerLowValue,DWORD dwTimerHighValue)
{
	printf("this is from APC routine\n");
}
int main()
{   
	DWORD dwThreadId;
	hTimer = CreateWaitableTimer(NULL,TRUE,NULL);
	LARGE_INTEGER li = { 0 };
	SetWaitableTimer(hTimer,&li,5000,ApcRoutine,NULL,false);
	_beginthreadex(NULL,0,(PTHREAD_START)newThread,NULL,0,(unsigned*)&dwThreadId);
	printf("this is from main\n");
	SleepEx(INFINITE,TRUE);
	CloseHandle(hTimer);
	system("pause");
	return 0;
}