#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

//节点的创建

SLTNode* NodeCreat(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	NewNode->x = x;
	NewNode->next = NULL;
	return NewNode;
}


//头插/删、尾插/删
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//若链表为空，创造一个节点为头节点
	if(*pphead == NULL)
	{
		*pphead = NodeCreat(x);
	}
	else//找到尾节点，插入
	{
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
			ptail = ptail->next;
		//此时 ptail 就是尾节点
		ptail->next = NodeCreat(x);
	}
}
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//若链表为空，创造一个节点为头节点
	if (*pphead == NULL)
	{
		*pphead = NodeCreat(x);
	}
	else
	{
		SLTNode* temp = NodeCreat(x);
		temp->next = *pphead;
		*pphead = temp;
	}
}
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		printf("链表是空的哦！\n");
		return;
	}
	else//找到尾节点，删除
	{
		SLTNode* ptail = *pphead;
		while (ptail->next->next != NULL)
			ptail = ptail->next;
		//此时 ptail 就是尾节点的上一个节点
		free(ptail->next->next);
		ptail->next->next = NULL;
	}
}
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		printf("链表是空的哦！\n");
		return;
	}
	else
	{
		SLTNode* del = *pphead;
		*pphead = (**pphead).next;
		free(del);
		del = NULL;
	}
}


//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur && pcur->x != x)
	{
		pcur = pcur->next;
	}
	//此时，pucr 要么找到了，要么已经遍历完链表而没找到
	if(pcur == NULL)
	{
		printf("根本没有这个数据！\n");
		return NULL;
	}	
	else 
	{
		printf("找 %d 到了！地址已返回\n", x);
		return pcur;
	}
}


//指定位置前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);
	SLTNode* prev = *pphead;
	while (prev && prev->next != pos)
	{
		prev = prev->next;
	}
	//此时，要么 prev 是目标的上一个节点，要么已经遍历完链表而没找到
	if (prev == NULL)
	{
		printf("此位置是非法的！\n");
		return;
	}
	SLTNode* new = NodeCreat(x);
	new->next = prev->next;
	prev->next = new;
}

//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);
	SLTNode* prev = *pphead;
	while (prev && prev->next != pos)
	{
		prev = prev->next;
	}
	if (prev == NULL)
	{
		printf("不存在此节点！\n");
		return;
	}
	SLTNode* del = prev->next;
	prev->next = prev->next->next;
	free(del);
	del = NULL;
}

//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* new = NodeCreat(x);
	new->next = pos->next;
	pos->next = new;
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		printf("此位置后面没有节点！\n");
		return;
	}
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	SLTNode* del = *pphead;
	SLTNode* next = del;
	while (del)
	{
		next = next->next;
		free(del);
		del = next;
	}
}

void SLTPrintf(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->x);
		pcur = pcur->next;
	}
	printf("\n");
}