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
	Derived *p = &d;//pָ���������ֽ�,VS�н�ָ���麯�����ָ����ڶ������ǰ��
	int **p2 = *(int ***)p;//p2ָ���麯����
	int (*p3)() = (int(*)())*p2;//ȡ���麯����ĵ�һ������Ķ�����麯��get
	//std::cout<<*(int*)(*(int**)(*(int***)p))<<std::endl;
	//std::cout<<p->get()<<std::endl;
	//
	std::cout<<p3()<<std::endl;
	system("pause");
}