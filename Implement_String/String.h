#pragma once
#include<string.h>
#include<iostream>

class string

{

public:
	string(const char* str = "");
	string(const string& s);
	string& operator=(const string& s);
	~string();

	size_t size() const;
	void my_cout() const;

private:

	char* _str;

};