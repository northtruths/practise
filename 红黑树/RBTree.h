#pragma once


#include<assert.h>
#include<iostream>
using namespace std;

namespace nor
{
	enum color		//�ڵ����ɫ
	{
		RED,
		BLACK
	};
	enum direction		//����ڵ�ķ���
	{
		LEFT,
		RIGHT
	};
	template<class T>
	struct RBTreeNode
	{
		typedef RBTreeNode<T> Node;

		RBTreeNode(const T& data = T())
			:_parent(nullptr)
			,_left(nullptr)
			,_right(nullptr)
			,_data(data)
			,col(RED)
		{}

		Node* _parent;
		Node* _left;
		Node* _right;
		color col;
		T _data;
	};

	// Ϊ�˺����װmap��set����ʵ��ʱ���������������һ��ͷ���
	template<class T>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:

		RBTree()
		{
			_phead = new Node;
			_phead->_parent = nullptr;
			_phead->_left = nullptr;
			_phead->_right = nullptr;
		}
		
		bool Insert(T& data)
		{
			Node* cur = _Insert(data);
			if (cur == nullptr)//���в���ֵ������ʧ��
			{
				return false;
			}
			//�������Ľڵ�������߻����ұߣ�����Ҫ����ͷ�ڵ������,���Ҳ����Ƿ���ת������ڵ㻹�ǻ�����������/����
			//ͷ�ڵ�ĸ��׽ڵ�ĸ���Ҫ����ת�����н���
			if (cur == _phead->_right->_right)
			{
				_phead->_right = cur;
			}
			if (cur == _phead->_left->_left)
			{
				_phead->_left = cur;
			}
			while(cur->_parent != _phead)
			{
				Node* parent = cur->_parent;
				if (parent->col == RED)
				{
					Node* grandparent = parent->_parent;
					direction dir = parent == grandparent->_left ? RIGHT : LEFT;
					if (dir == LEFT && grandparent->_left && grandparent->_left->col == RED)
					{
						Node* uncle = grandparent->_left;
						parent->col = BLACK;
						uncle->col = BLACK;
						grandparent->col = RED;

						cur = grandparent;
					}
					else if (dir == RIGHT && grandparent->_right && grandparent->_right->col == RED)
					{
						Node* uncle = grandparent->_right;
						parent->col = BLACK;
						uncle->col = BLACK;
						grandparent->col = RED;

						cur = grandparent;
					}
					else if (grandparent->_left == nullptr || (dir == LEFT && grandparent->_left->col == BLACK))
					{
						if (cur == parent->_right)
						{
							RotateL(parent);
							break;
						}
						else
						{
							RotateRL(parent);
							break;
						}
					}
					else if (grandparent->_right == nullptr || (dir == RIGHT && grandparent->_right->col == BLACK))
					{
						if (cur == parent->_left)
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
						assert(1);
					}
				}
				else
				{
					break;
				}
			}
			Node* root = GetRoot();
			root->col = BLACK;

			return true;
		}

		Node* Find(const T& data)
		{
			return _Find(data, GetRoot());
		}
		// ��ȡ����������ڵ�
		Node* LeftMost()
		{
			Node* ret = GetRoot();
			while (ret->_left)
			{
				ret = ret->_left;
			}
			return ret;
		}

		// ��ȡ��������Ҳ�ڵ�
		Node* RightMost()
		{
			Node* ret = GetRoot();
			while (ret->_right)
			{
				ret = ret->_right;
			}
			return ret;
		}


		// ��������Ƿ�Ϊ��Ч�ĺ������ע�⣺���ڲ���Ҫ����_IsValidRBTRee�������
		bool IsValidRBTRee()
		{
			size_t pathBlack = 0;
			Node* temp = GetRoot();

			do
			{
				if (temp->col == BLACK)
					++pathBlack;
				temp = temp->_right;
			} while (temp->_right);
			if (temp->col == BLACK)
				++pathBlack;

			return _IsValidRBTRee(GetRoot(), 0, pathBlack);
		}

