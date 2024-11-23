#pragma once
#include"hash_table.h"
using namespace hash_bucket;
namespace nor
{
	template<class K, class HF = HashFunc<K>>
	struct HBIterator
	{
		HBIterator(HashData<K, K>* kv = nullptr, size_t i = 0, HashTable<K, K, HF>& HB = HashTable<K, K, HF>())
			:iterator(kv)
			, hashi(i)
			, table(HB)
		{}
		HBIterator& operator++()
		{
			if (iterator->_next)
				iterator = iterator->_next;
			else
			{
				for (++hashi; hashi < table.size() - 1; ++hashi)
					if (table[hashi])
						break;
				iterator = table[hashi];
			}
			return *this;
		}

		HBIterator& operator++(int)
		{
			HBIterator& ret = *this;
			if (iterator->_next)
				iterator = iterator->_next;
			else
			{
				for (hashi + 1; hashi < table.size() - 1; ++hashi)
					if (table[hashi])
						break;
				iterator = table[hashi];
			}
			return ret;
		}

		K& operator*()
		{
			return this->iterator->_kK.second;
		}
		K* operator->()
		{
			&(this->iterator->_kv.second);
		}
		bool operator==(const HBIterator& it)
		{
			return this->iterator == it->iterator;
		}
		bool operator!=(const HBIterator& it)
		{
			return this->iterator != it.iterator;
		}

		HashData<K, K>* iterator;
		size_t hashi;
		HashTable<K, K, HF>& table;
	};

	template<class K, class HF = HashFunc<K>>
	class unordered_set
	{
		typedef HBIterator<K,HF> iterator;
	public:
		unordered_set()
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
		K& operator[](const K& key)
		{
			HashData<K, K>* cur = _ht.Find(key);
			if (cur)
			{
				return cur->_kv.second;
			}
			else
			{
				_ht.insert({ key, K() });
				auto it = this->Find(key);
				return *it;
			}
		}
		const K& operator[](const K& key)const
		{
			HashData<K, K>* cur = _ht.Find(key);
			if (cur)
			{
				return cur->_kv.second;
			}
			else
			{
				_ht.insert({ key, K() });
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
		pair<iterator, bool> Insert(const pair<K, K> kv)
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
		HashTable<K, K, HF> _ht;
	};
}

