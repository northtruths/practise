#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//实现顺序表的增删查改
//1.顺序表的创建与销毁
//2.增删查改


//顺序表的创建
typedef int DataType;
typedef struct SeqList//顺序表的格式及其属性
{
	DataType* arr;
	int vol;
	int size;
}SL;

//顺序表的初始化
void SLInit(SL* sl);
//销毁
void SLDelAll(SL* sl);
//扩容
void SLExpa(SL* sl);
//头插、尾插
void SLAddHead(SL* sl, DataType data);
void SLAddTail(SL* sl, DataType data);
//头删、尾删
void SLDelHead(SL* sl);
void SLDelTail(SL* sl);
//指定位置删除
void SLDelPoint(SL* sl, int po);
//查看数据
void SLCheck(SL* sl, int po);
//查看整个顺序表
void SLShow(SL* sl);
//指定位置修改
void SLRvise(SL* sl, DataType data, int po);