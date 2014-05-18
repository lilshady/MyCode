#include <iostream>

struct BinaryTreeNode
{
    int  m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

BinaryTreeNode *ConstructCore(int *startPreorder,int *endPreorder,
	                          int *startInorder,int *endInorder
	                          )
{
	int rootValue = startPreorder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startInorder == *startPreorder)
		{
			return root;
		}
		else 
			throw std::exception("invalid input");
	}

	int *rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	
	if(rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("invalid input");

	int leftlength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftlength;

	if (leftlength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,startInorder,rootInorder-1);
	}

	if (leftlength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
	}

	return root;
}

BinaryTreeNode* Construct(int * preorder, int *inorder,int length)
{
	if (preorder == NULL || inorder == NULL || length < 0)
		return NULL;
	
	return ConstructCore(preorder,preorder + length - 1,inorder,inorder + length - 1); 
}
void PostOrderDisplay(BinaryTreeNode *root)
{
	if ( root != NULL)
	{
		PostOrderDisplay(root->m_pLeft);
		PostOrderDisplay(root->m_pRight);
		std::cout<<root->m_nValue<<std::endl;
	}
}
int main()
{
	int a[8] = {1,2,4,7,3,5,6,8};
	int b[8] = {4,7,2,1,5,3,8,6};
    BinaryTreeNode *root = Construct(a,b,8);

	PostOrderDisplay(root);

	system("pause");

    
}