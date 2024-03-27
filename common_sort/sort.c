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
			swap(&a[cur], &a[cur - 1]);
			--cur;
		}
	}
}

void ShellSort(int* a, int n)//O(N^1.3)
{
	//˼�룺���ڲ�����������Խ�ӽ�����Ч��Խ�ߣ�
	// ���ʹ��һ�� gap(һ����������������й�)���Ƚ�ÿ��Ԥ���������������Ƚӽ�����
	//����ٲ������򣨵� gap = 1 ��ʵ���ǲ��������ˣ�
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		int begin = 0;//ÿ������ʼ�ĵط���Ҳ��ÿ���������Ԫ�أ�Ҳ��ÿ�� cur ����Сλ��
		int cur = 0;//��ǰλ��
		for (int i = 0; i < gap; ++i)//��Ҫ�ŵ�����
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
	//˼�룺ÿ�δӴ����������ҳ����/��С�����������е���ʼλ��
	//�Ż���ÿ��ѭ����������Сֵ���ҳ������������е���ʼ��ĩβλ��
	int begin = 0, end = n - 1, curi = begin;//��ʼ,ĩβ,��ǰ
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
		if (!(begin == maxi && end == mini))//�� begin �� max �ص����� end �� min �ص�ʱֻ����һ�Σ���Ȼ�ͻ���ȥ��
		swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

void AdjustDown(int* a, int n, int root)//һ�����µ���
{
	int parent = root;
	int schild = parent * 2 - 1;//Ĭ���������ӣ��Ȼ�ȽϿ��Ƿ����Һ��Ӹ��С�������
	while (schild < n)
	{
		if (schild + 1 < n && a[schild] < a[schild + 1])//�Һ�����������
			schild += 1;
		if(a[parent] < a[schild])//����û���������������ӵ���
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
	//˼·���Ƚ��ѣ������ô�ѣ�������С��
	//���Ѷ���ֵ����ĩβȻ�����µ������δ�/С��ֵ�������Ѷ���Ȼ����ڵ����ڶ�λ�ã��Դ�ѭ��

	//����
	//���ϵ�������(ʱ�临�Ӷȣ�O(N*logN) ),���µ�������( O(N) )
	
	//���ϵ�������˼·����Ϊ���ڵ������Ϊһ���ѣ��Դ˰����Ѻ��������Ϊһһ���룬Ȼ�����ϵ�����
	// ��Ϊ��Խ��ڵ�Խ�ಢ�ҽڵ�Խ�����ϵ�������Խ�࣬����Ч�ʽϵ�

	//���µ�������˼·����Ϊÿ��Ҷ�ڵ���Ե�����Ϊһ���ѣ��Դ��ҳ��丸�ڵ������µ�������Ϊ�ѣ�Ȼ���������Ҹ��ڵ�ĸ��ڵ㣬
	//��Ϊ��һ���Ѿ����������Ϊ���ˣ������ֿ��������µ��������ν������������Ϊ��
	//��Ϊ������������ϵ������ڶ�����ʱ�ڵ�൫���������٣��ڶ�����ʱ���������൫�ڵ��٣�����Ч�ʸ���
	
	//������������Ϊ��
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