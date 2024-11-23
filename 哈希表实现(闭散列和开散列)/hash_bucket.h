#pragma once
#include<utility>
#include<vector>
#include<string>
using namespace std;


template<class K>
struct HashFunc
{
	size_t operator()(const K& key = K(), size_t size = size_t())
	{
		return (size_t)key % size;
	}
};

template<>
struct HashFunc<string>
{
	size_t operator()(const string& key = string(), size_t size = size_t())
	{
		int i = 0;
		for (char e : key)
		{
			i = (i + e) * 31;
		}
		return i % size;
	}
};

namespace hash_bucket
{
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		HashData* _next;
		HashData(const pair<K, V>& kv = pair<K, V>())
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_num(0)
			,_table(3, nullptr)
		{}
		~HashTable()
		{
			int size = _table.size();
			for (int i = 0; i < size; ++i)
			{
				if (_table[i])
					delete _table[i];
			}
		}


		bool insert(const pair<K, V>& kv)
		{
			int size = _table.size();
			size_t hashi = Hash()(kv.first, size);
			HashData<K, V>* newdata = new  HashData<K, V>(kv);
			if (_table[hashi])
			{
				HashData<K, V>* cur = _table[hashi];
				if (cur->_kv.first == kv.first)
					return false;
				while (cur->_next)
				{
					if (cur->_kv.first == kv.first)
						return false;
					cur = cur->_next;
				}
				cur->_next = newdata;
			}
			else
			{
				_table[hashi] = newdata;
			}
			++_num;
			double bf = (double)_num / size;
			if (bf == 1)//À©ÈÝ
			{
				vector<HashData<K, V>*> newtable(2 * size, nullptr);
				for (int i = 0; i < size; ++i)
				{
					if (_table[i] == nullptr)
						continue;
					HashData<K, V>* cur = _table[i];
					HashData<K, V>* pre = nullptr;
					while (cur)
					{
						size_t newhashi = Hash()(cur->_kv.first, 2 * size);
						pre = cur;
						cur = cur->_next;
						if (newtable[newhashi])
						{
							pre->_next = newtable[newhashi];
						}
						else
						{
							pre -> _next = nullptr;
						}
						newtable[newhashi] = pre;
					}
					_table[i] = nullptr;
				}
				swap(_table, newtable);//×¢
			}
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			int size = _table.size();
			size_t hashi = Hash()(key, size);
			HashData<K, V>* cur = _table[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			int size = _table.size();
			size_t hashi = Hash()(key, size);
			HashData<K, V>* pre_del = nullptr;
			HashData<K, V>* del = _table[hashi];
			while (del)
			{
				if (del->_kv.first == key)
				{
					if (pre_del)
					{
						pre_del->_next = del->_next;
					}
					else
					{
						_table[hashi] = del->_next;
					}
					delete del;
					return true;
				}
				pre_del = del;
				del = del->_next;
			}
			return false;
		}
	private:
		vector<HashData<K, V>*> _table;
		size_t _num;
	};
}
