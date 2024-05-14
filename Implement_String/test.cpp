#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

int main()
{
	string s1("666666");
	s1.my_cout();//666666
	string s2(s1);
	s2.my_cout();//666666
	string s3("777");
	s3.my_cout();//777
	s3 = s1;
	s3.my_cout();//666666
	return 0;
}