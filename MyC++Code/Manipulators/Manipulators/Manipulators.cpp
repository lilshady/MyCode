#include <ostream>
#include <iostream>
template <class charT,class traits>
std::basic_ostream<charT,traits>&
    outhello (std::basic_ostream<charT,traits>& strm)
{
    strm.write("hello",6);
	return strm;
}

/************************************************************************/
/* 操纵器（endl等等）的实现方式：将"<<"重载为：ostream& ostream::operator << (ostream (*op)(ostream&))
   op为函数指针，以ostream为函数。每次cout<<endl;都被转换成endl(cout).自定义操纵器的方法如本例所示
*/
/************************************************************************/
int main()
{
	std::cout<<"I think it it easy "<<outhello<<std::endl;
	system("pause");
}