#define _CRT_SECURE_NO_WARNINGS

#include"poly.h"



node* ListCreat(int* n)
{
	node* head = NULL, *end = NULL, *cur = NULL;
	head = (node*)malloc(sizeof(node));//先把头节点开好 
	end = head;
	end->next = NULL;
	int i = 1;
	printf("请输入第%d的系数、指数,用空格隔开\n", i++);
	scanf("%d%d", &cur->coef, &cur->index);
	while (1)
	{
		cur = (node*)malloc(sizeof(node));
		assert(cur);
		printf("请输入第%d的系数、指数,用空格隔开\n", i++);
		if (scanf("%d%d", &cur->coef, &cur->index) == EOF)//输入同时将其作为判断条件  
			break;
		end->next = cur;
		end = cur;
		end->next = NULL;
	}
	free(cur);
	cur = NULL;
	return head;
}