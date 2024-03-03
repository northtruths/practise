#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//������Ϊ�գ��½ڵ���Ϊ����ͷβ
	if (q->front == NULL)
	{
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		assert(newnode);//����ʧ��
		newnode->data = data;
		q->front = newnode;
		q->rear = newnode;
		q->rear->next = NULL;
	}
	//��Ϊ����β��
	else
	{
		QNode* newnode = (QNode*)malloc(sizeof(QNode));
		assert(newnode);//����ʧ��
		newnode->data = data;
		newnode->next = NULL;
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	//����ͷɾ,���ڵ�ֻ��һ�����βҲҪ�ÿ�
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
bool QueueEmpty(Queue* q)
{
	return q->front == NULL;
}
// ���ٶ��� 
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