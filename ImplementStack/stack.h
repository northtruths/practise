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

void InitStack(SK* stcak);//初始化
void DestroyStack(SK* stack);//销毁
void PushStack(SK* stack, DataType x);//入栈
void PopStack(SK* stack);//出栈
bool EmptyStack(SK* stack);//是否为空
DataType TopStack(SK* stack);//尾元素
int SizeStack(SK* stack);//有效元素个数