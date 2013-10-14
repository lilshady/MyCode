#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
int main()
{
	HANDLE hFile = CreateFile(_T("test.txt"),GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	HANDLE hMapping = CreateFileMapping(hFile,NULL,PAGE_READWRITE,0,0,_T("test"));
	PBYTE pbFile = (PBYTE)MapViewOfFile(hMapping,FILE_MAP_ALL_ACCESS,0,0,0);
	//CreateProcess()
	for(int i = 0; i < 10; ++i)
	{
		pbFile[i] = 'L';
	}
	UnmapViewOfFile(pbFile);
	CloseHandle(hMapping);
	CloseHandle(hFile);
	return 0 ;
}