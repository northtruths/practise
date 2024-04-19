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

	Data(int year = 1, int month = 1, int day = 1);//����
	Data(const Data& d);//��������
	Data& operator=(const Data& d);//��ֵ����

	//������ļӼ��ͱȽ�
	//�Ӽ�����
	Data& operator+=(int day);
	Data operator+(int day);
	Data& operator-=(int day);
	Data operator-(int day);
	//�����Լ�(ǰ�ú���)
	Data& operator++();
	Data operator++(int);
	Data& operator--();
	Data operator--(int);
	//�Ƚ�
	bool operator>(const Data& d) const;
	bool operator>=(const Data& d) const;
	bool operator==(const Data& d) const;
	bool operator<(const Data& d) const;
	bool operator<=(const Data& d) const;
	//������������
	int operator-(const Data& d) const;
	void Print();
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};