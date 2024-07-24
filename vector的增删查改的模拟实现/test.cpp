#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"vector.h"
using namespace std;
using namespace bit;

void test1()//尾插尾删，[]，迭代器
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	//for (auto i = v1.begin(); i != v1.end(); ++i)
	//{
	//	cout << *i << ' ';
	//}
	//cout << endl;
	//v1.pop_back();
	//v1.pop_back();

	//for (int i = 0; i < v1.size(); ++i)
	//{
	//	cout << v1[i] << ' ';
	//}
	//cout << endl;
	//for (auto i = v1.end() - 1; i != v1.begin() - 1; --i)
	//{
	//	cout << *i << ' ';
	//}
	//cout << endl;
}

void test2()//拷贝构造、赋值
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	cout << "v1:" << &v1 << endl;
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;


	vector<int> v2(v1);
	cout << "v2:" << &v2 << endl;
	for (auto i = v2.begin(); i != v2.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;


	vector<int> v3 = v2;
	cout << "v3:" << &v3 << endl;
	for (auto i = v3.begin(); i != v3.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

void test3()//插入、删除,只实现了插删一个数据的，多个的无非就是多移动多复制几个
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	bit::iterator<int> test = v1.begin() + 2;//在3插入
	v1.insert(test, 0);//1 2 0 3 4 5
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;

	v1.insert(test, 10);//1 2 10 1 3 4 5
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;

	v1.erase(test);
	v1.erase(test);
	//1 2 3 4 5
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

int main()
{
	test3();
	return 0;
}