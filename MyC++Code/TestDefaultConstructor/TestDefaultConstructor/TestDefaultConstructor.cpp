#include <iostream>

class Base
{
  public:
	  Base()
	  {
		  std::cout<<"from Base"<<std::endl;
	  }

};

class Derived
{
public:
	Derived()
	{
		std::cout<<"from Derived"<<std::endl;
	}
private:

	Base object;
};

int main()
{
	Derived de;
	/*output the "from base\n from derived\n(compiler will insert the base default constructor into derived's)
	**if the Derived :public Base
	**the output will be "from base\n from base\n from derived\n"
	*/
	system("pause");
}