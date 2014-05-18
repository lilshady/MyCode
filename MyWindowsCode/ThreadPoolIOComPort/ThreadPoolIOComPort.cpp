#include <Windows.h>
#include <iostream>
PTP_IO ioobject;
VOID CALLBACK OverlappedCompletionRoutine(PTP_CALLBACK_INSTANCE pInstance,
	                                      PVOID pvContext,
										  PVOID pOverlapped,
										  ULONG IoResult,
										  ULONG_PTR numberofBytes,
										  PTP_IO pIo)
{
	if (IoResult == NO_ERROR )
		std::cout<<"THE PROCESS is done successfully"<<std::endl<<"the bytes are"<<numberofBytes<<std::endl;
}																																														

DWORD WINAPI ThreadFunc(PVOID pvParam)
{   /*等待一个线程池IO请求完成*/
	WaitForThreadpoolIoCallbacks(ioobject,false);
	std::cout<<"THE another thread is done successfully"<<std::endl;
	return 0;

}


int main()
{
	HANDLE hFile = CreateFile(TEXT("D:\\my.txt"),GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_FLAG_OVERLAPPED,NULL);
	
	TCHAR t[] = {'a','b','c','\0'};

	/*
	33行创建一个线程池的IO对象，其中作为参数传进的参数当异步IO完成后会调用。
	第一个参数是和内部IO完成端口相关联的句柄。
	36将句柄和内部IO完成端口关联起来。
	*/
	ioobject = CreateThreadpoolIo(hFile,OverlappedCompletionRoutine,NULL,NULL);
	StartThreadpoolIo(ioobject);
	CreateThread(NULL,0,ThreadFunc,NULL,0,NULL);
	OVERLAPPED over;
	over.Offset = 0;
	over.OffsetHigh = 0;
	over.hEvent = NULL;
	WriteFile(hFile,t,sizeof(TCHAR)*4,NULL,&over);
	Sleep(10000);
}