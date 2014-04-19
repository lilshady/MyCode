#include <string>
#include <iostream>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;

void GetAllPermutation(string s, int index)
{   
	int length = s.length();
	if (length == 0)
		cout<<"a empty string"<<endl;

	if (index == length - 1)
		 cout<<s<<endl;
	for (int i = index; i<length; ++i)
	{
		std::swap(s[index],s[i]);

		GetAllPermutation(s,index + 1);

		std::swap(s[index],s[i]);
	}
}

int main()
{
	GetAllPermutation("abcdefgh",0);

	system("pause");
}