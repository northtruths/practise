#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HPDataType;

void AdjustUp(HPDataType* a, int child);//向上调整

void AdjustDown(HPDataType* a, int size, int parent);//向下调整

void Swap(HPDataType* a, int child, int parent);//交换

void HeapPop(HPDataType* hp, int size);

void HeapSort(int* a, int n);