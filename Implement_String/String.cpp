#define _CRT_SECURE_NO_WARNINGS

#include"String.h"

size_t string:: size() const
{
	return strlen(_str) + 1;
}
string::string(const char* str)
{
	_str = new char[strlen(str) + 1];
	strcpy(_str, str);
}
string::string(const string& s)
{
	_str = new char[strlen(s._str) + 1];
	strcpy(_str, s._str);
}
string& string::operator=(const string& s)
{
	char* temp = new char[strlen(s._str) + 1];
	delete[] _str;
	_str = temp;
	strcpy(_str, s._str);
	return *this;
}

string::~string()
{
	delete[] _str;
	_str = nullptr;
}

void string::my_cout() const
{
	std::cout << _str << std::endl;
}