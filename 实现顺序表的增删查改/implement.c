#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

//��ʼ��
void SLInit(SL* sl)
{
	sl->arr = NULL;
	sl->vol = 0;
	sl->size = 0;
}

//����
void SLDelAll(SL* sl)
{
	free(sl->arr);
	sl->arr = NULL;
	sl->vol = 0;
	sl->size = 0;
}

//����
void SLExpa(SL* sl)
{
	int rea = 0;
	if (sl->vol == 0)
		rea = 4;
	else
		rea *= 2;
	sl->arr = (DataType*)realloc(sl->arr, sizeof(DataType) * rea);
	sl->vol = rea;
}

//ͷ��\β��
void SLAddHead(SL* sl, DataType data)
{
	if (sl->size == sl->vol)
		SLExpa(sl);
	memmove(sl->arr + 1, sl->arr, sl->size * sizeof(DataType));
	sl->arr[0] = data;
	sl->size++;
}
void SLAddTail(SL* sl, DataType data)
{
	if (sl->size == sl->vol)
		SLExpa(sl);
	sl->arr[sl->size] = data;
	sl->size++;
}
//ͷɾ\βɾ
void SLDelHead(SL* sl)
{
	if (sl->size == 0)
	{
		printf("û�ж�������ɾ�ˣ�");
		return;
	}
	memmove(sl->arr, sl->arr + 1, (sl->size - 1) * sizeof(DataType));
	sl->size--;
}
void SLDelTail(SL* sl)
{
	if (sl->size == 0)
	{
		printf("û�ж�������ɾ�ˣ�");
		return;
	}
	sl->size--;
}

//ָ��λ��ɾ��
void SLDelPoint(SL* sl, int po)
{
	if (po < 0 || po >= sl->size)
	{
		printf("��������ȷλ�ã�");
		return;
	}
	if (sl->size == 0)
	{
		printf("û�ж�������ɾ�ˣ�");
		return;
	}
	if (po == sl->size - 1)
	{
		sl->size--;
		return;
	}
	memmove(sl->arr + po, sl->arr + po + 1, (sl->size - (po + 1)) * sizeof(DataType));
	sl->size--;
}

//�鿴����
void SLCheck(SL* sl, int po)
{
	if (po < 0 || po >= sl->size)
	{
		printf("��������ȷλ�ã�");
		return;
	}
	printf("%d\n", sl->arr[po]);
}

void SLShow(SL* sl)
{
	for (int i = 0; i < sl->size; ++i)
	{
		printf("%d", sl->arr[i]);
	}
	printf("\n");
}
//�޸�
void SLRvise(SL* sl,int po ,DataType data)
{
	if (po < 0 || po >= sl->size)
	{
		printf("��������ȷλ�ã�");
		return;
	}
	sl->arr[po] = data;
}