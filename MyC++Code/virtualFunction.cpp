#include <iostream>
using namespace std;

class A
{
public:

	virtual void display()
	{
		cout<<"From Base"<<endl;
	}

};

class B :public A
{
  public:
  	void display(int)
  	{
  		cout<<"From Derived"<<endl;

  	}

};
/*
当派生类和基类的虚函数形参不一致时，通过指向基类的指针只能调用
基类中的版本，不支持派生类的接口。
也就是说，只有形参完全一致时才会改写虚函数表，不一致时，只是当作两个不同的函数
*/
int main(int argc, char const *argv[])
{
	A a;
	B b;
	A *p = &b;
	p->display();
	return 0;
}