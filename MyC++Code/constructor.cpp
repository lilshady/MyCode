#include <iostream>
#include <sstream>
class A
{
public:
	A()
	{std::cout<<"A default ctor"<<std::endl;}

};
class C
{
public:
	C()
	{std::cout<<"C default ctor"<<std::endl;}

};
class B:public C
{//自动扩充B定义的默认构造函数，先调用基类的，再调用成员的
public:
	B()
	{std::cout<<"B default ctor"<<std::endl;}
private:
	A a;
};

class D
{
  public:
  	D()
  {}
  typedef int mytype;
  int a = 5;

};
void display(int i)
{

	std::cout<<i<<std::endl;
}
int main()
{
	B b;
	std::stringstream mystringstream;
    mystringstream << "123";
    int i;
    mystringstream>>i;
    std::cout<<i<<std::endl;
    D d;
    std::cout<<d.a<<std::endl;
    D::mytype mm(10);

    display(mm);

}