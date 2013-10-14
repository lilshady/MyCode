#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

class Person
{
public:
	Person(const string &sname):name(sname)
	{
	}
	void print() const
	{
		cout<<name<<endl;
	}
	void print_prefix( string prefix) const
	{
		cout<<prefix<<":"<<name<<endl;
	}
private:
	string name;
};

int main()
{   
	/*
	** mem_fum_ref���������д�ŵ��Ƕ���mem_fun���������д�ŵ��Ƕ����ָ��
	** �ҵ��õĳ�Ա����������const
	*/
	vector<Person> Array1;
	Array1.push_back(Person("Lu"));
	Array1.push_back(Person("Shen"));

	for_each(Array1.begin(),Array1.end(),mem_fun_ref(&Person::print));
	string s = "the name is";
	for_each(Array1.begin(),Array1.end(),bind2nd(mem_fun_ref(&Person::print_prefix),"the name is"));
	/*
	**�����������д������print_prefix�Ĳ���������const string &.������string s = ...������s�����ַ�������
	**��д������print_prefix�Ĳ���������const string &.
	*/

	vector<Person*> Array2;
	Person *p1 = new Person("Lu");
	Person *p2 = new Person("Shen");
	Array2.push_back(p1);
	Array2.push_back(p2);

	for_each(Array2.begin(),Array2.end(),mem_fun(&Person::print));
	for_each(Array2.begin(),Array2.end(),bind2nd(mem_fun(&Person::print_prefix),"the name is"));
	
	system("pause");
}