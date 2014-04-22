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
����һ�������ι��ɵ��������õ�һ������Щ����ƴ�ӵõ�����С��������
˼·������Щ�������������������������������˭��ǰ��ƴ�ӵõ��������Ľ�С
��Ȥ�ĵط���1.��stringstream���д�int��string��ת����2.vector��reserveֻ�ı�capacity,���ı�size.��resize�������ı䡣
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