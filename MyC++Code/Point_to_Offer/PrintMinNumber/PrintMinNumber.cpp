#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::stringstream;
using std::transform;
using std::copy;
using std::ostream_iterator;
/*
接收一个由整形构成的向量，得到一个由这些整形拼接得到的最小的整数。
思路：对这些整数进行排序，排序规则是两个整数，谁在前面拼接得到的整数的较小
有趣的地方：1.用stringstream进行从int到string的转化。2.vector的reserve只改变capacity,不改变size.而resize两个都改变。
*/
string fromInt2String(int num)
{  
	string s;
	stringstream ss(s);

	ss << num;

	return ss.str();
}
bool MyCompare(const string &lhs, const string &rhs);

void GetMinNumber(const vector<int> &v)
{
	if (v.empty())
		{
			cout<<"invalid input";
			return;
	    }
	
	vector<string> temp;
	temp.resize(v.size());

	transform(v.begin(),v.end(),temp.begin(),fromInt2String);

	sort(temp.begin(),temp.end(),MyCompare);

	copy(temp.begin(),temp.end(),ostream_iterator<string>(cout,""));
}

bool MyCompare(const string &lhs, const string &rhs)
{
	string temp1 = lhs + rhs;
	string temp2 = rhs + lhs;

	return temp1 < temp2;
}

int main()
{
	vector<int> v;
	v.reserve(3);
	v.push_back(3);
	v.push_back(32);
	v.push_back(321);

	GetMinNumber(v);
	cout<<endl;

	system("pause");
}