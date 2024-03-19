#define _CRT_SECURE_NO_WARNINGS

#include"BT.h"

int main()
{
	BTDataType a[20] = { 'A','B','D','#','H','E','#','#','#','#','C','F','G','#','#','#','#' };
	BTDataType b[20] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	BTNode* root = BinaryTreeCreate(a, 0, 17);

	printf("TreeSize: %d\n", BinaryTreeSize(root));//8

	printf("LeafSize: %d\n", BinaryTreeLeafSize(root));//3

	printf("LeveKSize: %d\n", BinaryTreeLevelKSize(root, 3));//2

	printf("FindPosion: %p\n", BinaryTreeFind(root, 'M'));//NULL

	printf("Prev: ");
	BinaryTreePrevOrder(root);//AB#H#C##DEF##G###
	printf("\n");
	printf("In: ");
	BinaryTreeInOrder(root);//BHCAFEGD
	printf("\n");
	printf("Post: ");
	BinaryTreePostOrder(root);//CHBFGEDA
	printf("\n");
	
	return 0;
}