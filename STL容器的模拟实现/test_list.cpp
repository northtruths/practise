//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include"list.h"
//using namespace std;
//using namespace bit_list;
//
//void test1()//list的增删查改
//{
//	list<int> l1(5, 1);
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	l1.push_back(2);
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	l1.push_front(3);
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	l1.pop_back();
//	l1.pop_front();
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//}
//
//void test2()//取数据
//{
//	list<int> l1;
//	int i = 5;
//	while (i--)
//	{
//		l1.push_back(i);//54321
//	}
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//	cout << l1.front() << endl;//4
//	cout << l1.back() << endl;//0
//	++l1.front();
//	++l1.back();
//	cout << l1.front() << endl;//5
//	cout << l1.back() << endl;//1
//
//	const int& a = l1.front();
//	cout << a << endl;
//	int& b = l1.front();
//	++b;
//}
//
//void test3()//迭代器构造、拷贝构造、赋值构造
//{
//	list<int> l1;
//	int i = 5;
//	while (i--)
//	{
//		l1.push_back(i);//54321
//	}
//	cout << &l1 << "l1 : ";
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	list<int> l2(l1.begin(), l1.end());
//	cout << &l1 << "l2 : ";
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	list<int> l3(l2);
//	cout << &l1 << "l3 : ";
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//	list<int> l4 = l3;
//	cout << &l1 << "l4 : ";
//	for (auto& e : l1)
//	{
//		cout << e << ' ';
//	}
//	cout << endl;
//
//}
//
//
//
//int main()
//{
//
//	return 0;
//}