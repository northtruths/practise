#pragma once

namespace bit
{
	template<class T = int()>
	struct ListNode
	{
		ListNode() = default;
		ListNode(const T& val)
		{
			_val = val;
		}
		T _val;
		ListNode* _next;
		ListNode* _prev;
	};

	template<class T>
	struct iterator
	{
		ListNode<T>* _node;
		iterator() = default;
		iterator(ListNode<T>* node)
		{
			_node = node;
		}

		T& operator*()
		{
			return _node->_val;
		}
		iterator<T> operator=(iterator<T> it)
		{
			_node = it._node;
			return *this;
		}
		iterator<T> operator++()
		{
			_node = _node->_next;
			return *this;
		}
		iterator<T> operator++(int)
		{
			iterator& temp = *this;
			_node = _node->_next;
			return temp;
		}
		iterator<T> operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		iterator<T> operator--(int)
		{
			iterator& temp = *this;
			_node = _node->_prev;
			return temp;
		}
		bool operator==(iterator<T> it)
		{
			return _node == it._node;
		}
		bool operator!=(iterator<T> it)
		{
			return _node != it._node;
		}
	};

	// 适配器 -- 复用
	template<class iterator, class Ref, class Ptr>
	struct Reverse_iterator
	{
		iterator _it;

		Ref operator*()
		{
			return *_it;
		}
		bool operator==(Reverse_iterator<iterator, Ref, Ptr> it)
		{
			return _it == it._it;
		}
		bool operator!=(Reverse_iterator<iterator, Ref, Ptr> it)
		{
			return _it != it._it;
		}
		iterator operator++()
		{
			return --_it;
		}
		iterator operator++(int)
		{
			return _it--;
		}
		iterator operator--()
		{
			return ++_it;
		}
		iterator operator--(int)
		{
			return _it++;
		}
	};

	template<class T>
	class list
	{
	public:
		////////////////////////////////////////////////////////////////////////////////////////////
		//list的构造
		list()
		{
			Headcreate();
		}
		list(int n, const T& val = T())
		{
			Headcreate();
			ListNode<T>* pre = _head;
			ListNode<T>* cur = _head;
			_size = n;
			while (n--)
			{
				cur = new ListNode<T>(val);
				_head->_prev = cur;
				pre->_next = cur;
				cur->_prev = pre;
				cur->_next = _head;
				pre = cur;
			}
		}

		~list()
		{
			iterator<T> cur(_head->_next);
			iterator<T> next(_head->_next->_next);
			while (next != this->end()) 
			{
				delete cur._node;
				cur = next;
				++next;
			}

		}
		
		////////////////////////////////////////////////////////////////////////////////////////////
		// List Iterator
		iterator<T> begin()
		{
			iterator<T> ret;
			ret._node = _head->_next;
			return ret;
		}
		iterator<T> end()
		{
			iterator<T> ret;
			ret._node = _head;
			return ret;
		}
		Reverse_iterator<iterator<T>, T, T*> rbegin()
		{
			Reverse_iterator<iterator<T>, T, T*> ret;
			ret._it = --end();
			return ret;
		}
		Reverse_iterator<iterator<T>, T, T*> rend()
		{
			Reverse_iterator<iterator<T>, T, T*> ret;
			ret._it = --begin();
			return ret;
		}
		////////////////////////////////////////////////////////////////////////////////////////////
		// List Capacity
		int  size()
		{
			return _size;
		}
		bool empty()
		{
			return _size == 0;
		}

		////////////////////////////////////////////////////////////////////////////////////////////
		// List Access


		////////////////////////////////////////////////////////////////////////////////////////////
		// List Modify
		iterator<T> insert(iterator<T> pos, const T& val)
		{
			ListNode<T>* new_node = new ListNode<T>(val);
			pos._node->_prev->_next = new_node;
			new_node->_prev = pos._node->_prev;
			new_node->_next = pos._node;
			pos._node->_prev = new_node;
			return --pos;
		}

		iterator<T> erase(iterator<T> pos)
		{
			iterator<T> ret;
			ret._node = pos._node->_next;
			pos._node->_prev->_next = pos._node->_next;
			pos._node->_next->_prev = pos._node->_prev;
			delete pos._node;
			return ret;
		}

		void push_back(const T& x)
		{
			insert(this->end(), x);
		}
		void pop_back()
		{
			erase(--(this->end()));
		}

		void push_front(const T& x)
		{
			insert(this->begin(), x);
		}
		void pop_front()
		{
			erase(this->begin());
		}
	private:
		ListNode<T>* _head;
		int _size = 0;


		void Headcreate()
		{
			_head = new ListNode<T>();
			_head->_next = _head;
			_head->_prev = _head;
		}
	};

};