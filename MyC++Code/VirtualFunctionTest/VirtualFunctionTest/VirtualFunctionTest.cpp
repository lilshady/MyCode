#include <iostream>

class Base
{
public:
	virtual int get()
	{
		return 10;
	}
};

class Derived:public Base
{
public:
	virtual int get()
	{
		return 5;
	}
};

int main()
{
	Derived d;
	Derived *p = &d;//p指向对象的首字节,VS中将指向虚函数表的指针放在对象的最前面
	int **p2 = *(int ***)p;//p2指向虚函数表
	int (*p3)() = (int(*)())*p2;//取出虚函数表的第一项，即上文定义的虚函数get
	//std::cout<<*(int*)(*(int**)(*(int***)p))<<std::endl;
	//std::cout<<p->get()<<std::endl;
	//
	std::cout<<p3()<<std::endl;
	system("pause");
}