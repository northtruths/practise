#define _CRT_SECURE_NO_WARNINGS

#include"BT.h"

BTNode* BinaryTreeCreate(BTDataType* a, int n, int size)
{
	if (n > 17 || a[n] == '#')
		return NULL;
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[n];
	root->_left = BinaryTreeCreate(a, n * 2 + 1, size);//左子树
	root->_right = BinaryTreeCreate(a, n * 2 + 2, size);//右子树
	return root;
}

void BinaryTreeDestory(BTNode** root)
{
	//后序释放
	if (!root)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	
	//子问题：个数等于根加左右子树
	//最小子问题：空树
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	//子问题：树的叶结点个数等于左右子树叶结点的和 
	//最小子问题：没有叶子，或者说根就是叶子,和为空树
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//子问题：第k层的节点个数等于左右子树的第k-1层节点个数和
	//最小子问题：为空; 层数为 1
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//子问题：找根然后找左右子树
	//最小子问题：为空，找到
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* rl = BinaryTreeFind(root->_left, x);
	if (rl)
		return rl;
	return BinaryTreeFind(root->_right, x);
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
	{
		printf("# ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}