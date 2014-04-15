#include <iostream>
#include <functional>

int add(int x, int y)
{
	return x + y;
}

class Myadd
{
	public:
		Myadd(int x):a(x)
	    {

	    }

	    int operator()(int b,int c)
	    {
	    	return a + b + c;
	    }
	    void display(int x)
	    {
	    	std::cout<<x<<"..........."<<a<<"~~~~~~~~~~"<<std::endl;
	    }
	private:
		int a;

};
int main(int argc, char const *argv[])
{   

	auto lam = [](int a,int b)->int{return a + b;};
	std::function<int(int,int)> f1 = add;
    std::function<int(int,int)> f2 = Myadd(2);
    std::function<int(int,int)> f3 = lam;
    std::function<void(Myadd,int)> f4 = &Myadd::display;

	std::cout<<f1(2,3)<<std::endl;
    std::cout<<f2(2,4)<<std::endl;
    std::cout<<f3(6,5)<<std::endl;
    f4(Myadd(2),1000);
	return 0;
}