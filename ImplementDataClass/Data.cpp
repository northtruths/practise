#define _CRT_SECURE_NO_WARNINGS

#include"Data.h"

Data::Data(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

Data::Data(const Data& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Data& Data::operator=(const Data& d)
{
	if (this == &d)
		return *this;
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Data& Data::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetDay(_year, _month))
	{
		_day -= GetDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Data Data::operator+(int day)
{
	if (day < 0)
	{
		return *this - -day;
	}
	Data d = *this;
	d += day;
	return d;
}

Data& Data::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetDay(_year, _month);
	}
	return *this;
}

Data Data::operator-(int day)
{
	Data d = *this;
	d -= day;
	return d;
}

Data& Data::operator++()
{
	*this += 1;
	return *this;
}
Data Data::operator++(int)
{
	Data temp = *this;
	*this += 1;
	return temp;
}
Data& Data::operator--()
{
	*this -= 1;
	return *this;
}
Data Data::operator--(int)
{
	Data temp = *this;
	*this -= 1;
	return temp;
}

bool Data::operator>(const Data& d) const
{
	if (!(_year > d._year))
	{
		if (_year == d._year)
		{
			if (!(_month > d._month))
			{
				if (_month == d._month)
				{
					return (_day - d._day) > 0;
				}
				else
				return false;
			}
		}
		else
			return false;
	}

	return true;
}
bool Data::operator==(const Data& d) const
{
	return (_year == d._year
		&& _month == d._month
		&& _day == d._day);
}
bool Data::operator>=(const Data& d) const
{
	return *this > d || *this == d;
}
bool Data::operator<(const Data& d) const
{
	return !(*this >= d);
}
bool Data::operator<=(const Data& d) const
{
	return !(*this > d);
}

int Data::operator-(const Data& d) const
{
	int day = 0;
	Data max = *this;
	Data min = d;
	int flag = 1;//为正
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;//为负
	}
	while (!(max == min))
	{
		++min;
		++day;
	}
	return flag * day;
}

void Data::Print()
{
	printf("%d/%d/%d\n", _year, _month, _day);
}