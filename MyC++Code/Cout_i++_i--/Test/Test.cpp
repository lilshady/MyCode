#include <iostream>

int main()
{
	int i = 0;
	/*
	**this is is semantically equivalent to

operator<<(operator<<(cout, i++),   i--);
           <------arg1--------->, <-arg2->

	*/
	std::cout<<i++<<" "<<i--<<std::endl;
	system("pause");
}