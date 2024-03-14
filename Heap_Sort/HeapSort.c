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
	int schild = parent * 2 + 1;//����Ĭ����������
	while (schild < size)
	{
		//�����Һ����ҳ�����ǿ��
		//С��С����ǿ����Ѵ������ǿ
		if (schild + 1 < size && a[schild] > a[schild + 1])
		{
			schild++;
		}
		if (a[schild] < a[parent])
		{
			Swap(a, schild, parent);
			parent = schild;//����������һ�Ը���
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
		if (a[child] < a[parent])// < ��С�ѣ� > ����
		{
			Swap(a, child, parent);//�������ӵ�ֵ
			child = parent;//���ӱ�Ϊ���ϵ�һ��
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
	//�ȸ���������ҵ�Ҷ�Ի��������µ���
	Swap(hp, 0, size - 1);
	size--;
	AdjustDown(hp, size, 0);
}

void HeapSort(int* a, int size)
{
	//����,��ĩҶ�ӵĸ��ڵ㿪ʼ
	//�����ô�ѣ�������С��
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, 10, i);
	}
	//�������ö�pop��˼�뽫���/��С���Ƚ�����ĩβ���ٵ���
	for (int j = size; j > 0; --j)
	{
		HeapPop(a, j);
	}
}

void CreatFileData(int n, int max)
{
	FILE* file = fopen("C:/��ʱ/data", "w");
	srand((int)time(NULL));
	while (n--)
	{
		fprintf(file, "%d\n", rand() % max);
	}
	fclose(file);
}

void PrintfTopK(int k)
{//
	//�Ƚ��ѣ����öѶ������/��С�����ʣ�
	//  �����������ݽ���С/�ϴ�����ݷŽ�����

	HPDataType* topk = (HPDataType*)malloc(sizeof(HPDataType) * k);
	FILE* file = fopen("C:/��ʱ/data", "r");
	for (int i = 0; i < k; ++i)
	{
		fscanf(file, "%d", &topk[i]);
	}
	HeapSort(topk, k);//��С�ѣ���С���ڶѶ���ֻҪ��������ľ����
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