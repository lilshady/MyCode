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
**一般这种情况自己定义的functor不用从binary_function中继承，但当自己的functor需要和适配器：bind1st,bind2nd等联动时
**自己定义的functor就需要从binary_function继承。Myfunctor:public binary_function<第一个参数类型，第二个参数类型，返回值类型>
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