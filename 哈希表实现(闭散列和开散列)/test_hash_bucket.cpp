#define _CRT_SECURE_NO_WARNINGS
#include"hash_bucket.h"
#include<iostream>
using namespace hash_bucket;

void test1()
{
	HashTable<int, int> h1;
	h1.insert({ 0, 0 });
	h1.insert({ 10, 10 });
	h1.insert({ 100, 100 });
	h1.insert({ 1000, 1000 });
	h1.insert({ 20, 20 });
}

void test2()
{
	HashTable<string, string> h1;
	h1.insert({ "left", "左" });
	h1.insert({ "right", "右" });
	h1.insert({ "up", "上" });
	h1.insert({ "down", "下" });
	h1.insert({ "abc", "abc" });
	h1.insert({ "acb", "acb" });
	h1.insert({ "cba", "cba" });

	cout << "left:" << h1.Find("left")->_kv.second << endl;
	cout << "abc:" << h1.Find("abc")->_kv.second << endl;
	
	if (h1.Find("up"))
	{
		cout << "up:" << h1.Find("up")->_kv.second << endl;
		h1.Erase("up");
	}
	else cout << "up不存在" << endl;
	if (h1.Find("up"))
	{
		cout << h1.Find("up")->_kv.second << endl;
		h1.Erase("up");
	}
	else cout <<"up不存在" << endl;
}
int main()
{
	//test1();
	test2();
	return 0;
}