#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>


typedef int HPDataType;

void AdjustUp(HPDataType* a, int child);//向上调整

void AdjustDown(HPDataType* a, int size, int parent);//向下调整

void Swap(HPDataType* a, int child, int parent);//交换

void HeapPop(HPDataType* hp, int size);//删除/假删除

void HeapSort(HPDataType* a, int size);//堆排序

void CreatFileData(int n, int max);//创建 n 个大小不大于 max 的文件数据

void PrintfTopK(int k);//TopK！