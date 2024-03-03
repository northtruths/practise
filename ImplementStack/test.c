#define _CRT_SECURE_NO_WARNINGS

#include"stack.h"

int main()
{
	SK sk;

	InitStack(&sk);
	PushStack(&sk, 1);
	PushStack(&sk, 2);
	PushStack(&sk, 3);
	PushStack(&sk, 4);
	PushStack(&sk, 5);
	PushStack(&sk, 6);
	printf("%d\n",SizeStack(&sk));//5
	while ((&sk)->top)
	{
		printf("%d ", (&sk)->arr[(&sk)->top - 1]);//654321
		PopStack(&sk);
	}
	if (EmptyStack(&sk))
		printf("Îª¿Õ£¡\n");
	else
		printf("²»Îª¿Õ£¡\n");
	DestroyStack(&sk);

	return 0;
}