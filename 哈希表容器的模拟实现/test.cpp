#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"unordered_map.h"
#include"unordered_set.h"
using namespace nor;

void test1()
{
	unordered_map<int, int> m1;
	m1.Insert({ 1, 5 });
	m1.Insert({ 3, 15 });
	m1.Insert({ 10, 50 });
	m1.Insert({ 2, 10 });
	m1.Insert({ 1, 5 });
	
	for (auto& e : m1)
	{
		cout << e << " ";
	}
	cout << endl;
	auto it = m1.begin();
	for (it; it != m1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	m1.Erase(m1.Find(3));
	for (auto& e : m1)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "10 £º" << m1[10] << endl;

	unordered_map<string, string> m2;
	m2.Insert({ "left", "×ó" });
	m2.Insert({ "right", "ÓÒ" });
	m2.Insert({ "up", "ÉÏ" });
	m2.Insert({ "down", "ÏÂ" });

	cout << m2["up"] << endl;
	m2["up"] = "up_plus";
	cout << m2["up"] << endl;

}

void test2()
{
	unordered_set<string> m1;

}

int main()
{
	test1();
	return 0;
}