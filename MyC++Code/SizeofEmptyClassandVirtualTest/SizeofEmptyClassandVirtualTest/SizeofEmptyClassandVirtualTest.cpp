#include <iostream>

class Base
{
};

class Derived1:public virtual Base
{
};

class Derived2:public virtual Base
{
};

class Last:public Derived1,public Derived2
{
};

int main()
{
	 Base ob1;
	 Derived1 ob2;
	 Derived2 ob3;
	 Last ob4;
	 std::cout<<"the size of Base is"<<sizeof(ob1)<<std::endl<<"the size of Derived1 is "<<sizeof(ob2)<<std::endl;
	 std::cout<<"the size of Derived2 is"<<sizeof(ob3)<<std::endl<<"the size of Last is "<<sizeof(ob4)<<std::endl;
	 system("pause");
	 /*
	 **the output is 1,4,4,8
	 */

}