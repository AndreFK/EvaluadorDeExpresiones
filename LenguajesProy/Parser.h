#pragma once
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Parser
{
private:
	
	vector<string> result;
	stack<string> stak;
public:
	vector<string> digitos;
	vector<string> simbolos;
	vector<string> words;

	void buildCommand(string cmd);

	void printWords();
	void execute(string cmd);

	bool checkF(string word);
	bool checkS(string word);
	bool checkO(string word);
	bool checkD(string word);
	bool checkPC(string word);
	bool firstnum(string word);
	[[nodiscard]] bool checkAll(string word); //Feature de c++ 17 -> [[nodiscard]]

	void buildPost(vector<string> word);
	void divideNegative();

	int answer(vector<string> result);
	int precedence(string s);

	void loop();
	Parser();
	~Parser();
};

#endif // !PARSER_H_INCLUDED