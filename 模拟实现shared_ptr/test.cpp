#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"my_shared_ptr.h"
using namespace std;
using namespace nor;

class Data
{
public:
	Data(int year = 2025, int month = 1, int day = 1)
		:_year(new int(year))
		,_month(new int(month))
		,_day(new int(day))
	{}
	~Data()
	{
		delete _year;
		delete _month;
		delete _day;
	}
	void Print()
	{
		cout << _year << '/' << _month << '/' << _day << endl;
	}
private:
	int* _year;
	int* _month;
	int* _day;
};

int main()
{
	Data* d1 = new Data(2025, 3, 3);
	nor::shared_ptr<Data> p1(d1);
	for (int i = 0; i < 1; ++i)
		nor::shared_ptr<Data> p2(p1);
	return 0;
}