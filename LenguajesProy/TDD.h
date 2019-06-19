#pragma once
#ifndef TDD_H_INCLUDED
#define TDD_H_INCLUDED

#include <string>
#include <iostream>

#include "Parser.h"

using namespace std;

class TDD
{
private:
	string test0 = "3+2";
	string test1 = "(1-2)*1";
	string test2 = "(4+4)%4";
	string test3 = "[(1+2)*(1+2)]^2";
	string test4 = "(1+3)^[3+(8-3/1)%2]";
public:
	TDD() = default; //Feature de c++ 11 -> default en un constructor
	bool test();
	~TDD();
};

#endif // !TDD_H_INCLUDED