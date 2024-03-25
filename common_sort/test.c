#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"

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

int main()
{
	//InsertSortTest();
	ShellSortTest();
	return 0;
}