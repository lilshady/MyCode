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
{   /*�ȴ�һ���̳߳�IO�������*/
	WaitForThreadpoolIoCallbacks(ioobject,false);
	std::cout<<"THE another thread is done successfully"<<std::endl;
	return 0;

}


int main()
{
	HANDLE hFile = CreateFile(TEXT("D:\\my.txt"),GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_FLAG_OVERLAPPED,NULL);
	
	TCHAR t[] = {'a','b','c','\0'};

	/*
	33�д���һ���̳߳ص�IO����������Ϊ���������Ĳ������첽IO��ɺ����á�
	��һ�������Ǻ��ڲ�IO��ɶ˿�������ľ����
	36��������ڲ�IO��ɶ˿ڹ���������
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