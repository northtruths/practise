#define _CRT_SECURE_NO_WARNINGS

#include"poly.h"



node* ListCreat(int* n)
{
	node* head = NULL, *end = NULL, *cur = NULL;
	head = (node*)malloc(sizeof(node));//�Ȱ�ͷ�ڵ㿪�� 
	end = head;
	end->next = NULL;
	int i = 1;
	printf("�������%d��ϵ����ָ��,�ÿո����\n", i++);
	scanf("%d%d", &cur->coef, &cur->index);
	while (1)
	{
		cur = (node*)malloc(sizeof(node));
		assert(cur);
		printf("�������%d��ϵ����ָ��,�ÿո����\n", i++);
		if (scanf("%d%d", &cur->coef, &cur->index) == EOF)//����ͬʱ������Ϊ�ж�����  
			break;
		end->next = cur;
		end = cur;
		end->next = NULL;
	}
	free(cur);
	cur = NULL;
	return head;
}