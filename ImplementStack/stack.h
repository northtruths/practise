#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int DataType;

typedef struct stack
{
	DataType* arr;
	int top;
	int sizenum;
}SK;

void InitStack(SK* stcak);//��ʼ��
void DestroyStack(SK* stack);//����
void PushStack(SK* stack, DataType x);//��ջ
void PopStack(SK* stack);//��ջ
bool EmptyStack(SK* stack);//�Ƿ�Ϊ��
DataType TopStack(SK* stack);//βԪ��
int SizeStack(SK* stack);//��ЧԪ�ظ���