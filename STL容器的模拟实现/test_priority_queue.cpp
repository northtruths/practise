#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"priority_queue.h"
using namespace std;
using namespace bit_priority_queue;

int main()
{
	priority_queue<int> p1;
	p1.push(3);
	p1.push(2);
	p1.push(5);
	p1.push(4);
	p1.push(1);
	while (!p1.empty())
	{
		cout << p1.top() << ' ';
		p1.pop();
	}
	cout << endl;

	return 0;
}