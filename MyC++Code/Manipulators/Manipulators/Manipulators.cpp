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
/* ��������endl�ȵȣ���ʵ�ַ�ʽ����"<<"����Ϊ��ostream& ostream::operator << (ostream (*op)(ostream&))
   opΪ����ָ�룬��ostreamΪ������ÿ��cout<<endl;����ת����endl(cout).�Զ���������ķ����籾����ʾ
*/
/************************************************************************/
int main()
{
	std::cout<<"I think it it easy "<<outhello<<std::endl;
	system("pause");
}