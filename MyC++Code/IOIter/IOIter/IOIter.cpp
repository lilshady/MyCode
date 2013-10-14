// IOIter.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector <string> StringVector;
	
	copy(istream_iterator<string>(cin),istream_iterator<string>(),back_inserter(StringVector));

	sort(StringVector.begin(),StringVector.end());

	unique_copy(StringVector.begin(),StringVector.end(),ostream_iterator<string>(cout,"\n"));
	system("pause");

}

