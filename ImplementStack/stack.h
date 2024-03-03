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

void InitStack(SK* stcak);
void DestroyStack(SK* stack);
void PushStack(SK* stack, DataType x);
void PopStack(SK* stack);
bool EmptyStack(SK* stack);
DataType TopStack(SK* stack);
int SizeStack(SK* stack);