#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ʵ��˳������ɾ���
//1.˳���Ĵ���������
//2.��ɾ���


//˳���Ĵ���
typedef int DataType;
typedef struct SeqList//˳���ĸ�ʽ��������
{
	DataType* arr;
	int vol;
	int size;
}SL;

//˳���ĳ�ʼ��
void SLInit(SL* sl);
//����
void SLDelAll(SL* sl);
//����
void SLExpa(SL* sl);
//ͷ�塢β��
void SLAddHead(SL* sl, DataType data);
void SLAddTail(SL* sl, DataType data);
//ͷɾ��βɾ
void SLDelHead(SL* sl);
void SLDelTail(SL* sl);
//ָ��λ��ɾ��
void SLDelPoint(SL* sl, int po);
//�鿴����
void SLCheck(SL* sl, int po);
//�鿴����˳���
void SLShow(SL* sl);
//ָ��λ���޸�
void SLRvise(SL* sl, DataType data, int po);