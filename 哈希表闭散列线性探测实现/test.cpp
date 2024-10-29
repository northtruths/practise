#define _CRT_SECURE_NO_WARNINGS

#include"hash_open_address.h"
#include<iostream>

using namespace std;
using namespace open_adress;

void test1()
{
	HashTable<int, char> h1;
	h1.insert(make_pair(65, (char)65));
	h1.insert(make_pair(67, (char)67));
	h1.insert(make_pair(67, (char)67));
	h1.insert(make_pair(122, (char)122));
	int a = 0;

	HashTable<int, int> h2;
	h2.insert({0, 0});
	h2.insert({ 10, 10 });
	h2.insert({ 100, 100 });
	h2.insert({ 1000, 1000 });
	h2.insert({ 10000, 10000 });
	h2.insert({ 100000, 100000 });
	h2.insert({ 1000000, 1000000 });
	h2.insert({ 20, 20 });

}

void test2()
{
	HashTable<string, string> h1;
	h1.insert({ "left", "×ó" });
	h1.insert({ "right", "ÓÒ" });
	h1.insert({ "up", "ÉÏ" });
	h1.insert({ "down", "ÏÂ" });
	h1.insert({ "abc", "abc" });
	h1.insert({ "acb", "acb" });

}

int main()
{

	//test1();
	test2();
	return 0;
}