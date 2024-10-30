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

namespace open_adress
{
	enum state
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		state _state;
		HashData(const pair<K, V>& kv = pair<K, V>())
			:_kv(kv)
			,_state(EMPTY)
		{};

	};



	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
			:_num(0)
		{
			_table.resize(10);
		}
		
		bool insert(const pair<K, V>& kv)
		{	
			int size = _table.size();
			size_t hashi = Hash()(kv.first, size);
			while (_table[hashi]._state == EXIST)
			{
				if (_table[hashi]._kv.first == kv.first)
					return false;
				++hashi;
				if (hashi == size)
					hashi = 0;
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_num;

			double bf = (double)_num / _table.size();
			if (bf >= 0.7)//À©ÈÝ
			{
				HashTable<K, V> newtable;
				newtable._table.resize(2*size);
				for (int i = 0; i < size; ++i)
				{
					if (_table[i]._state == EXIST)
					{
						newtable.insert(_table[i]._kv);
					}
				}
				swap(newtable, *this);
			}
			return true;
		}

		HashData<K, V>* Find(const K& key)
		{
			int size = _table.size();
			size_t hashi = Hash(key, size);
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
					return &_table[hashi];
				++hashi;
				if (hashi == size)
					hashi = 0;
			}
			return nullptr;
		}
		bool Erase(const K& key)
		{
			HashData<K, V>* del = Find(key);
			if (del)
			{
				del->_state = DELETE;
				return true;
			}
			return false;
		}

	private:
		vector<HashData<K, V>>_table;
		size_t _num;
	};

};