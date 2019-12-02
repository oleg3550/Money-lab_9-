#pragma once
#ifndef _MY_EXCEPTION__defined_
#define _MY_EXCEPTION__defined_
#include <exception>
using namespace std;
class my_exception : public exception {
public:
	my_exception(const char* msg) : exception(msg)
	{   }
	my_exception(const my_exception& right) : exception(right)
	{   }
};
#endif
