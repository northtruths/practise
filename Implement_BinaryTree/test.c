#define _CRT_SECURE_NO_WARNINGS

#include"BT.h"

int main()
{
	BTDataType a[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	BTDataType b[] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, sizeof(a) / sizeof(a[0]), &i);
	//BTNode* root = BinaryTreeCreate(b, sizeof(b) / sizeof(b[0]), &i);
	printf("TreeSize: %d\n", BinaryTreeSize(root));//8

	printf("LeafSize: %d\n", BinaryTreeLeafSize(root));//4

	printf("LeveKSize: %d\n", BinaryTreeLevelKSize(root, 3));//4

	printf("FindPosion: %p\n", BinaryTreeFind(root, 'M'));//NULL

	printf("Prev: ");
	BinaryTreePrevOrder(root);//ABD##E#H##CF##G##
	printf("\n");
	printf("In: ");
	BinaryTreeInOrder(root);//DBEHAFCG
	printf("\n");
	printf("Post: ");
	BinaryTreePostOrder(root);//DHEBFGCA
	printf("\n");
	printf("Level: ");
	BinaryTreeLevelOrder(root);//ABCDEFGH
	printf("\n");

	if (BinaryTreeComplete(root))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");
	return 0;
}