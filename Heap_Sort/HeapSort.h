#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>


typedef int HPDataType;

void AdjustUp(HPDataType* a, int child);//���ϵ���

void AdjustDown(HPDataType* a, int size, int parent);//���µ���

void Swap(HPDataType* a, int child, int parent);//����

void HeapPop(HPDataType* hp, int size);//ɾ��/��ɾ��

void HeapSort(HPDataType* a, int size);//������

void CreatFileData(int n, int max);//���� n ����С������ max ���ļ�����

void PrintfTopK(int k);//TopK��