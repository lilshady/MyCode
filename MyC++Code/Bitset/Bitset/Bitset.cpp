#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main()
{
	bitset<32> bit1(1234567);
	cout<<"origin: "<<bit1<<endl;
	cout<<"the string: "<<bit1.to_string()<<endl;

	bitset<32> bit2(string("00001010100101"));
	cout<<"origin: "<<bit2<<endl;
	cout<<"the numeric: "<<bit2.to_ulong()<<endl;
	system("pause");
}