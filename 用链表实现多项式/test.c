#define _CRT_SECURE_NO_WARNINGS

#include"poly.h"

int main()
{
	int n1 = 0;
	node* p1 = ListCreat(&n1);
	//ListPrint(p1);
	ListSort(p1, n1);
	//ListPrint(p1);
	int n2 = 0;
	node* p2 = ListCreat(&n2);
	node* ret = ListAdd(p1, p2, n1, n2);
	ListPrint(ret);
	return 0;
}