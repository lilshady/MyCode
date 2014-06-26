#include <iostream>
#include <string>
#include <bitset>

class Test
{
   
  public:
  	Test() 
  	{std::cout<<"from default ctor"<<std::endl;}

  	Test(const Test& )
  	{std::cout<<"from copy ctor"<<std::endl;}

  	Test(Test &&rhs)
  	{std::cout<<"from move ctor"<<std::endl;}

};

Test Foo()
{
    return Test();

}

int main()
{
    Test a;

    Test b(a);

    Test c(Foo());
     
    Test d(std::move(Foo()));

    std::string s("012345");
    std::cout<<s[0]<<std::endl;

    std::bitset<6> bits("111000");
    std::cout<<bits[5]<<std::endl;

}