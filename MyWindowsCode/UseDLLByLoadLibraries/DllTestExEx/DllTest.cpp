#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
DWORD WINAPI Thread_func(PVOID pvParam)
{
	printf("a new thread\n");
	return 1;
}
int main()
{
	HINSTANCE hDll = LoadLibrary(_T("UseDllEx.dll"));
	if (hDll == NULL) printf("wrong\n");
	FARPROC pfn = GetProcAddress(hDll,_T("test"));
	printf("%d\n",pfn());
	DWORD dwId;
	HANDLE hThread = CreateThread(NULL,0,Thread_func,NULL,0,&dwId);
	WaitForSingleObject(hThread,INFINITE);
	CloseHandle(hThread);
	FreeLibrary(hDll);
	system("pause");
}