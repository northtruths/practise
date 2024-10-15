#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& val = T())
		:_parent(nullptr)
		, _left(nullptr)
		, _right(nullptr)
		, bf(0)
		, _val(val)
	{}

	AVLTreeNode<T>* _parent;
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	int bf;// 节点的平衡因子
	T _val;
};

template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_root(nullptr)
	{

	}

	bool Insert(const T& val)
	{
		Node* cur = _Insert(val);
		if (cur == nullptr)//已有插入值，插入失败
		{
			return false;
		}
		if(cur->_parent)
		{
			Node* parent = cur->_parent;
			if (cur == parent->_right)
				++parent->bf;
			else
				--parent->bf;
			while (parent->bf != 0 && parent != _root)
			{
				if (parent->bf == 2)
				{
					if (cur == parent->_right && cur->bf == 1)
					{
						RotateL(parent);
						break;
					}
					else if (cur == parent->_right && cur->bf == -1)
					{
						RotateRL(parent);
						break;
					}
					else if (cur == parent->_left && cur->bf == -1)
					{
						RotateR(parent);
						break;
					}
					else
					{
						RotateLR(parent);
						break;
					}
				}
				else
				{
					cur = cur->_parent;
					parent = parent->_parent;
					if (cur == parent->_right)
						++parent->bf;
					else
						--parent->bf;
				}
			}
		}
		return true;
	}

	bool IsALVTree()
	{
		return _IsAVLTree(_root);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	size_t Height()
	{
		return _Height(_root);
	}

private:
	//单纯插入节点，未进行其他操作
	 Node* _Insert(const T& val)
	{
		Node* newnode = new Node(val);
		Node* cur = _root;
		if (cur == nullptr)
		{
			_root = newnode;
			return _root;
		}
		while (cur)
		{
			if (val < cur->_val)
			{
				if (cur->_left == nullptr)
				{
					cur->_left = newnode;
					newnode->_parent = cur;
					return newnode;
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
					newnode->_parent = cur;
					return newnode;
				}
				else
				{
					cur = cur->_right;
				}
			}
			else
				return nullptr;
		}
	}
	// 根据AVL树的概念验证pRoot是否为有效的AVL树
	bool _IsAVLTree(Node* pRoot)
	{
		if (pRoot == nullptr)
			return true;

		int bf = abs((int)_Height(pRoot->_right) - (int)_Height(pRoot->_left));
		if (pRoot->bf >= 2 && pRoot->bf != bf)
			return false;
		return _IsAVLTree(pRoot->_left) && _IsAVLTree(pRoot->_right);
	}

	size_t _Height(Node* pRoot)
	{
		if (pRoot == nullptr)
		{
			return 0;
		}
		size_t child_height = 0;
		if (pRoot->bf == 1)
		{
			child_height = _Height(pRoot->_right);
		}
		else
		{
			child_height = _Height(pRoot->_left);
		}
		return 1 + child_height;
	}

	// 右单旋
	void RotateR(Node* pParent)
	{
		Node* GrandParent = pParent->_parent;
		Node* L = pParent->_left;
		Node* LR = L->_right;

		if (LR)
		{		
			LR->_parent = pParent;
		}
		pParent->_left = LR;
		pParent->_parent = L;
		L->_right = pParent;
		L->_parent = GrandParent;
		if (pParent == GrandParent->_left)
			GrandParent->_left = L;
		else
			GrandParent->_right = L;

		pParent->bf = 0;
		L->bf = 0;
	}

	// 左单旋
	void RotateL(Node* pParent)
	{
		Node* GrandParent = pParent->_parent;
		Node* R = pParent->_right;
		Node* RL = R->_left;

		if (RL)
		{
			RL->_parent = pParent;
		}
		pParent->_right = RL;
		pParent->_parent = R;
		R->_left = pParent;
		R->_parent = GrandParent;
		if (pParent == GrandParent->_left)
			GrandParent->_left = R;
		else
			GrandParent->_right = R;

		pParent->bf = 0;
		R->bf = 0; 
	}

	// 右左双旋
	void RotateRL(Node* pParent)
	{
 		Node* R = pParent->_right;
		Node* RL = R->_left;

		RotateR(pParent->_right);
		RotateL(pParent);
		if (RL->bf == 0)
		{
			RL->bf = 0;
			pParent->bf = 0;
			R->bf = 0;
		}
		else if(RL->bf == 1)
		{
			RL->bf = 0;
			pParent->bf = 0;
			R->bf = -1;
		}
		else if (RL->bf = -1)
		{
			RL->bf = 0;
			pParent->bf = 1;
			R->bf = 0;
		}
	}

	// 左右双旋
	void RotateLR(Node* pParent)
	{
		Node* L = pParent->_left;
		Node* LR = L->_right;

		RotateL(pParent->_left);
		RotateR(pParent);

		if (LR->bf == 0)
		{
			LR->bf = 0;
			pParent->bf = 0;
			L->bf = 0;
		}
		else if (LR->bf == 1)
		{
			LR->bf = 0;
			pParent->bf = 0;
			L->bf = -1;
		}
		else if (LR->bf = -1)
		{
			LR->bf = 0;
			pParent->bf = 1;
			L->bf = 0;
		}
	}

	//中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_val << ' ';
		_InOrder(root->_right);
	}
private:

	Node* _root;
};