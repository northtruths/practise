#define _CRT_SECURE_NO_WARNINGS

#include"HeapSort.h"

void Swap(HPDataType* a, int child, int parent)
{
	HPDataType temp = a[child];
	a[child] = a[parent];
	a[parent] = temp;
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int schild = parent * 2 + 1;//这里默认先是左孩子
	while (schild < size)
	{
		//从左右孩子找出能力强的
		//小堆小能力强，大堆大的能力强
		if (schild + 1 < size && a[schild] > a[schild + 1])
		{
			schild++;
		}
		if (a[schild] < a[parent])
		{
			Swap(a, schild, parent);
			parent = schild;//调整来到下一对父子
			schild = parent * 2 + 1;
		}
		else
		{
			break;
		}

	}
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])// < 则小堆， > 则大堆
		{
			Swap(a, child, parent);//交换父子的值
			child = parent;//父子变为向上的一对
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}

	}
}

void HeapPop(HPDataType* hp, int size)
{
	assert(hp);
	//先根和最后最右的叶对换，再向下调整
	Swap(hp, 0, size - 1);
	size--;
	AdjustDown(hp, size, 0);
}

void HeapSort(int* a, int size)
{
	//建堆,从末叶子的父节点开始
	//升序用大堆，降序用小堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, 10, i);
	}
	//堆排序，用堆pop的思想将最大/最小的先交换到末尾，再调整
	for (int j = size; j > 0; --j)
	{
		HeapPop(a, j);
	}
}

void CreatFileData(int n, int max)
{
	FILE* file = fopen("C:/临时/data", "w");
	srand((int)time(NULL));
	while (n--)
	{
		fprintf(file, "%d\n", rand() % max);
	}
	fclose(file);
}

void PrintfTopK(int k)
{//
	//先建堆，利用堆顶是最大/最小的性质，
	//  遍历整个数据将较小/较大的数据放进堆里

	HPDataType* topk = (HPDataType*)malloc(sizeof(HPDataType) * k);
	FILE* file = fopen("C:/临时/data", "r");
	for (int i = 0; i < k; ++i)
	{
		fscanf(file, "%d", &topk[i]);
	}
	HeapSort(topk, k);//排小堆，最小的在堆顶，只要遇到更大的就入堆
	HPDataType temp = 0;
	while (fscanf(file, "%d", &temp) != EOF)
	{
		if (temp > topk[0])
		{
			topk[0] = temp;
			AdjustDown(topk, k, 0);
		}
	}
	for(int i = 0; i < k; ++i)
	{
		printf("%d ", topk[i]);
	}
	fclose(file);
}