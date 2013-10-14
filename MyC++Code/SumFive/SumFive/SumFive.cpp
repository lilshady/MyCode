#include <iostream>
int path[10];
/*
**基本思路是这样：前9个数加减为5的总数等于前8个数加减成为-4和加减成为14之和(你想想)。可以得到
**递归式：sumfive(Array,9,5)= sumfive(Array,8,5-9) + sumfive(Array,8,5+9)
**path用来记录结果的。
*/
int sumfive(int array[],int index,int sum)
{   

    if (index == 0)
	{   
	    if (sum == array[index])
		{    
			path[index] = array[index];
			for (int i = 0; i < 10;++i)
			{
				std::cout<<std::showpos<<path[i];
			}
			std::cout<<std::endl;
			return 1;
		}
		else 
			return 0;
	}
	path[index] = -array[index];
	int count1 = sumfive(array,index-1,sum+array[index]);
	path[index] = array[index];
	int count2 = sumfive(array,index-1,sum-array[index]);
	return count1 + count2;
}

int main()
{
	int Array[10] = {0,1,2,3,4,5,6,7,8,9};
	std::cout<<"the total count :"<<sumfive(Array,9,5)<<std::endl;
	system("pause");

}