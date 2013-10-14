#define  DLLTEST_H extern "C" __declspec(dllexport)
#include "TestDll.h"
FILE *p;
int test()
{ 
	return 100;
}

BOOL WINAPI DllMain(HINSTANCE hInstDll,DWORD dwReason,PVOID fImpLoad )
{
	switch(dwReason)
	{
	    case DLL_PROCESS_ATTACH:
			
			    p = fopen("d:\\TEST.txt","w");
				fprintf(p,"this is loaded\n");
				break;
			
		case DLL_THREAD_ATTACH:
			
				fprintf(p,"a NEW thread is created\n");
				break;
			

		case DLL_THREAD_DETACH:
			
				fprintf(p,"a NEW thread is killed\n");
			    break;
			
		case DLL_PROCESS_DETACH:
			
				fprintf(p,"the dll is unloaded\n");
				fclose(p);
				break;
			
	}

	return TRUE;
}