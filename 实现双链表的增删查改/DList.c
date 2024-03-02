#define _CRT_SECURE_NO_WARNINGS

#include"DList.h"

//�����ڵ�
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

//��ʼ��
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

//��ӡ
void LTPrint(LTNode* phead)
{
	if (phead == NULL)
	{
		printf("����Ϊ�գ�\n");
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

//����
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

//��������Ƿ�Ϊ��
bool LTEmpty(LTNode* phead)
{
	if (phead == NULL)
		return 1;
	else
		return 0;
}

//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	LTNode* newnode = NodeCreat(&phead);
	newnode->data = x;
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;
}

//βɾ
void LTPopBack(LTNode* phead)
{
	LTNode* del = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(del);
	del = NULL;
}

//ͷ�壬��Ϊ�����ͷ�ڵ��ǰ�棬�ͺ�β��һ���ˣ����Բ�ͷ�ڵ����
void LTPushFront(LTNode* phead, LTDataType x)
{
	LTNode* newnode = NodeCreat(&phead);
	newnode->data = x;
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next = newnode;
	newnode->next->prev = newnode;
}

//ͷɾ
void LTPopFront(LTNode* phead)
{
	LTNode* del = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;
	free(del);
	del = NULL;

}

//��posλ��֮���������
void LTInsert(LTNode* pos, LTDataType x)
{
	LTNode* newnode = NodeCreat(&pos);
	newnode->data = x;
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

//ָ��λ��ɾ������
void LTErase(LTNode* pos)
{
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

//����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	if (phead == NULL)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	LTNode* pcur = phead;
	do
	{
		pcur = pcur->next;
	} while (pcur->data != x && pcur != phead);
	if (pcur->data == x)
	{
		printf("�ҵ��ˣ�\n");
		printf("����Ϊ��%d\n", pcur->data);
		return pcur;
	}
	else
		printf("�����ݲ����ڣ�\n");
}