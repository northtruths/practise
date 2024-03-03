#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//若队列为空，新节点作为队列头尾
	if (q->front == NULL)
	{
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		assert(newnode);//开辟失败
		newnode->data = data;
		q->front = newnode;
		q->rear = newnode;
		q->rear->next = NULL;
	}
	//不为空则，尾插
	else
	{
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		assert(newnode);//开辟失败
		newnode->data = data;
		newnode->next = NULL;
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	//链表头删,若节点只有一个则队尾也要置空
	if (q->size == 1)
	{
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
		q->size--;
		return;
	}
	QNode* newfront = q->front->next;
	free(q->front);
	q->front = newfront;
	q->size--;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
bool QueueEmpty(Queue* q)
{
	return q->front == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* del = q->front;
	while (q->front)
	{
		q->front = q->front->next;
		free(del);
		del = q->front;
	}
}