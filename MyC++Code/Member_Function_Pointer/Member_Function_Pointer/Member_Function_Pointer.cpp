#include <iostream>

class Base
{
public:
	void get()
	{
		std::cout<<"this is easy"<<std::endl;
	}
	virtual void test()
	{
         std::cout<<"this is useless"<<std::endl;
	}
};

int main()
{   
	Base object;
	void (Base::*p)() = &Base::get;
	(object.*p)();
	void (Base::*p_v)() = &Base::test;
	size_t t = sizeof object;

	system("pause");
}