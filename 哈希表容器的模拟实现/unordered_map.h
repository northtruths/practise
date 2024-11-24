#pragma once
#include"hash_table.h"
using namespace hash_bucket;
namespace nor
{
	template<class K, class V, class HF = HashFunc<K>>
	struct HBIterator
	{
		HBIterator(HashData<K, V>* kv = nullptr, size_t i = 0, HashTable<K, V, HF>& HB = HashTable<K, V, HF>())
			:iterator(kv)
			,hashi(i)
			,table(HB)
		{}
		HBIterator& operator++()
		{
			if (iterator->_next)
				iterator = iterator->_next;
			else
			{
				if (hashi < table.size() - 1)
				{
					for (++hashi; hashi < table.size() - 1; ++hashi)
						if (table[hashi])
							break;
					iterator = table[hashi];
				}
				else
				{
					iterator = nullptr;
				}
			}
			return *this;
		}

		HBIterator operator++(int)
		{
			HBIterator& ret = *this;
			if (iterator->_next)
				iterator = iterator->_next;
			else
			{
				if (hashi < table.size() - 1)
				{
					for (++hashi; hashi < table.size() - 1; ++hashi)
						if (table[hashi])
							break;
					iterator = table[hashi];
				}
				else
				{
					iterator = nullptr;
				}
			}
			return ret;
		}

		V& operator*()
		{
			return this->iterator->_kv.second;
		}
		V* operator->()
		{
			return &(this->iterator->_kv.second);
		}
		bool operator==(const HBIterator& it)
		{
			return this->iterator == it->iterator;
		}
		bool operator!=(const HBIterator& it)
		{
			return this->iterator != it.iterator;
		}

		HashData<K, V>* iterator;
		size_t hashi;
		HashTable<K, V, HF>& table;
	};

	template<class K, class V, class HF = HashFunc<K>>
	class unordered_map
	{
		typedef HBIterator<K, V, HF> iterator;
	public:
		unordered_map()
			:_ht()
		{}
//////////////////////////////////////////////////////////////
		iterator begin()
		{
				int i = 0;
				for (i; i < _ht.size(); ++i)
					if (_ht[i] != nullptr)
						break;
				if (i == _ht.size())
					return iterator(nullptr, 0, _ht);
				else
					return iterator(_ht[i], i, _ht);
		}
		iterator end()
		{
			return iterator(nullptr, 0, _ht);
		}
//////////////////////////////////////////////////////////////
		// capacity
		size_t size()
		{
			return _ht.size();
		}
		bool empty()
		{
			return _ht.num == 0;
		}
//////////////////////////////////////////////////////////////
		//Acess
		V& operator[](const K& key)
		{
			HashData<K, V>* cur = _ht.Find(key);
			if (cur)
			{
				return cur->_kv.second;
			}
			else
			{
				_ht.insert({ key, V() });
				auto it = this->Find(key);
				return *it;
			}
		}
		const V& operator[](const K& key)const
		{
			HashData<K, V>* cur = _ht.Find(key);
			if (cur)
			{
				return cur->_kv.second;
			}
			else
			{
				_ht.insert({ key, V() });
				auto it = this->Find(key);
				return *it;
			}
		}
//////////////////////////////////////////////////////////////
		// lookup
		iterator Find(const K& key)
		{
			size_t hashi = HF()(key, _ht.size());
			auto cur = _ht.Find(key);
			if (cur == nullptr) hashi = 0;
			return iterator(cur, hashi, _ht);
		}
		size_t count(const K& key)
		{
			size_t ret = 0;
			for (auto& e : _ht)
				if (e)
					++ret;
			return ret;
		}
//////////////////////////////////////////////////////////////
		// modify
		pair<iterator, bool> Insert(const pair<K, V> kv)
		{
			bool ret = _ht.insert(kv);
			return { Find(kv.first), ret };
		}
		iterator Erase(iterator position)
		{
			iterator del = position;
			++position;
			_ht.Erase(del.iterator->_kv.first);
			return position;
		}
/////////////////////////////////////////////////////////////
	// bucket
		size_t bucket_count() { return _ht.num(); }
		size_t bucket_size(const K& key)
		{
			size_t ret = 0;
			auto cur = _ht.Find(key);
			while (cur)
			{
				++ret;
				cur = cur->_next;
			}
			return ret;
		}
	private:
		HashTable<K, V, HF> _ht;
	};
}