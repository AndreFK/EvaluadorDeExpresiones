#pragma once
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Parser
{
private:
	vector<string> result;
	vector<string> stack;
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
	bool checkAll(string word);

	void buildPost(vector<string> word);

	int answer(vector<string> result);

	void loop();
	Parser();
	~Parser();
};

#endif // !PARSER_H_INCLUDED