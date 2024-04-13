#define _CRT_SECURE_NO_WARNINGS

#include"poly.h"



node* ListCreat(int* n)
{
	*n = 0;
	node* head = NULL, *end = NULL, *cur = NULL;
	head = (node*)malloc(sizeof(node));//先把头节点开好 
	assert(head);
	end = head;
	end->next = NULL;
	int i = 1;
	++(*n);
	printf("请输入第%d项的系数、指数,用空格隔开\n结束输入请输入两个 -1\n", i++);
	scanf("%d%d", &end->coef, &end->index);
	getchar();
	while (1)
	{
		//printf("coef:%d index:%d\n", end->coef, end->index);
		cur = (node*)malloc(sizeof(node));
		cur->coef = NULL;
		cur->index = NULL;
		assert(cur);
		printf("请输入第%d的系数、指数,用空格隔开\n结束输入请输入两个 -1\n", i++);
		scanf("%d%d", &cur->coef, &cur->index);
		if(cur->coef == -1 || cur->index == -1)
			break;
		end->next = cur;
		end = cur;
		end->next = NULL;
		++(*n);
	}
	printf("创建成功！\n");
	free(cur);
	cur = NULL;
	return head;
}

typedef struct Temp
{
	int coef;
	int index;
}Temp;
int compare(void* a, void* b)
{
	return ((Temp*)a)->index - ((Temp*)b)->index;
}

void ListSort(node* head, int n)
{
	//直接用指数和系数建立数组
	//排数组，再遍历链表把值搞回去

	Temp* arr = (node*)malloc(sizeof(Temp) * n);
	node* pcur = head;
	for (int i = 0; i < n; ++i)
	{
		arr[i].coef = pcur->coef;
		arr[i].index = pcur->index;
		pcur = pcur->next;
	}
	qsort(arr, n, sizeof(Temp), compare);
	pcur = head;
	for (int i = 0; i < n; ++i)
	{
		pcur->coef = arr[i].coef;
		pcur->index = arr[i].index;
		pcur = pcur->next;
	}
}

void ListPrint(node* p)
{
	node* pcur = p;
	while(pcur)
	{
		printf("%dx^%d + ", pcur->coef, pcur->index);
		pcur = pcur->next;
	}
	printf("\b\b \n");
}
node* ListAdd(node* p1, node* p2, int n1, int n2)
{
	node* new = (node*)malloc(sizeof(node));//哨兵结点
	new->next = NULL;
	new->coef = 0;
	new->index = 0;
	node* npcur = new;
	node* pcur1 = p1, * pcur2 = p2;
	while(pcur1)
	{
		npcur->next = pcur1;
		npcur = npcur->next;
		pcur1 = pcur1->next;
	}
	while (pcur2)
	{
		npcur->next = pcur2;
		npcur = npcur->next;
		pcur2 = pcur2->next;
	}

	ListSort(new->next, n1 + n2);
	node* head = new->next;
	node* prev = new;
	node* del = head;
	while(head->next)
	{
		if (head->index == head->next->index)
		{
			head->next->coef += head->coef;

			del = head;
			head = head->next;
			prev->next = head;

			free(del);
		}
		else 
		{
			head = head->next;
			prev = prev->next;
		}
	}

	return new->next;
}