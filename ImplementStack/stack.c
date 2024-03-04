#define _CRT_SECURE_NO_WARNINGS

#include"stack.h"

void InitStack(SK* sk)
{
	assert(sk);
	sk->sizenum = 0; 
	sk->top = 0;//top的位置为尾元素的下一个
	sk->arr = NULL;
}

void DestroyStack(SK* sk)
{
	assert(sk);
	free(sk->arr);
	sk->arr = NULL;
	sk->sizenum = 0;
	sk->top = 0;
}
void PushStack(SK* sk, DataType x)
{
	assert(sk);
	if (sk->top == sk->sizenum)//扩容
	{
		int newsizenum = sk->sizenum == 0 ? 4 : sk->sizenum * 2;
		DataType* temp = (DataType*)realloc(sk->arr, newsizenum * sizeof(DataType));
		sk->sizenum = newsizenum;
		if (temp == NULL)
		{
			perror("扩容失败！\n");
			exit ;
		}
		sk->arr = temp;
	}
	sk->arr[sk->top] = x;
	sk->top++;
}
void PopStack(SK* sk)
{
	assert(sk);
	assert(sk->top);
	sk->top--;
}
bool EmptyStack(SK* sk)
{
	assert(sk);
	return sk->top == 0;
}
DataType TopStack(SK* sk)
{
	assert(sk);
	return sk->arr[sk->top - 1];
}
int SizeStack(SK* sk)
{
	assert(sk);
	return sk->top;
}
