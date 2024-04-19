#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


int main()
{
	SLTNode* newphead = NULL;
	//头插、尾插
	SLTPushBack(&newphead, 1);//1
	SLTPushFront(&newphead, 2);//21
	SLTPushBack(&newphead, 3);//213
	SLTPushFront(&newphead, 4);//4213
	//SLTPrintf(newphead);
	//查找
	SLTNode* pos = SLTFind(newphead, 10);
	//指定位置前插入
	SLTInsert(&newphead, pos, 5);//42513
	//指定位置后插入
	SLTInsertAfter(pos, 6);//425163
	//删除pos后的节点
	SLTEraseAfter(pos);//42513
	//删除pos
	SLTErase(&newphead, pos);//4253
	//
	SLTPrintf(newphead);

	return 0;
}