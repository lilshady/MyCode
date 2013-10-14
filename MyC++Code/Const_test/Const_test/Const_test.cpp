#include <iostream>

class Base
{
public:
	Base(int t):a(t)
	{
	
	}
	int& get()
	{   
		return const_cast<int&>(static_cast<const Base&>(*this).get());//调用const成员函数

	}
    const int& get() const
	{   

        return a;
	}
private:
	int a;
};

int main()
{
	Base base1(10);
	const Base base2(10);
	std::cout<<base1.get()<<std::endl<<base2.get()<<std::endl;
	base1.get() = 20;
	std::cout<<base1.get()<<std::endl;
	system("pause");
}