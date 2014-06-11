#include <iostream>

char* StackString()
{
	char p[7]= {'1','2','3','4','5','6','\0'};
	return p;
}

void Override()
{
	char p[7]= {'a','b','c','d','e','f','\0'};
}

int main()
{
	char *p = StackString();

	*p = '8';
	//Override();

	system("pause");
}