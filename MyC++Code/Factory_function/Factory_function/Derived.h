#include "Base.h"
class Derived:public Base
{
public:
	Derived(int p)
		{
			j = p;
		}
    virtual int getInt();
	
private:
	int j;
};