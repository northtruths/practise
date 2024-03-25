#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"

void swap(int* a, int left, int right)
{
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

void InsertSort(int* a, int n)//O(n^2)
{
	//˼�룺��������������������У��Ӻ���ǰ����(������ɣ�)��
	// ����˳��(����ǰС�ں� ���෴)�����
	//�������һ��Ԫ�ؿ�ʼ��Ϊ��������(��Ϊֻ��һ����)
	int begin = 0;
	int cur = begin;
	for (begin; begin < n - 1; ++begin)
	{
		cur = begin + 1;
		while (cur > 0 && a[cur] < a[cur - 1])
		{
			swap(a, cur, cur - 1);
			--cur;
		}
	}
}

void ShellSort(int* a, int n)
{
	//˼�룺���ڲ�����������Խ�ӽ�����Ч��Խ�ߣ�
	// ���ʹ��һ�� gap(һ����������������й�)���Ƚ�ÿ��Ԥ���������������Ƚӽ�����
	//����ٲ������򣨵� gap = 1 ��ʵ���ǲ��������ˣ�
	int gap = 3;
	int begin = 0;
	int cur = 0;
	for (int i = gap; i > 0; --i)
	{
		for (int j = begin; j < n - gap; j += gap)
		{
			cur = j + gap;
			while (cur > begin && a[cur] < a[cur - gap])
			{
				swap(a, cur, cur - gap);
				cur -= gap;
			}
		}
		begin++;
	}

}