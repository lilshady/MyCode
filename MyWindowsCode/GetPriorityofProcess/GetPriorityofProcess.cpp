#include <Windows.h>
#include <iostream>

using std::endl;
using std::cout;

int main()
{  
	DWORD i ;
	i = GetPriorityClass(GetCurrentProcess());
	cout<<i<<endl;
	system("pause");
}