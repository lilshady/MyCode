#include <iostream>

class Base
{
public:
	Base()
	{
		a = 10;
	}
	virtual ~Base()
	{
		std::cout<<"Base Destructor"<<std::endl;
	}
	int a;
};

class Derived:public Base
{
public:
	Derived()
	{
	    b = 20;
	}
	virtual ~Derived()
	{
		std::cout<<"Derived Destructor"<<std::endl;
	}
	int b;
};

int main()
{   
	Base a;
	Derived b;
	std::cout<<sizeof a<<" "<<sizeof b<<std::endl;
	Base *p = new Derived[10];

	delete  p;

	system("pause");
}