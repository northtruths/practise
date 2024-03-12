#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HPDataType;

void AdjustUp(HPDataType* a, int child);//���ϵ���

void AdjustDown(HPDataType* a, int size, int parent);//���µ���

void Swap(HPDataType* a, int child, int parent);//����

void HeapPop(HPDataType* hp, int size);

void HeapSort(int* a, int n);