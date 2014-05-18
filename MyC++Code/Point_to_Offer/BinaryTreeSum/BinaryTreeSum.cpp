#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::make_pair;

struct BinaryNode
{
	int value;
	BinaryNode *left;
	BinaryNode *right;
};
void print_path(pair<string,int> pathnode)
{
	cout<<pathnode.first<<"->"<<pathnode.second<<endl;
}

string resources[3] ={"","go left","go right"}; 
void FindPathSumtoN(BinaryNode *root,int n,vector<pair<string,int>> &path,int direction)
{   
	if (root == NULL)
		cout<<"a empty tree"<<endl;
	
	path.push_back(make_pair(resources[direction],root->value));

	if (root ->value == n && root ->left == NULL & root ->right == NULL)
	{
		std::for_each(path.begin(),path.end(),print_path);
		cout<<"---------------------------"<<endl;
	}

	if (root ->left)
	{  
        FindPathSumtoN(root->left,n-(root->value),path,1);
	}

	if (root ->right)
	{  
		FindPathSumtoN(root->right,n-(root->value),path,2);
	}
	
	path.pop_back();

}

int main()
{
	BinaryNode *root = new BinaryNode;
	root -> value = 10;

	BinaryNode * temp1 = new BinaryNode;
	temp1 ->value = 5;

	BinaryNode * temp2 = new BinaryNode;
	temp2 ->value = 12;
	temp2->left = NULL;
	temp2 ->right = NULL;

	BinaryNode * temp3 = new BinaryNode;
	temp3 ->value = 4;
	temp3->left = NULL;
	temp3 ->right = NULL;

	BinaryNode * temp4 = new BinaryNode;
	temp4 ->value = 7;
	temp4->left = NULL;
	temp4 ->right = NULL;

	root -> left = temp1;
	root -> right = temp2;
	temp1 -> left = temp3;
	temp1 -> right = temp4;

	vector<pair<string,int>> path;
	FindPathSumtoN(root,22,path,0);

	system("pause");
}