#include <iostream>

class Base
{
public:
	virtual int get()
	{
		return 10;
	}
};

class Derived:public Base
{
public:
	virtual int get()
	{
		return 5;
	}
};

int main()
{
	Derived d;
	Derived *p = &d;//pÖ¸Ïò¶ÔÏóµÄÊ××Ö½Ú,VSÖÐ½«Ö¸ÏòÐéº¯Êý±íµÄÖ¸Õë·ÅÔÚ¶ÔÏóµÄ×îÇ°Ãæ
	int **p2 = *(int ***)p;//p2Ö¸ÏòÐéº¯Êý±í
	int (*p3)() = (int(*)())*p2;//È¡³öÐéº¯Êý±íµÄµÚÒ»Ïî£¬¼´ÉÏÎÄ¶¨ÒåµÄÐéº¯Êýget
	//std::cout<<*(int*)(*(int**)(*(int***)p))<<std::endl;
	//std::cout<<p->get()<<std::endl;
	//
	std::cout<<p3()<<std::endl;
	system("pause");
}