#include <iostream>
using namespace std;
/*final标记的虚函数无法被override,所以这个代码会编译错误。
override标记的函数必须重写了其基类的函数，如果没有重写，会报错
用下面final标记的类无法被继承*/
class  Base final
{
public:

	virtual void display() 
	{
		cout<<"from base"<<endl;
	}
	virtual void display2() final
	{
		cout<<"from baes2"<<endl;
	}
};

class Dev: public Base
{
public:

    virtual void display() override
    {
    	cout<<"from dev"<<endl;
    }

	virtual void display2()
	{
		cout<<"from dev2"<<endl;
	}

};

int main(int argc, char const *argv[])
{
	Base *p = new Dev();
	p->display(); 
	return 0;
}

