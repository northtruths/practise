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
	//int begin = 0;
	//int cur = begin;
	//for (begin; begin < n - 1; ++begin)
	//{
	//	cur = begin + 1;
	//	while (cur > 0 && a[cur] < a[cur - 1])
	//	{
	//		swap(&a[cur], &a[cur - 1]);
	//		--cur;
	//	}
	//}
	int gap = 1;
	for (int i = 0; i < n - gap; ++i)
	{
		int temp = a[i + gap];//此次待排的数据
		int j = i;//寻找下标
		while (j >= 0)
		{
			if (a[j] > temp)
			{
				a[j + gap] = a[j];
				j -= gap;
			}
			else
			{
				break;
			}
		}
		a[j + gap] = temp;
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
		//int begin = 0;//每次排序开始的地方，也是每组数组的首元素，也是每个 cur 的最小位置
		//int cur = 0;//当前位置
		//for (int i = 0; i < gap; ++i)//需要排的组数
		//{
		//	for (int j = begin; j < n - gap; j += gap)
		//	{
		//		cur = j + gap;
		//		while (cur > begin && a[cur] < a[cur - gap])
		//		{
		//			swap(&a[cur], &a[cur - 1]);
		//			cur -= gap;
		//		}
		//	}
		//	++begin;
		//}
		for (int i = 0; i < n - gap; ++i)
		{
			int temp = a[i + gap];//此次待排的数据
			int j = i;//寻找下标
			while( j >= 0)
			{
				if (a[j] > temp)
				{
					a[j + gap] = a[j];
					j -= gap;
				}
				else
				{
					break;
				}
			}
			a[j + gap] = temp;
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

void AdjustDown(int* a, int n, int root)//一次向下调整,时间复杂度为( O(logN) )
{
	//思路：找出左右孩子能力大的，和父节点比较，孩子能力大就交换，然后孩子之前的位置作为新的父节点一直这样调整下去
	int parent = root;
	int schild = parent * 2 + 1;//默认先是左孩子，等会比较看是否是右孩子更有“能力”
	while (schild < n)
	{
		if (schild + 1 < n && a[schild] < a[schild + 1])//右孩子能力更大
			schild += 1;
		if(a[parent] < a[schild])//父亲没孩子有能力，儿子当爹
		{
			swap(&a[parent], &a[schild]);
			parent = schild;
			schild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)//( O(N*logN) ) -> 建堆(N) + 向下调整(N*logN)
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
	
	//把数组数据排为堆(建堆 )
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
		--size;
		AdjustDown(a, size, 0);
	}
}

void BubbleSort(int* a, int n)//(O(N^2))
{
	//思想：两两比较，将较大的/较小交换到后面一个，
	// 一轮下来就把当前最大/最小的排到后面去了
	int num = n - 1;//总共要排的轮数
	int size = n - 1;//当前轮要排的次数
	while (num--)
	{
		int flag = 0;//设置一个标志看本次是否进行过交换，若没有说明有序直接终止循环
		for (int i = 0; i < size; ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(&a[i], &a[i + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
		size--;
	}
}

int PartSort1(int* a, int left, int right)//快排 hoare 版(递归)
{
	//思想：将数组头元素或尾元素作为 key，两个下标从数组头和尾开始遍历数组
	//必须离 key 远的一方先走(这样才可以保证左右下标相遇时与 key 交换是正确的),左下标遇到比 key 大的停下，右坐标遇到比 key 小的停下，
	//两边都停下时交换，这样大的就到 key 右边，小的就到 key 左边了，然后左右相遇时的位置就是 key 的正确顺序位置
	//最后将数组从现在 key 的位置将数组分为两个数组，将这两个数组重复上述步骤，也就是递归
	int begin = left;
	int end = right;
	if (left >= right)//此时数组只有一个元素或没有元素，也就是有序了，回归
		return 0;
	int keyi = left;//key 的下标
	while (left != right)
	{
		//右找小
		while (a[right] >= a[keyi] && right > left)
		{
			--right;
		}
		//左找大
		while (a[left] <= a[keyi] && left < right)
		{
			++left;
		}
		//找到了，交换，或相遇了
		swap(&a[left], &a[right]);
	}
	//相遇
	swap(&a[keyi], &a[left]);
	keyi = left;
	//数组分为[left, keyi - 1] [keyi] [keyi + 1, right]
	PartSort1(a, begin, keyi - 1);
	PartSort1(a, keyi + 1, end);
}

int PartSort2(int* a, int left, int right)//快排挖坑法(递归)
{
	//思路：此法是基于 hoare 版本的思想，将首或尾作为 key，并将其存在临时变量里
	//视为将这个位置的数取出，形成一个坑位，另一个方向的下标找大/小，
	// 将找到的数填进这个坑位，并将那个位置视为新的坑位，循环知道相遇，相遇位置即 key 真正的位置
	//最后和 hoare 版一样，递归
	int begin = left;
	int end = right;
	if (left >= right)
		return 0;
	int key = a[left];//左 作为 key 取出
	while (left != right)
	{
		while (right > left && a[right] >= key)
		{
			--right;
		}
		a[left] = a[right];
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[right] = a[left];
	}
	a[left] = key;
	int keyi = left;
	//数组分为[left, keyi - 1] [keyi] [keyi + 1, right]
	PartSort2(a, begin, keyi - 1);
	PartSort2(a, keyi + 1, end);
}

int PartSort3(int* a, int left, int right)//快排前后指针法(递归)
{
	//思路：两个指针，前指针一直走，后指针在前指针所处位置的数据小于 key 时，才向前走一步并和前指针交换值，
	// 最后前指针走完数组，后指针所在位置就是key的顺序位置，将此位置与key交换即可，最后递归
	//解释：因为若两指针一直经过的位置数据都小于key，那么小与小交换（本身），小还是在前，若前遇到大，后会停在大的前面，
	// 当前再遇到小，就向前走一步交换把大交换到后面去了，所以后指针的位置一直小于 key，而前指针一遇到小就会被交换至前面去，
	// 最后前指针走完时，后指针前全是大，它所处位置就为 key 的位置了

	//虽说说指针法，其实不是必须用指针，只是思路和双指针很像，所以取的这个名字把？
	if (left >= right)
		return 0;
	//OptQuickSort(a, left, right);
	int keyi = left;
	int prev = left + 1;
	int post = left;
	while (prev <= right)
	{
		if (a[prev] < a[keyi])
		{
			++post;
			swap(&a[prev], &a[post]);
		}
		++prev;
	}
	swap(&a[keyi], &a[post]);
	keyi = post;
	//数组分为[left, keyi - 1] [keyi] [keyi + 1, right]
	PartSort3(a, left, keyi - 1);
	PartSort3(a, keyi + 1, right);
}
int OptQuickSort(int* a, int left, int right)//快排的优化，这里直接把三数的中数放在数组首位置了，直接调用不用去管 key 或 keyi
{
	//两个优化：三数取中取 key，使取出的 key 的真实顺序越靠近中间越好
	//当递归到小的子区间时使用插入排序，因为快排递归是类似二叉树的递归
	// 越深层递归开辟的栈越多消耗大，并且小区间的排序其他排序算法消耗都不大，
	// 但在 release 下递归开辟栈被优化得极好，所以此优化的效果并非非常明显
	
	int midi = (left + right) / 2;//第三个数的坐标
	if ((a[midi] >= a[left] && a[midi] <= a[right])
		|| (a[midi] >= a[right] && a[midi] <= a[left]))
	{
		swap(&a[midi], &a[left]);
		return midi;
	}
	else if ((a[left] >= a[midi] && a[left] <= a[right]) 
		|| (a[left] >= a[right] && a[left] <= a[midi]))
	{
		return left;
	}
	else
	{
		swap(&a[right], &a[left]);
		return right;
	}

	//混合插入排序无法写在这，以后需要的话，则位置写在递归的返回条件(替代返回条件),
	// 返回前先用插入排序把剩下的小区间数组排好即可
}

//时间复杂度：最坏情况(待排数据有序或接近有序)：O(N^2)
//但因最坏情况在随机情况下几乎不会发生，并且可以用三数取中优化掉此情况，所以真实情况：O(N*logN)
void QuickSort(int* a, int left, int right)
{
	//思想：从待排数据中选择一个 key，后续通过各种方法，
	// 达到 -> 遇到比 key 小数据会被移到 key 正确顺序位置的左边，比 key 大的在右边，最后 key 将会移动到正确顺序位置
	
	//PartSort1(a, left, right);
	//PartSort2(a, left, right);
	PartSort3(a, left, right);
}

void QuickSortNonR(int* a, int left, int right)//快排(非递归)
{
	//思想：将递归改为非递归，递归的一个特点是后进先出，和栈特点一样，所以用栈代替递归
	// 而递归核心传递新的参数，作用同一个函数，我们就用栈存参数,出栈模拟传参，循环模拟递推和回归
	
	//每循环一次将左右区间存入栈，同时出一次栈进行使用
	SK sk;
	InitStack(&sk);
	PushStack(&sk, right);
	PushStack(&sk, left);//每次入栈的左右顺序不能搞反,这里先入的右，所以先出左
	while(!EmptyStack(&sk))
	{
		left = TopStack(&sk);
		PopStack(&sk);
		right = TopStack(&sk);
		PopStack(&sk);
		OptQuickSort(a, left, right);
		int keyi = left;
		int prev = left + 1;
		int post = left;
		while (prev <= right)
		{
			if (a[prev] < a[keyi])
			{
				++post;
				swap(&a[prev], &a[post]);
			}
			++prev;
		}
		swap(&a[keyi], &a[post]);
		keyi = post;
		//数组同样为分为[left, keyi - 1] [keyi] [keyi + 1, right], 
		//不过现在是入栈而不是传参

		if (keyi + 1 < right)//先存右边的数组坐标，则先排左边的数组
		{
			PushStack(&sk, right);
			PushStack(&sk, keyi + 1);
		}
		if (left < keyi - 1)
		{
			PushStack(&sk, keyi - 1);
			PushStack(&sk, left);
		}
	}

}