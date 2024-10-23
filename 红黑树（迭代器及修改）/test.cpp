#define _CRT_SECURE_NO_WARNINGS

#include"RBTree.h"
using namespace nor;

void test1()
{
	RBTree<int> t1;
	//int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr2[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int e : arr2)
	{
		if (e == 14)
			int a = 0;
		t1.Insert(e);
	}
	auto it = t1.begin();
	for (it; it != t1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	auto it1 = --t1.end();
	for (it1; it1 != t1.end(); --it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;
}

int main()
{
	test1();
	return 0;
}