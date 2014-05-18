#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::for_each;
using std::vector;

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

void printchar(char i)
{
	cout<<i<<" ";
}

vector<char> path;
int GetAllCombinations(string s, int index , int num)
{   

	if(num == 0)
	{
		//for_each(s.begin()+index,s.end(),printchar);
		for_each(path.begin(),path.end(),printchar);
		cout<<endl;
		return 1;
	}

    if (index >= s.length())
    {
		return 0;
	}
	  
	
	
    path.push_back(s[index]);
    int i = GetAllCombinations(s,index+1,num-1);
    path.pop_back();
    int j = GetAllCombinations(s,index+1,num);

    return i+j;

}
int main()
{   
	string s = "abcd";
	GetAllPermutation("abcdefgh",0);
	cout<<"the combinations are"<<endl;
    for (int i = 1; i <= s.length(); ++i)
    {  
		
		cout<< GetAllCombinations(s,0,i)<<endl;
		
    }

	system("pause");
}