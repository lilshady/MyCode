#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
	set<int,greater<int> > coll1;
	deque<int> coll2;

	for(int i = 0; i < 9; ++i)
		coll1.insert(i);
	copy(coll1.begin(),coll1.end(),ostream_iterator<int>(cout,"\n"));

	transform(coll1.begin(),coll1.end(),back_inserter(coll2),bind2nd(multiplies<int>(),10));
	cout<<"---------------------"<<endl;
	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout,"\n"));
	cout<<"---------------------"<<endl;
	replace_if(coll2.begin(),coll2.end(),bind2nd(equal_to<int>(),70),42);

	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout,"\n"));
	cout<<"---------------------"<<endl;
	coll2.erase(remove_if(coll2.begin(),coll2.end(),bind2nd(less<int>(),50)),coll2.end());

	copy(coll2.begin(),coll2.end(),ostream_iterator<int>(cout,"\n"));

	system("pause");
}