#include <iostream>
int path[10];
/*
**����˼·��������ǰ9�����Ӽ�Ϊ5����������ǰ8�����Ӽ���Ϊ-4�ͼӼ���Ϊ14֮��(������)�����Եõ�
**�ݹ�ʽ��sumfive(Array,9,5)= sumfive(Array,8,5-9) + sumfive(Array,8,5+9)
**path������¼����ġ�
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