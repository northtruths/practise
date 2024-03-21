#define _CRT_SECURE_NO_WARNINGS

#include"BT.h"



BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	//�����⣺�ȸ�������������
	//��С�����⣺Ϊ��
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	assert(root);
	root->_data = a[(*pi)++];//ÿ����һ������±� + 1
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}

void BinaryTreeDestory(BTNode** root)
{
	//�����ͷ�
	if (!root)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	
	//�����⣺�������ڸ�����������
	//��С�����⣺����
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	//�����⣺����Ҷ������������������Ҷ���ĺ� 
	//��С�����⣺û��Ҷ�ӣ�����˵������Ҷ��,��Ϊ����
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//�����⣺��k��Ľڵ�����������������ĵ�k-1��ڵ������
	//��С�����⣺Ϊ��; ����Ϊ 1
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//�����⣺�Ҹ�Ȼ������������
	//��С�����⣺Ϊ�գ��ҵ�
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* rl = BinaryTreeFind(root->_left, x);
	if (rl)
		return rl;
	return BinaryTreeFind(root->_right, x);
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
	{
		printf("# ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)
{
	//����ʵ�֣�ÿ�����Ľ���ָ����Ϊ���еĳ�Ա
	// ������ӣ������Ӻ����������������
	//��������������Ϊ��
	assert(root);
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while(!QueueEmpty(&q))
	{
		BTNode* tfront = q.front->data;
		printf("%c ", tfront->_data);//��ӡ����ֵ
		QueuePop(&q);
		//����������Ϊ�վ����
		if(tfront->_left)
		QueuePush(&q, tfront->_left);
		if(tfront->_right)
		QueuePush(&q, tfront->_right);
	}
	QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root)
{
	//��ȫ������Ҷ�Ӳ��Ǳ����ģ���������������
	//����������ҵ���һ���ս�㣬�����滹�зǿս�㼴������ȫ������
	//�������վ���գ��ս�����������ӣ�
	// ����һ����־��ʶ�Ƿ��߹��ս�㣬���߹��ս�㻹�����������Ϊ����ȫ������
	assert(root);
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	int flag = 0;
	while (!QueueEmpty(&q))
	{
		BTNode* tfront = q.front->data;
		if (tfront == NULL)
			flag = 1;
		if (flag == 1 && tfront)
		{
			QueueDestroy(&q);
			return false;
		}
		QueuePop(&q);
		//����Ϊ��������������Ϊ��,������
		//����Ϊ�ն���������Ϊ�գ������
		if (tfront && tfront->_left )
			QueuePush(&q, tfront->_left);
		else if(tfront != NULL && tfront->_left == NULL)
			QueuePush(&q, NULL);
		if (tfront && tfront->_right)
			QueuePush(&q, tfront->_right);
		else if(tfront != NULL && tfront->_right == NULL)
			QueuePush(&q, NULL);
	}
	QueueDestroy(&q);
	return true;
}

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