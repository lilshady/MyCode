#include <boost/shared_ptr.hpp>
#include <iostream>
template <typename T>
class SthImp
{
public:
	SthImp():sth(T())
	{

	}
	SthImp(T t):sth(t)
	{

	}
	T get()
	{
		return sth;
	}
private:
	T sth;
};
template <typename T>
class Sth
{
public:
	Sth():p(new SthImp<T>)
	{
	
	}
	Sth(T t):p(new SthImp<T>(t))
	{

	}
	Sth(const Sth &rhs ):p(rhs.p)
	{

	};
	T get()
	{
		return p->get;
	}
private:
	std::tr1::shared_ptr<SthImp<T>> p;
};
int main()
{
	Sth<int> tmp1;
	Sth<int> tmp2(14);
	std::cout<<tmp1.get()<<std::endl;
	Sth<int> tmp3(tmp2);
    std::cout<<tmp3.get()<<std::endl;
	system("pause");

}