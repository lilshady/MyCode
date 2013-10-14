#include <iostream>

class Base
{
public:
	virtual int get()=0;
	int a;
};

class Derived :public Base
{
	virtual int get()
	{
	    return 10;
	}
public:
	int b;
};

int main()
{    
	Derived o;
	o.a = 10;
	o.b = 11;
	/*
	**int Derived::*p_a :����һ��ָ��Derived���ݳ�Ա��ָ�룬���ݳ�Ա����ΪInt
	*/
	int Derived::*p_a = &Derived::a;
	int Derived::*p_b = &Derived::b;
	std::cout<<o.*p_a<<std::endl;
	system("pause");
}