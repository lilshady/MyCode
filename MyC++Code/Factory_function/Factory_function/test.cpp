#include "Base.h"
#include <iostream>

int main()
{
	Base* p = Base::create(5);
	std::cout<<p->getInt()<<std::endl;
	system("pause");
}