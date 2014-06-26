#include <iostream>
#include <vector>
using namespace std;
int x;

int main()
{
	const vector<int> v(1,0);
	auto a = v[0];
	int b = 0;
	auto c = 0;
	auto d = c;
	decltype(c) e = x;
	decltype(e) f = e;
	auto index = a+b+c+d+e;
	cout<<x<<endl;
	cout<<index<<endl;
}