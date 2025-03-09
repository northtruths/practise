#pragma once

namespace nor
{
#include<iostream>
	using namespace std;
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _count(new int(1))
		{}

		void Release()
		{
			--(*_count);
			if (*_count == 0)
			{
				cout << "~shared_ptr" << endl;
				delete _ptr;
				delete _count;
			}
		}
		~shared_ptr()
		{
			Release();
		}

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_count(sp._count)
		{
			Add();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != sp._ptr)
			{
				Release();
				_ptr = sp._ptr;
				_count = sp._count;
				++(*_count);
			}
			return *this;
		}
		void Add()
		{
			++(*_count);
		}

		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			return *_ptr;
		}
	private:
		T* _ptr;
		int* _count;
	};
}