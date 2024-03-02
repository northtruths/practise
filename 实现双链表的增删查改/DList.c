#define _CRT_SECURE_NO_WARNINGS

#include"DList.h"

//创建节点
LTNode* NodeCreat(LTNode** prev)
{
	if (*prev == NULL)
	{
		*prev = (LTNode*)malloc(sizeof(LTNode));
		(*prev)->next = *prev;
		(*prev)->prev = *prev;
		(*prev)->data = 0;
		return *prev;
	}
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = 0;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//初始化
void LTInit(LTNode** pphead)
{
	if(*pphead == NULL)
	{
		*pphead = NodeCreat(pphead);
		return;
	}
	else
	{
		(*pphead)->data = 0;
		(*pphead)->next = *pphead;
		(*pphead)->prev = *pphead;
	}
}

//打印
void LTPrint(LTNode* phead)
{
	if (phead == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	LTNode* pcur = phead;
	do
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	} while (pcur != phead);
	printf("\n");
}

//销毁
void LTDestroy(LTNode* phead)
{
	LTNode* next = phead;
	LTNode* del = phead;
	while (del)
	{
		next = next->next;
		free(del);
		del = NULL;
		del = next;
	}
}

//检查链表是否为空
bool LTEmpty(LTNode* phead)
{
	if (phead == NULL)
		return 1;
	else
		return 0;
}

//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	LTNode* newnode = NodeCreat(&phead);
	newnode->data = x;
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//尾删
void LTPopBack(LTNode* phead)
{
	LTNode* del = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(del);
	del = NULL;
}

//头插，因为如果插头节点的前面，就和尾插一样了，所以插头节点后面
void LTPushFront(LTNode* phead, LTDataType x)
{
	LTNode* newnode = NodeCreat(&phead);
	newnode->data = x;
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next = newnode;
	newnode->next->prev = newnode;
}

//头删
void LTPopFront(LTNode* phead)
{
	LTNode* del = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;
	free(del);
	del = NULL;

}

//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x)
{
	LTNode* newnode = NodeCreat(&pos);
	newnode->data = x;
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//指定位置删除数据
void LTErase(LTNode* pos)
{
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	if (phead == NULL)
	{
		printf("链表为空！\n");
		return;
	}
	LTNode* pcur = phead;
	do
	{
		pcur = pcur->next;
	} while (pcur->data != x && pcur != phead);
	if (pcur->data == x)
	{
		printf("找到了！\n");
		printf("数据为：%d\n", pcur->data);
		return pcur;
	}
	else
		printf("此数据不存在！\n");
}