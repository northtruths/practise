#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"

//�ڵ�Ĵ���

SLTNode* NodeCreat(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	NewNode->x = x;
	NewNode->next = NULL;
	return NewNode;
}


//ͷ��/ɾ��β��/ɾ
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//������Ϊ�գ�����һ���ڵ�Ϊͷ�ڵ�
	if(*pphead == NULL)
	{
		*pphead = NodeCreat(x);
	}
	else//�ҵ�β�ڵ㣬����
	{
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
			ptail = ptail->next;
		//��ʱ ptail ����β�ڵ�
		ptail->next = NodeCreat(x);
	}
}
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	//������Ϊ�գ�����һ���ڵ�Ϊͷ�ڵ�
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
		printf("�����ǿյ�Ŷ��\n");
		return;
	}
	else//�ҵ�β�ڵ㣬ɾ��
	{
		SLTNode* ptail = *pphead;
		while (ptail->next->next != NULL)
			ptail = ptail->next;
		//��ʱ ptail ����β�ڵ����һ���ڵ�
		free(ptail->next->next);
		ptail->next->next = NULL;
	}
}
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		printf("�����ǿյ�Ŷ��\n");
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


//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur && pcur->x != x)
	{
		pcur = pcur->next;
	}
	//��ʱ��pucr Ҫô�ҵ��ˣ�Ҫô�Ѿ������������û�ҵ�
	if(pcur == NULL)
	{
		printf("����û��������ݣ�\n");
		return NULL;
	}	
	else 
	{
		printf("�� %d ���ˣ���ַ�ѷ���\n", x);
		return pcur;
	}
}


//ָ��λ��ǰ��������
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
	//��ʱ��Ҫô prev ��Ŀ�����һ���ڵ㣬Ҫô�Ѿ������������û�ҵ�
	if (prev == NULL)
	{
		printf("��λ���ǷǷ��ģ�\n");
		return;
	}
	SLTNode* new = NodeCreat(x);
	new->next = prev->next;
	prev->next = new;
}

//ɾ��pos�ڵ�
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
		printf("�����ڴ˽ڵ㣡\n");
		return;
	}
	SLTNode* del = prev->next;
	prev->next = prev->next->next;
	free(del);
	del = NULL;
}

//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* new = NodeCreat(x);
	new->next = pos->next;
	pos->next = new;
}
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		printf("��λ�ú���û�нڵ㣡\n");
		return;
	}
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//��������
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