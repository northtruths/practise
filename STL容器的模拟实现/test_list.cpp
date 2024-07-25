#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"list.h"
using namespace std;
using namespace bit;


void test1()//list的增删查改
{
	list<int> l1(5, 1);
	for (auto& e : l1)
	{
		cout << e << ' ';
	}
	cout << endl;

	l1.push_back(2);
	for (auto& e : l1)
	{
		cout << e << ' ';
	}
	cout << endl;

	l1.push_front(3);
	for (auto& e : l1)
	{
		cout << e << ' ';
	}
	cout << endl;

	l1.pop_back();
	l1.pop_front();
	for (auto& e : l1)
	{
		cout << e << ' ';
	}
	cout << endl;
}

int main()
{
	test1();
	return 0;
}