#pragma once


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, bf(0)
		, _val(val)
	{}

	AVLTreeNode<T>* _parent;
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	int bf;// �ڵ��ƽ������
	T _val;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> ;
public:
	AVLTree()
		:_root(nullptr)
	{

	}

	bool Insert(const& T val)
	{
		Node* newnode = new Node(val);
		Node* cur = _root;
		if (cur == nullptr)
		{
			cur = newnode;
			return true;
		}
		while (cur)
		{
			if (val < cur->_val)
			{
				if (cur->_left == nullptr)
				{
					cur->_left = newnode;
					return true;
				}
				else
				{
					cur = cur->_left;
				}
			}
			else if (val > cur->_val)
			{
				if (cur->_right == nullptr)
				{
					cur->_right = newnode;
					return true;
				}
				else
				{
					cur = cur->_right;
				}
			}
			else
				return false;
		}

	}
}
	bool IsALVTree()
	{
		return _IsAVLTree(_root);
	}

private:
	// ����AVL���ĸ�����֤pRoot�Ƿ�Ϊ��Ч��AVL��
	bool _IsAVLTree(Node* pRoot)
	{
		if (pRoot->bf >= 2)
			return false;
		return _IsAVLTree(pRoot->_left) && _IsAVLTree(pRoot->_right);
	}
	size_t _Height(Node* pRoot);
	// �ҵ���
	void RotateR(Node* pParent);
	// ����
	void RotateL(Node* pParent);
	// ����˫��
	void RotateRL(Node* pParent);
	// ����˫��
	void RotateLR(Node* pParent);

private:

	Node* _root;
};