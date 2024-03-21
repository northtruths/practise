#define _CRT_SECURE_NO_WARNINGS

#include"BT.h"



BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	//子问题：先根，后左右子树
	//最小子问题：为空
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	assert(root);
	root->_data = a[(*pi)++];//每创建一个结点下标 + 1
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}

void BinaryTreeDestory(BTNode** root)
{
	//后序释放
	if (!root)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

int BinaryTreeSize(BTNode* root)
{
	
	//子问题：个数等于根加左右子树
	//最小子问题：空树
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)
{
	//子问题：树的叶结点个数等于左右子树叶结点的和 
	//最小子问题：没有叶子，或者说根就是叶子,和为空树
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//子问题：第k层的节点个数等于左右子树的第k-1层节点个数和
	//最小子问题：为空; 层数为 1
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//子问题：找根然后找左右子树
	//最小子问题：为空，找到
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
	//队列实现，每个树的结点的指针作为队列的成员
	// 根先入队，根出队后它的左右子树入队
	//结束条件：队列为空
	assert(root);
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while(!QueueEmpty(&q))
	{
		BTNode* tfront = q.front->data;
		printf("%c ", tfront->_data);//打印根的值
		QueuePop(&q);
		//左右子树不为空就入队
		if(tfront->_left)
		QueuePush(&q, tfront->_left);
		if(tfront->_right)
		QueuePush(&q, tfront->_right);
	}
	QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root)
{
	//完全二叉树叶子层是饱满的，或左到右是连续的
	//层序遍历，找到第一个空结点，若后面还有非空结点即不是完全二叉树
	//若遇到空就入空，空结点的子树不入队，
	// 设置一个标志标识是否走过空结点，若走过空结点还有正常结点则为非完全二叉树
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
		//本身不为空且左右子树不为空,入子树
		//本身不为空而左右子树为空，则入空
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