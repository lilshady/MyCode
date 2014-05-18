#include <iostream>

void display(int array[],int length)
{
	for (int i = 0 ; i < length; ++i)
	{
		std::cout<<array[i]<<" "<<std::endl;
	}
}

void MergeSortArray(int a[],int b[],int a_length,int b_length,int a_size)
{
	bool condition_a = (a == NULL)||(a_length <=0 )||(a_size <=0);
	bool condition_b = (b == NULL)||(b_length <=0 );

	if (condition_a)
		std::cout<<"the first array is invalid"<<std::endl;
	else if (condition_b)
		return;
	else 
	{
		int a_num = a_length - 1;
		int b_num = b_length - 1;
		int index = a_size - 1;
		while (a_num >=0 && b_num >= 0)
		{
			if (a[a_num] > b[b_num])
			{
				a[index--] = a[a_num--];
			}
			else
			{
				a[index--] = b[b_num--];
			}
		}
		while (a_num >= 0)
		{
			return;
		}
		while (b_num >= 0)
		{
			a[index--] = b[b_num--];
		}
	}
}

int main()
{
	int a[15] = {18,19,20};
	int b[5] = {2,4,6,8,10};
	int size = 3;
	MergeSortArray(a,NULL,3,5,size);
	display(a,size);
	system("pause");
}

