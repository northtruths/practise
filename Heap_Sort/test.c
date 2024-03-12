#define _CRT_SECURE_NO_WARNINGS

#include"HeapSort.h"

int main()
{
	int test1[10] = { 3, 65, 1, 8, 4, 24, 86, 11, 1, 17 };
	int n = sizeof(test1) / sizeof(test1[0]);
	HeapSort(&test1, n);
	return 0;
}