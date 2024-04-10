#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node //每个多项式
{
	int coef;//系数
	int index;//指数
	struct node* next;
} node;

//创建多项式链表
//参数为多项式的个数的指针
node* ListCreat(int* n);

//多项式排序（将多项式链表中每个多项式按指数从小到大排序）
//参数为多项式个数
void ListSort(int n);

//多项式相加，返回第一个多项式链表的头结点
node* ListAdd(node* p1, node* p2);

//多项式输出（打印多项式）
void ListPrint(node* p);




