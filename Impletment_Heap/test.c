#define _CRT_SECURE_NO_WARNINGS

#include"Heap.h"
Heap test;

int main()
{
	HeapCreate(&test, test._a, test._size);
	int arr[10] = { 13, 95 ,4, 1, 91, 44, 17, 86, 52, 9 };
	for (int i = 0; i < 10; ++i)
	{
		HeapPush(&test, arr[i]);

	}
	printf("堆里有效个数为：%d\n", test._size);
	while (!HeapEmpty(&test))
	{
		printf("%d ", HeapTop(&test));
		HeapPop(&test);
	}
	HeapDestory(&test);
	return 0;
}