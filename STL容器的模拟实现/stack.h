#pragma once

#include<deque>
namespace bit_stack
{

	template<class T, class Container = std::deque<T>>
	class stack
	{
    public:

        stack()
        {
            
        }

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_back();
        }

        T& top()
        {
            return _c.back();
        }

        const T& top()const
        {
            return _c.back();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.size() == 0;
        }

        auto begin()
        {
            return _c.begin();
        }

        auto end()
        {
            return _c.end();
        }
    private:

        Container _c;
	};
}