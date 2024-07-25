//#pragma once
////模拟实现vector类，并完成测试
//#include<assert.h>
//
//using namespace std;
//
//// 将以下代码适配到vector和list中做反向迭代器，理解反向迭代器的原理
//
//namespace bit
//{
//	// 适配器 -- 复用
//template<class iterator, class Ref, class Ptr>
//struct Reverse_iterator
//{
//	iterator _it;
//
//	Ref operator*()
//	{
//		return *_it;
//	}
//	bool operator==(Reverse_iterator<iterator, Ref, Ptr> it)
//	{
//		return _it == it._it;
//	}
//	bool operator!=(Reverse_iterator<iterator, Ref, Ptr> it)
//	{
//		return _it != it._it;
//	}
//	iterator operator++()
//	{
//		return --_it;
//	}
//	iterator operator++(int)
//	{
//		return _it--;
//	}
//	iterator operator--()
//	{
//		return ++_it;
//	}
//	iterator operator--(int)
//	{
//		return _it++;
//	}
//};
//	
//	//iterator<int>
//	template<class T>
//	struct iterator
//	{
//		T* pv = nullptr;
//
//		T& operator*()
//		{
//			return *pv;
//		}
//		iterator operator++()
//		{
//			++(this->pv);
//			return *this;
//		}
//		iterator operator++(int)
//		{
//			iterator temp = *this;
//			++(this->pv);
//			return temp;
//		}
//		iterator operator--()
//		{
//			--(this->pv);
//			return *this;
//		}
//		iterator operator--(int)
//		{
//			iterator temp = *this;
//			--(this->pv);
//			return temp;
//		}
//		iterator operator+=(int i)
//		{
//			(this->pv) += i;
//			return *this;
//		}
//		iterator operator-=(int i)
//		{
//			(this->pv) -= i;
//			return *this;
//		}
//		iterator operator+(int i)
//		{
//			iterator<T> temp;
//			temp.pv = (this->pv) + i;
//			return temp;
//		}
//		iterator operator-(int i)
//		{
//			iterator<T> temp;
//			temp.pv = (this->pv) - i;
//			return temp;
//		}
//		bool operator==(iterator<T> it)
//		{
//			return (*this).pv == it.pv;
//		}
//		bool operator!=(iterator<T> it)
//		{
//			return (*this).pv != it.pv;
//		}
//	};
//	template<class T>
//	class vector
//	{
//	public:
//		T& operator[](int i)
//		{
//			return *(_arr + i);
//		}
//		T operator=(vector<T>& v)
//		{	
//			return v;
//		}
//		iterator<T> begin()
//		{
// 			iterator<T> it_begin;
//			it_begin.pv = _arr;
//			return it_begin;
//		}
//		iterator<T> end()
//		{
//			iterator<T> it_end;
//			it_end.pv = _arr + _size;
//			return it_end;
//		}
//		Reverse_iterator<iterator<T>, T, T*> rbegin()
//		{
//			Reverse_iterator<iterator<T>, T, T*> it_rbegin;
//			it_rbegin._it = this->end() - 1;
//			return it_rbegin;
//		}
//		Reverse_iterator<iterator<T>, T, T*> rend()
//		{
//			Reverse_iterator<iterator<T>, T, T*> it_rend;
//			it_rend._it = this->begin() - 1;
//			return it_rend;
//		}
//
//		vector() = default;
//		vector( vector<T>& v)
//		{
//			_arr = new T[v._capacity];
//			_capacity = v._capacity;
//			for (const auto& e : v)
//			{
//				this->push_back(e);
//			}
//		}
//		~vector()
//		{
//			delete[] _arr;
//		}
//
//
//		void expansion()//扩容，拷贝数据
//		{
//			T* temp = _arr;
//			int new_capacity = _capacity == 0 ? 4 : 2 * _capacity;
//			T* new_arr = new T[new_capacity];
//			for (int i = 0; i < _size; ++i)
//			{
//				new_arr[i] = _arr[i];
//			}
//
//			_capacity = new_capacity;
//			_arr = new_arr;
//			delete[] temp;
//		}
//		void push_back(T x)
//		{
//			if (_size == _capacity)
//			{
//				expansion();
//			}
//
//			*(_arr + _size) = x;
//			++_size;
//		}
//		void pop_back()
//		{
//			assert(!empty());
//			--_size;
//		}
//
//		void reserve(int n)
//		{
//			if (n <= _capacity)
//				return;
//			T* temp = _arr;
//			T* new_arr = new T[n];
//			for (int i = 0; i < _size; ++i)
//			{
//				new_arr = _arr[i];
//			}
//
//			_capacity = n;
//			_arr = new_arr;
//			delete[] temp;
//		}
//
//		void resize(int n)
//		{
//			if (n <= _capacity)
//			{
//				_size = n;
//				return;
//			}
//			else
//			{
//				reserve(n);
//				_size = n;
//			}
//		}
//
//		bool empty()
//		{
//			return _size == 0;
//		}
//		int size()
//		{
//			return _size;
//		}
//		int capacity()
//		{
//			return _capacity;
//		}
//
//
//		iterator<T> insert(iterator<T> pos, const T x)
//		{
//			if (_size == _capacity)
//				expansion();
//			for (auto i = this->end(); i != pos; --i)
//			{
//				*i = *(i - 1);
//			}
//			*pos = x;
//			++_size;
//			return pos;
//		}
//
//		iterator<T> erase(iterator<T> pos)
//		{
//			assert(!empty());
//			iterator<T> ret = pos + 1;
//			for (auto i = pos + 1; i != (*this).end(); ++i)
//			{
//				*(i - 1) = *i;
//			}
//			--_size;
//			return ret;
//		}
//	private:
//		T* _arr = nullptr;
//		int _size = 0;
//		int _capacity = 0;
//	};
//
//}



