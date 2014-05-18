#include <iostream>
using std::cout;
using std::endl;

void printsequence(int start,int end)
{
	for (int i = start; i<=end ; ++i)
	{
		cout<<i<<" ";
	}


	cout<<endl;
}
void FindContinuousSequence(int sum)
{
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
    int current_sum = small + big;

	while (small < middle)
	{
		if (current_sum == sum)
		{
			printsequence(small,big);
		}

		while (current_sum > sum)
		{
			current_sum -= small;
			++small;

			if (current_sum == sum)
			{  
				printsequence(small,big);
				break;
			}
		}

		++big;
		current_sum += big;
	}
}

int main()
{
	FindContinuousSequence(14);

	system("pause");
}

