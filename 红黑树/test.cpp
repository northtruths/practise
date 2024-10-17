#define _CRT_SECURE_NO_WARNINGS

#include"RBTree.h"
using namespace nor;

void test1()
{
	RBTree<int> t1;
	int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int arr2[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (int e : arr1)
	{
		if (e == 14)
			int a = 0;
		t1.Insert(e);
	}
	cout << t1.Rotate_num << endl; 
	if (t1.IsValidRBTRee())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	t1.InOrder();
	cout << endl;

}

int main()
{
	test1();
	return 0;
}