#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������(ֱ��ѡ������)
void SelectSort(int* a, int n);

// ������
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);