		void InOrder()
		{
			_InOrder(GetRoot());
		}
	private:
		bool _IsValidRBTRee(Node* pRoot, size_t blackCount, size_t pathBlack)
		{
			if (pRoot == nullptr)
				return true;
			if (pRoot->col == BLACK)
				++blackCount;
			if (pRoot->_left == nullptr || pRoot->_right == nullptr)
			{
				if (blackCount != pathBlack)
					return false;
			}
			return _IsValidRBTRee(pRoot->_left, blackCount, pathBlack) && _IsValidRBTRee(pRoot->_right, blackCount, pathBlack);
		}
		Node* _Find(const T& data, Node* root)
		{
			if (root->_data == data)
				return root;
			if (root == nullptr)
				return nullptr;
			return _Find(data, root->_left) || _Find(data, root->_right);
		}

		Node* _Insert(const T& data)
		{
			Node* newnode = new Node(data);
			Node* cur = GetRoot();
			if (cur == nullptr)
			{
				_phead->_left = newnode;
				_phead->_right = newnode;
				_phead->_parent = newnode;
				newnode->_parent = _phead;
				newnode->col = BLACK;
				return newnode;
			}
			while (cur)
			{
				if (data < cur->_data)
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
				else if (data > cur->_data)
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
		void RotateL(Node* parent)
		{		
			Node* grandparent = parent->_parent;

			if (grandparent == GetRoot())
			{
				_phead->_parent = grandparent->_right;
			}

			if (parent->_left)
			{
				parent->_left->_parent = grandparent;
				grandparent->_right = parent->_left;
				parent->_left = grandparent;
				parent->_parent = grandparent->_parent;
				if (grandparent == grandparent->_parent->_left)
					grandparent->_parent->_left = parent;
				else
					grandparent->_parent->_right = parent;
				grandparent->_parent = parent;
			}
			else
			{
				parent->_left = grandparent;
				parent->_parent = grandparent->_parent;
				if (grandparent == grandparent->_parent->_left)
					grandparent->_parent->_left = parent;
				else
					grandparent->_parent->_right = parent;
				grandparent->_parent = parent;
				grandparent->_right= nullptr;
			} 
			grandparent->col = RED;
			++Rotate_num;
		}
		void RotateR(Node* parent)
		{
			Node* grandparent = parent->_parent;

			if (grandparent == GetRoot())
			{
				_phead->_parent = grandparent->_left;
			}

			if (parent->_right)
			{
				parent->_right->_parent = grandparent;
				grandparent->_left = parent->_right;
				parent->_right = grandparent;
				parent->_parent = grandparent->_parent;
				if (grandparent == grandparent->_parent->_left)
					grandparent->_parent->_left = parent;
				else
					grandparent->_parent->_right = parent;
				grandparent->_parent = parent;
			}
			else
			{
				parent->_right = grandparent;
				parent->_parent = grandparent->_parent;
				if (grandparent == grandparent->_parent->_left)
					grandparent->_parent->_left = parent;
				else
					grandparent->_parent->_right = parent;
				grandparent->_parent = parent;
				grandparent->_left = nullptr;
			}

			parent->col = BLACK;
			grandparent->col = RED;

			++Rotate_num;
		}

		void RotateRL(Node* parent)
		{
			Node* cur = parent->_left;
			Node* grandparent = parent->_parent;
			RotateR(cur);
			RotateL(cur);
			grandparent->col = RED;
			cur->col = BLACK;
		}
		void RotateLR(Node* parent)
		{
			Node* cur = parent->_right;
			Node* grandparent = parent->_parent;
			RotateL(cur);
			RotateR(cur);
			grandparent->col = RED;
			cur->col = BLACK;
		}
		//��ȡ���ڵ�
		Node* GetRoot()
		{
			if (_phead->_parent == _phead)
				return nullptr;
			else
				return _phead->_parent;
		}
		//�������
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_data << ' ';
			_InOrder(root->_right);
		}

	private:
		Node* _phead;
		public:
		int Rotate_num = 0;
	};
}
