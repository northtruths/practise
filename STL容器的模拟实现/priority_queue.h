#pragma once

#include<vector>
#include<functional>
#include<assert.h>

namespace bit_priority_queue
{


	template<class T, class Container = std::vector<T>, class Compare = std::less<T>>
	class priority_queue
	{
	public:
		void adjust_up()
		{
			int child = _c.size() - 1;
			int parent = (child - 1) / 2;
			while (child > 0 && _compare(_c[parent], _c[child]))
			{
				int temp = _c[parent];
				_c[parent] = _c[child];
				_c[child] = temp;
				child = parent;
				parent = (parent - 1) / 2;
			}
		}
		void adjust_down()
		{
			int parent = 0;
			int child = 0;
			if (parent * 2 + 1 >= _c.size()) return;
			else if (parent * 2 + 2 >= _c.size()) child = parent * 2 + 1;
			else child = _compare(_c[parent * 2 + 1], _c[parent * 2 + 2]) ? parent * 2 + 2 : parent * 2 + 1;
			while(child <= _c.size() && _compare(_c[parent], _c[child]))
			{
				int temp = _c[parent];
				_c[parent] = _c[child];
				_c[child] = temp;
				parent = child;
				if (parent * 2 + 1 >= _c.size()) break;
				else if(parent * 2 + 2 >= _c.size()) child = parent * 2 + 1;
				else child = _compare(_c[parent * 2 + 1], _c[parent * 2 + 2]) ? parent * 2 + 2: parent * 2 + 1;
			}
		}
		priority_queue() = default;
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			for (auto& i = first; i != last; ++i)
			{
				_c.push(*i);
			}
		}
		bool empty()
		{
			return _c.empty();
		}
		size_t size()
		{
			return _c.size();
		}

		T& top()
		{
			return _c.front();
		}

		void push(const T& x)
		{
			_c.push_back(x);
			adjust_up();
		}

		void pop()
		{
			assert(!empty());
			_c[0] = _c[_c.size() - 1];
			_c.pop_back();
			adjust_down();
		}
	private:
		Container _c;
		Compare _compare;
	};
}