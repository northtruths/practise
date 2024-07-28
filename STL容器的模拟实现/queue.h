#pragma once
#include<deque>

//queue.h
namespace bit_queue
{
	template<class T, class Container = std::deque<T>>
	class queue
	{
	public:
		queue()
		{

		}

		auto begin()
		{
			return _c.begin();
		}
		
		auto end()
		{
			return _c.end();
		}

		T& front()
		{
			return _c.front();
		}

		T& back()
		{
			
			return _c.back();
		}

		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			_c.pop_front();
		}

		bool empty()
		{
			return _c.size() == 0;
		}
		size_t size()
		{
			return _c.size();
		}
	private:
		Container _c;
	};
}
