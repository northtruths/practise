#define _CRT_SECURE_NO_WARNINGS

#include"BT.h"

BTNode* BinaryTreeCreate(BTDataType* a, int n, int size)
{
	if (n > 17 || a[n] == '#')
		return NULL;
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[n];
	root->_left = BinaryTreeCreate(a, n * 2 + 1, size);//������
	root->_right = BinaryTreeCreate(a, n * 2 + 2, size);//������
	return root;
}

void BinaryTreeDestory(BTNode** root)
{
	//�����ͷ�
	if (!root)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	
	//�����⣺�������ڸ�����������
	//��С�����⣺����
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	//�����⣺����Ҷ������������������Ҷ���ĺ� 
	//��С�����⣺û��Ҷ�ӣ�����˵������Ҷ��,��Ϊ����
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//�����⣺��k��Ľڵ�����������������ĵ�k-1��ڵ������
	//��С�����⣺Ϊ��; ����Ϊ 1
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//�����⣺�Ҹ�Ȼ������������
	//��С�����⣺Ϊ�գ��ҵ�
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