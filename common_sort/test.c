#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"

void TestOP()
{
	srand((size_t)time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);


	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("BubbleSort:%d\n", end7 - begin7);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);


	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

void Printf(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSortTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0};
	Printf(a, sizeof(a) / sizeof(a[0]));
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	Printf(a, sizeof(a) / sizeof(a[0]));
}

void ShellSortTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0 };
	Printf(a, sizeof(a) / sizeof(a[0]));
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	Printf(a, sizeof(a) / sizeof(a[0]));
}

void SelectSortTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0 };
	Printf(a, sizeof(a) / sizeof(a[0]));
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	Printf(a, sizeof(a) / sizeof(a[0]));
}

void HeapSortTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0 };
	Printf(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	Printf(a, sizeof(a) / sizeof(a[0]));
}

void BubbleSortTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0 };
	Printf(a, sizeof(a) / sizeof(a[0]));
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	Printf(a, sizeof(a) / sizeof(a[0]));
}

void QuickSortTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0 };
	/*int a[] = { 1, 2, 3 ,4, 5, 6, 7, 8, 9, 10 };*/
	Printf(a, sizeof(a) / sizeof(a[0]));
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Printf(a, sizeof(a) / sizeof(a[0]));
}

void QuickSortNonRTest()
{
	int a[] = { 8, 1, 4, 2, 9, 7, 5, 6, 3, 0 };
	Printf(a, sizeof(a) / sizeof(a[0]));
	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	Printf(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	TestOP();

	//InsertSortTest();
	//ShellSortTest();
	//SelectSortTest();
	//HeapSortTest();
	//BubbleSortTest();
	//QuickSortTest();
	//QuickSortNonRTest();
	return 0;
}