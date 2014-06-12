#include <iostream>
#include <memory>
void process(std::shared_ptr<int> x)
{   
   std::cout<<x.use_count()<<std::endl;
   std::cout<<"int this function"<<std::endl;
}

class A
{
	public:
		A()
		{std::cout<<"from default"<<std::endl;}
		~A()
		{std::cout<<"from dector"<<std::endl;}
};

void test(A a)
{std::cout<<"int this functiontest"<<std::endl;}


int main()
{
    auto lamda = [](int*){std::cout<<"from the lamda"<<std::endl;};
	//std::shared_ptr<int> q(new int(42),lamda);
	process(std::shared_ptr<int>(new int(42),lamda));

	test(A());
}