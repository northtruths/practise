#define _CRT_SECURE_NO_WARNINGS

#include"Heap.h"

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = 0;
	hp->_capacity = 0;
	hp->_size = 0;
}

void Swap(HPDataType* a, int child, int parent)
{
	HPDataType temp = a[child];
	a[child] = a[parent];
	a[parent] = temp;
}

void AdjustUp(HPDataType* a, int child)
{
	//ǰ�᣺����Ϊ�ѽṹ����������һ���ѣ��ڶ�β�������
	//˼�룺�����ӽ��бȽ�Ȼ�󽻻����ڽ����ڵ���Ϊ�ӽڵ�����ĸ��ڵ��ٴ˱ȽϽ�����������ϵ������ֶѽṹ
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

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//�ж�����
	if (hp->_size == hp->_size)
	{
		int newcapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* temp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newcapacity);
		assert(temp);
		hp->_a = temp;
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ����Ա��ֽṹ
	AdjustUp(hp->_a, hp->_size - 1);
}

HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}

void AdjustDown(HPDataType* a, int size)
{
	//ǰ�᣺��Ҫ���µ����Ľڵ����������Ϊ��
	//˼·���ҳ����Һ��ӡ���������Ľ�����Ȼ�����ӽڵ������ڵ��ظ��˲���
	int parent = 0;
	int schild = parent * 2 + 1;//����Ĭ����������
	while (schild < size)
	{
		//�����Һ����ҳ�����ǿ��
		//������С�ѣ�С������ǿ
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

void HeapPop(Heap* hp)
{
	assert(hp);
	//�ȸ���������ҵ�Ҷ�Ի��������µ���
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size);
}