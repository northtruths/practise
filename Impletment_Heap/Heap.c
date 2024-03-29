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
	//前提：本身为堆结构，适用已有一个堆，在堆尾添加数据
	//思想：将父子进行比较然后交换，在将父节点作为子节点和它的父节点再此比较交换，达成向上调整保持堆结构
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

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//判断扩容
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
	//向上调整以保持结构
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
	//前提：需要向下调整的节点的左右子树为堆
	//思路：找出左右孩子“能力”大的交换，然后再子节点作父节点重复此步骤
	int parent = 0;
	int schild = parent * 2 + 1;//这里默认先是左孩子
	while (schild < size)
	{
		//从左右孩子找出能力强的
		//现在是小堆，小的能力强
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

void HeapPop(Heap* hp)
{
	assert(hp);
	//先根和最后最右的叶对换，再向下调整
	Swap(hp->_a, 0, hp->_size - 1);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size);
}