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
		int temp = a[i + gap];//�˴δ��ŵ�����
		int j = i;//Ѱ���±�
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
	//˼�룺���ڲ�����������Խ�ӽ�����Ч��Խ�ߣ�
	// ���ʹ��һ�� gap(һ����������������й�)���Ƚ�ÿ��Ԥ���������������Ƚӽ�����
	//����ٲ������򣨵� gap = 1 ��ʵ���ǲ��������ˣ�
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//int begin = 0;//ÿ������ʼ�ĵط���Ҳ��ÿ���������Ԫ�أ�Ҳ��ÿ�� cur ����Сλ��
		//int cur = 0;//��ǰλ��
		//for (int i = 0; i < gap; ++i)//��Ҫ�ŵ�����
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
			int temp = a[i + gap];//�˴δ��ŵ�����
			int j = i;//Ѱ���±�
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

void AdjustDown(int* a, int n, int root)//һ�����µ���,ʱ�临�Ӷ�Ϊ( O(logN) )
{
	//˼·���ҳ����Һ���������ģ��͸��ڵ�Ƚϣ�����������ͽ�����Ȼ����֮ǰ��λ����Ϊ�µĸ��ڵ�һֱ����������ȥ
	int parent = root;
	int schild = parent * 2 + 1;//Ĭ���������ӣ��Ȼ�ȽϿ��Ƿ����Һ��Ӹ��С�������
	while (schild < n)
	{
		if (schild + 1 < n && a[schild] < a[schild + 1])//�Һ�����������
			schild += 1;
		if(a[parent] < a[schild])//����û���������������ӵ���
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

void HeapSort(int* a, int n)//( O(N*logN) ) -> ����(N) + ���µ���(N*logN)
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
	
	//������������Ϊ��(���� )
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
	//˼�룺�����Ƚϣ����ϴ��/��С����������һ����
	// һ�������Ͱѵ�ǰ���/��С���ŵ�����ȥ��
	int num = n - 1;//�ܹ�Ҫ�ŵ�����
	int size = n - 1;//��ǰ��Ҫ�ŵĴ���
	while (num--)
	{
		int flag = 0;//����һ����־�������Ƿ���й���������û��˵������ֱ����ֹѭ��
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

int PartSort1(int* a, int left, int right)//���� hoare ��(�ݹ�)
{
	//˼�룺������ͷԪ�ػ�βԪ����Ϊ key�������±������ͷ��β��ʼ��������
	//������ key Զ��һ������(�����ſ��Ա�֤�����±�����ʱ�� key ��������ȷ��),���±������� key ���ͣ�£������������� key С��ͣ�£�
	//���߶�ͣ��ʱ������������ľ͵� key �ұߣ�С�ľ͵� key ����ˣ�Ȼ����������ʱ��λ�þ��� key ����ȷ˳��λ��
	//������������ key ��λ�ý������Ϊ�������飬�������������ظ��������裬Ҳ���ǵݹ�
	int begin = left;
	int end = right;
	if (left >= right)//��ʱ����ֻ��һ��Ԫ�ػ�û��Ԫ�أ�Ҳ���������ˣ��ع�
		return 0;
	int keyi = left;//key ���±�
	while (left != right)
	{
		//����С
		while (a[right] >= a[keyi] && right > left)
		{
			--right;
		}
		//���Ҵ�
		while (a[left] <= a[keyi] && left < right)
		{
			++left;
		}
		//�ҵ��ˣ���������������
		swap(&a[left], &a[right]);
	}
	//����
	swap(&a[keyi], &a[left]);
	keyi = left;
	//�����Ϊ[left, keyi - 1] [keyi] [keyi + 1, right]
	PartSort1(a, begin, keyi - 1);
	PartSort1(a, keyi + 1, end);
}

int PartSort2(int* a, int left, int right)//�����ڿӷ�(�ݹ�)
{
	//˼·���˷��ǻ��� hoare �汾��˼�룬���׻�β��Ϊ key�������������ʱ������
	//��Ϊ�����λ�õ���ȡ�����γ�һ����λ����һ��������±��Ҵ�/С��
	// ���ҵ�������������λ�������Ǹ�λ����Ϊ�µĿ�λ��ѭ��֪������������λ�ü� key ������λ��
	//���� hoare ��һ�����ݹ�
	int begin = left;
	int end = right;
	if (left >= right)
		return 0;
	int key = a[left];//�� ��Ϊ key ȡ��
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
	//�����Ϊ[left, keyi - 1] [keyi] [keyi + 1, right]
	PartSort2(a, begin, keyi - 1);
	PartSort2(a, keyi + 1, end);
}

int PartSort3(int* a, int left, int right)//����ǰ��ָ�뷨(�ݹ�)
{
	//˼·������ָ�룬ǰָ��һֱ�ߣ���ָ����ǰָ������λ�õ�����С�� key ʱ������ǰ��һ������ǰָ�뽻��ֵ��
	// ���ǰָ���������飬��ָ������λ�þ���key��˳��λ�ã�����λ����key�������ɣ����ݹ�
	//���ͣ���Ϊ����ָ��һֱ������λ�����ݶ�С��key����ôС��С������������С������ǰ����ǰ�����󣬺��ͣ�ڴ��ǰ�棬
	// ��ǰ������С������ǰ��һ�������Ѵ󽻻�������ȥ�ˣ����Ժ�ָ���λ��һֱС�� key����ǰָ��һ����С�ͻᱻ������ǰ��ȥ��
	// ���ǰָ������ʱ����ָ��ǰȫ�Ǵ�������λ�þ�Ϊ key ��λ����

	//��˵˵ָ�뷨����ʵ���Ǳ�����ָ�룬ֻ��˼·��˫ָ���������ȡ��������ְѣ�
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
	//�����Ϊ[left, keyi - 1] [keyi] [keyi + 1, right]
	PartSort3(a, left, keyi - 1);
	PartSort3(a, keyi + 1, right);
}
int OptQuickSort(int* a, int left, int right)//���ŵ��Ż�������ֱ�Ӱ���������������������λ���ˣ�ֱ�ӵ��ò���ȥ�� key �� keyi
{
	//�����Ż�������ȡ��ȡ key��ʹȡ���� key ����ʵ˳��Խ�����м�Խ��
	//���ݹ鵽С��������ʱʹ�ò���������Ϊ���ŵݹ������ƶ������ĵݹ�
	// Խ���ݹ鿪�ٵ�ջԽ�����Ĵ󣬲���С������������������㷨���Ķ�����
	// ���� release �µݹ鿪��ջ���Ż��ü��ã����Դ��Ż���Ч�����Ƿǳ�����
	
	int midi = (left + right) / 2;//��������������
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

	//��ϲ��������޷�д���⣬�Ժ���Ҫ�Ļ�����λ��д�ڵݹ�ķ�������(�����������),
	// ����ǰ���ò��������ʣ�µ�С���������źü���
}

//ʱ�临�Ӷȣ�����(�������������ӽ�����)��O(N^2)
//�����������������¼������ᷢ�������ҿ���������ȡ���Ż����������������ʵ�����O(N*logN)
void QuickSort(int* a, int left, int right)
{
	//˼�룺�Ӵ���������ѡ��һ�� key������ͨ�����ַ�����
	// �ﵽ -> ������ key С���ݻᱻ�Ƶ� key ��ȷ˳��λ�õ���ߣ��� key ������ұߣ���� key �����ƶ�����ȷ˳��λ��
	
	//PartSort1(a, left, right);
	//PartSort2(a, left, right);
	PartSort3(a, left, right);
}

void QuickSortNonR(int* a, int left, int right)//����(�ǵݹ�)
{
	//˼�룺���ݹ��Ϊ�ǵݹ飬�ݹ��һ���ص��Ǻ���ȳ�����ջ�ص�һ����������ջ����ݹ�
	// ���ݹ���Ĵ����µĲ���������ͬһ�����������Ǿ���ջ�����,��ջģ�⴫�Σ�ѭ��ģ����ƺͻع�
	
	//ÿѭ��һ�ν������������ջ��ͬʱ��һ��ջ����ʹ��
	SK sk;
	InitStack(&sk);
	PushStack(&sk, right);
	PushStack(&sk, left);//ÿ����ջ������˳���ܸ㷴,����������ң������ȳ���
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
		//����ͬ��Ϊ��Ϊ[left, keyi - 1] [keyi] [keyi + 1, right], 
		//������������ջ�����Ǵ���

		if (keyi + 1 < right)//�ȴ��ұߵ��������꣬��������ߵ�����
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