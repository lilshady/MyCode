#include <iostream>
#include <vector>
template<typename T>
void myoutput(const T& t )
{
	std::cout<<"this is template"<<std::endl;
}

void myoutput(const int& t)
{
	std::cout<<"this is specialized"<<std::endl;
}

int main()
{   
	std::vector<int> List;
	double i = 0.0;
	myoutput(i);
	int t = 0;
	myoutput(t);
	myoutput(List);
	system("pause");
}