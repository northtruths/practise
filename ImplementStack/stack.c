#define _CRT_SECURE_NO_WARNINGS

#include"stack.h"

void InitStack(SK* stack)
{
	assert(stack);
	stack->sizenum = 0; 
	stack->top = 0;//top的位置为尾元素的下一个
	stack->arr = NULL;
}

void DestroyStack(SK* stack)
{
	assert(stack);
	free(stack->arr);
	stack->arr = NULL;
	stack->sizenum = 0;
	stack->top = 0;
}
void PushStack(SK* stack, DataType x)
{
	assert(stack);
	if (stack->top == stack->sizenum)//扩容
	{
		int newsizenum = stack->sizenum == 0 ? 4 : stack->sizenum * 2;
		DataType* temp = (DataType*)realloc(stack->arr, newsizenum * sizeof(DataType));
		stack->sizenum = newsizenum;
		if (temp == NULL)
		{
			perror("扩容失败！\n");
			exit ;
		}
		stack->arr = temp;
	}
	stack->arr[stack->top] = x;
	stack->top++;
}
void PopStack(SK* stack)
{
	assert(stack);
	assert(stack->top);
	stack->top--;
}
bool EmptyStack(SK* stack)
{
	assert(stack);
	return stack->top == 0;
}
DataType TopStack(SK* stack)
{
	assert(stack);
	return stack->arr[stack->top - 1];
}
int SizeStack(SK* stack)
{
	assert(stack);
	return stack->top;
}
