#pragma once
#include<stdio.h>

class Data
{
public:
	int GetDay(int year, int month)
	{
		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		{
			return 28;
		}
		else
		{
			return arr[month];
		}
	}

	Data(int year = 1, int month = 1, int day = 1);//构造
	Data(const Data& d);//拷贝构造
	Data& operator=(const Data& d);//赋值重载

	//日期类的加减和比较
	//加减天数
	Data& operator+=(int day);
	Data operator+(int day);
	Data& operator-=(int day);
	Data operator-(int day);
	//自增自减(前置后置)
	Data& operator++();
	Data operator++(int);
	Data& operator--();
	Data operator--(int);
	//比较
	bool operator>(const Data& d) const;
	bool operator>=(const Data& d) const;
	bool operator==(const Data& d) const;
	bool operator<(const Data& d) const;
	bool operator<=(const Data& d) const;
	//日期相减差，天数
	int operator-(const Data& d) const;
	void Print();
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};