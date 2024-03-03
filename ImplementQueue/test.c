#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

int main()
{
	Queue test1;
	QueueInit(&test1);
	QueuePush(&test1, 1);
	QueuePush(&test1, 2);
	QueuePush(&test1, 3);
	QueuePush(&test1, 4);
	QueuePush(&test1, 5);
	printf("%d\n", QueueSize(&test1));//5
	QueuePop(&test1);
	printf("%d\n", QueueFront(&test1));//2
	printf("%d\n", QueueBack(&test1));//5
	if (QueueEmpty(&test1))
		printf("Îª¿Õ£¡\n");
	else
		printf("²»Îª¿Õ£¡\n");
	return 0;
}