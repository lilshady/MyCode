#include <functional>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template <class T1,class T2>
class fopow:public binary_function<T1,T2,T1>
{
public:
	T1 operator() (T1 base,T2 expo) const
	{
	    return pow(base,expo);
	}
};

int main()
{
	vector<int> coll;

	for (int i = 0; i < 10; ++i)
		coll.push_back(i);
	
	transform(coll.begin(),coll.end(),ostream_iterator<int>(cout,"\n"),bind1st(fopow<double,int>(),3));
	cout<<endl;
	transform(coll.begin(),coll.end(),ostream_iterator<int>(cout,"\n"),bind2nd(fopow<double,int>(),3));
	cout<<endl;
	system("pause");
}