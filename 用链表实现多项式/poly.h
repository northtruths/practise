#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node //ÿ������ʽ
{
	int coef;//ϵ��
	int index;//ָ��
	struct node* next;
} node;

//��������ʽ����
//����Ϊ����ʽ�ĸ�����ָ��
node* ListCreat(int* n);

//����ʽ���򣨽�����ʽ������ÿ������ʽ��ָ����С��������
//����Ϊ����ʽ����
void ListSort(int n);

//����ʽ��ӣ����ص�һ������ʽ�����ͷ���
node* ListAdd(node* p1, node* p2);

//����ʽ�������ӡ����ʽ��
void ListPrint(node* p);




