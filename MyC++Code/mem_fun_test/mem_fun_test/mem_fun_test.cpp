#include <iostream>
#include <algorithm>
#include <vector>
class Test
{
public:
	Test(int t):sth(t)
	{

	}
	void get()
	{
	    std::cout<<sth<<std::endl;
	}
private:
	int sth;
};
typedef void (Test::*point)();
/*
**mem_fun_t基本上就是这么实现的
*/

class Call
{
public:
	Call(point t):pointer(t)
	{
	}
	void operator ()(Test t)
	{
		(t.*pointer)();
	}
private:
	point pointer;
};

Call mymem(point p)
{
	return Call(p);
}
int main()
{
    std::vector<Test> v1;
	v1.reserve(3);
	v1.push_back(Test(1));
	v1.push_back(Test(5));
	v1.push_back(Test(3));
	for_each(v1.begin(),v1.end(),mymem(&Test::get));
	system("pause");
}