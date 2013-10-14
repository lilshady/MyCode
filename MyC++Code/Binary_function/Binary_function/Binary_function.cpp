#include <set>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
class MyCompare
{
public:
	bool operator()(const string& lhs,const string& rhs)
	{
		return lhs.length() < rhs.length();
	}
};
/*
**һ����������Լ������functor���ô�binary_function�м̳У������Լ���functor��Ҫ����������bind1st,bind2nd������ʱ
**�Լ������functor����Ҫ��binary_function�̳С�Myfunctor:public binary_function<��һ���������ͣ��ڶ����������ͣ�����ֵ����>
*/
int main()
{
	set<string,MyCompare> Myset;
	Myset.insert(string("123"));
	Myset.insert(string("1234"));
	Myset.insert(string("12345"));
	Myset.insert(string("123456"));
	Myset.insert(string("ab"));
	copy(Myset.begin(),Myset.end(),ostream_iterator<string>(cout,"\n"));
	system("pause");
	
}