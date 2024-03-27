#define _CRT_SECURE_NO_WARNINGS

#include"sort.h"

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void InsertSort(int* a, int n)//O(N^2)
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
			swap(&a[cur], &a[cur - 1]);
			--cur;
		}
	}
}

void ShellSort(int* a, int n)//O(N^1.3)
{
	//思想：基于插入排序数组越接近有序效率越高，
	// 提出使用一个 gap(一个数，与数组分组有关)，先将每组预排序，让整个数组先接近有序
	//最后再插入排序（当 gap = 1 其实就是插入排序了）
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int begin = 0;//每次排序开始的地方，也是每组数组的首元素，也是每个 cur 的最小位置
		int cur = 0;//当前位置
		for (int i = 0; i < gap; ++i)//需要排的组数
		{
			for (int j = begin; j < n - gap; j += gap)
			{
				cur = j + gap;
				while (cur > begin && a[cur] < a[cur - gap])
				{
					swap(&a[cur], &a[cur - 1]);
					cur -= gap;
				}
			}
			++begin;
		}
	}
}

void SelectSort(int* a, int n)//O(N^2)
{
	//思想：每次从待排数据中找出最大/最小的数放在序列的起始位置
	//优化：每次循环把最大和最小值都找出来，放在序列的起始和末尾位置
	int begin = 0, end = n - 1, curi = begin;//起始,末尾,当前
	while (begin < end)
	{
		int maxi = begin, mini = begin;
		for (curi = begin; curi <= end; ++curi)
		{
			if (a[curi] > a[maxi])
			{
				maxi = curi;
			}
			if (a[curi] < a[mini])
			{
				mini = curi;
			}
		}
		swap(&a[begin], &a[mini]);
		if (!(begin == maxi && end == mini))//当 begin 和 max 重叠并且 end 和 min 重叠时只交换一次，不然就换回去了
		swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int root)//一次向下调整
{
	int parent = root;
	int schild = parent * 2 - 1;//默认先是左孩子，等会比较看是否是右孩子更有“能力”
	while (schild < n)
	{
		if (schild + 1 < n && a[schild] < a[schild + 1])//右孩子能力更大
			schild += 1;
		if(a[parent] < a[schild])//父亲没孩子有能力，儿子当爹
		{
			swap(&a[parent], &a[schild]);
			parent = schild;
			schild = parent * 2 - 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//思路：先建堆，升序用大堆，降序用小堆
	//将堆顶的值放在末尾然后向下调整将次大/小的值调整到堆顶，然后放在倒数第二位置，以此循环

	//建堆
	//向上调整建堆(时间复杂度：O(N*logN) ),向下调整建堆( O(N) )
	
	//向上调整建堆思路：因为根节点可以视为一个堆，以此挨个把后面的数视为一一插入，然后向上调整，
	// 因为树越深节点越多并且节点越深向上调整次数越多，所以效率较低

	//向下调整建堆思路：因为每个叶节点可以单独视为一个堆，以此找出其父节点用向下调整调整为堆，然后再依次找父节点的父节点，
	//因为上一步已经把下面调整为堆了，所以又可以用向下调整，依次将整个数组调整为堆
	//因为是整体从下往上调整，在堆下面时节点多但调整次数少，在堆上面时调整次数多但节点少，所以效率更高
	
	//把数组数据排为堆
	int root = ((n - 1) - 1) / 2;
	while (root >= 0)
	{
		AdjustDown(a, n, root);
		--root;
	}

	int size = n;
	while (size > 0)
	{
		swap(&a[0], &a[size - 1]);
		AdjustDown(a, size, 0);
		--size;
	}
}