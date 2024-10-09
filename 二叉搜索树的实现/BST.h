#pragma once

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode* left;
	BSTreeNode* right;
	K _key;
	V _value;
};

template<class K, class V>
class BSTree
{
public:
	typedef BSTreeNode<K, V> Node;

	BSTree()
	{
		_head = nullptr;
	}

	BSTree(BSTree& t)
	{
		//先序遍历，挨个复制

	}


	Node* Find(K& key)
	{
		Node* cur = _head;
		while (cur)
		{
			if (key == cur->_key)
			{
				return cur;
			}
			else if (key < cur->_key)
			{
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}
		return nullptr;
	}


	bool Insert(const K& key, const V& value)
	{
		Node* n = new Node;
		n->_key = key;
		n->_value = value;
		n->left = nullptr;
		n->right = nullptr;
		Node* cur = _head;
		if (cur == nullptr)
		{
			_head = n;
			return true;
		}
		while (cur)
		{
			if (key < cur->_key)
			{
				if (cur->left == nullptr)
				{
					cur->left = n;
					return true;
				}
				else
				{
					cur = cur->left;
				}
			}
			else if (key > cur->_key)
			{
				if (cur->right == nullptr)
				{
					cur->right = n;
					return true;
				}
				else
				{
					cur = cur->right;
				}
			}
			else
				return false;
		}
		assert(1);
	}

	Node* FindMin(Node* root)
	{
		root = root->right;
		while (root->left)
			root = root->left;
		return root;
	}

	bool Erase(K& key)
	{
		Node* cur =	_head;
		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->left;
			}
			else if (key > cur->_key)
			{
				cur = cur->right;
			}
			else
			{
				break;
			}
		}
		
		Node* erase = FindMin(cur);
		cur->_key = erase->_key;
		cur->_value = erase->_value;
		delete erase;
		erase = nullptr;
	}

	void InOrder()
	{
		_InOrder(_head);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->left);
		cout << root->_value << endl;
		_InOrder(root->right);
	}

private:
	Node* _head = nullptr;
};
