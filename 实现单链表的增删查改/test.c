#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


int main()
{
	SLTNode* newphead = NULL;
	//ͷ�塢β��
	SLTPushBack(&newphead, 1);//1
	SLTPushFront(&newphead, 2);//21
	SLTPushBack(&newphead, 3);//213
	SLTPushFront(&newphead, 4);//4213
	//SLTPrintf(newphead);
	//����
	SLTNode* pos = SLTFind(newphead, 10);
	//ָ��λ��ǰ����
	SLTInsert(&newphead, pos, 5);//42513
	//ָ��λ�ú����
	SLTInsertAfter(pos, 6);//425163
	//ɾ��pos��Ľڵ�
	SLTEraseAfter(pos);//42513
	//ɾ��pos
	SLTErase(&newphead, pos);//4253
	//
	SLTPrintf(newphead);

	return 0;
}