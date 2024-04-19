#define _CRT_SECURE_NO_WARNINGS

#include"Data.h"

int main()
{
	Data d1(2024, 4, 19);
	Data d2 = d1 + 10;
	d1.Print();
	d2.Print();
	
	d1 -= 10;//2024 4 9
	d1.Print();
	d1 += -10;//2024 3 30
	d1.Print();

	if (d1 <= d2)
	{
		d1 += 30;//2024 4 29
	}
	d1.Print();
	if (d1 <= d2)
	{
		d1 += 30;//2024 5 29
	}
	d1.Print();

	printf("%d\n", d1 - d2);//30
	printf("%d\n", d2 - d1);//-30
	return 0;
}