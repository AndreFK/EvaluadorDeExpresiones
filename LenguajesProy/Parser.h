#pragma once
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include "TDD.h"
using namespace std;

class Parser
{
private:
	vector<string> result;
	stack<string> stak;

	auto checkF(string word) -> bool; //Feature de c++ 14 -> auto en una funcion
	bool checkS(string word);
	bool checkO(string word);
	bool checkD(string word);
	bool checkPC(string word);

public:
	vector<string> digitos;
	vector<string> simbolos;
	vector<string> words;

	void buildCommand(string cmd);

	void printWords();
	void printPost();

	void execute(string cmd);


	[[maybe_unused]]bool firstnum(string word);//Feature de c++ 17 -> [[maybe_unused]]
	[[nodiscard]] bool checkAll(string word); //Feature de c++ 17 -> [[nodiscard]]

	void buildPost(vector<string> word);

	float answer();
	int precedence(string s);

	void loop();
	Parser();
	~Parser();
};

#endif // !PARSER_H_INCLUDED