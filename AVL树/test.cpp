#define _CRT_SECURE_NO_WARNINGS

#include"AVL.h"


//void test1()
//{
//	AVLTree<int> t1;
//	t1.Insert(3);
//	t1.Insert(7);
//	t1.Insert(1);
//	t1.Insert(6);
//	t1.Insert(3);
//	if (t1.IsALVTree())
//		cout << "yes" << endl;
//	else
//		cout << "no" << endl;
//	t1.InOrder();
//}

void test2()
{
	AVLTree<int> t1;
	t1.Insert(60);
	t1.Insert(30);
	t1.Insert(70);
	t1.Insert(10);
	t1.Insert(35);

	cout << t1.Height() << endl;//3
	if (t1.IsALVTree())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	t1.InOrder();
	cout << endl;

	t1.Insert(50);
	cout << t1.Height() << endl;//3
	if (t1.IsALVTree())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	t1.InOrder();
	cout << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}