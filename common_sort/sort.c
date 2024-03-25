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
	//思想：将数插入已有序的数组中，从后往前遍历(看情况吧？)，
	// 符合顺序(大于前小于后 或相反)便插入
	//从数组第一个元素开始视为有序数组(因为只有一个数)
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
	//思想：基于插入排序数组越接近有序效率越高，
	// 提出使用一个 gap(一个数，与数组分组有关)，先将每组预排序，让整个数组先接近有序
	//最后再插入排序（当 gap = 1 其实就是插入排序了）
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