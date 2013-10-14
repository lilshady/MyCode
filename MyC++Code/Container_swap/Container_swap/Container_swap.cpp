#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	vector<int> v1(10,5);
	vector<int> v2(10,8);
    vector<int>::iterator iter1 = v1.begin()+5;
	cout<<"iter1 pre:"<<*iter1<<endl;
	
	vector<int>::iterator iter2 = v2.begin()+3;
	cout<<"iter2 pre:"<<*iter2<<endl;
	v1.swap(v2);
	/*
	**���������Ժ�iter1��Ȼָ��v1�� Ԫ�أ�iter2��Ȼָ��v2��Ԫ�ء�
	*/
	cout<<"iter1 post:"<<*iter1<<endl;
	cout<<"iter2 post:"<<*iter2<<endl;
	copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," "));
	system("pause");
}