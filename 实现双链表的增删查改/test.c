#define _CRT_SECURE_NO_WARNINGS

#include"DList.h"

LTNode* test1;

int main()
{
	//��ʼ��
	LTInit(&test1);//0
	//ͷ��β��
	LTPushBack(test1, 1);//01
	LTPushFront(test1, 2);//021
	LTPushBack(test1, 3);//0213
	LTPushFront(test1, 4);//04213
	LTPrint(test1);
	//ͷβɾ
	LTPopFront(test1);//0213
	LTPopBack(test1);//021
	LTPrint(test1);
	//ָ����\ɾ
	LTNode* dest = LTFind(test1, 2);
	LTInsert(dest, 6);//0261
	LTErase(dest);//061
	LTPrint(test1);//061
	return 0;
}