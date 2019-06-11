#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

class Character
{
public:
	string valor;
	Character * ant;
	Character();
	Character(string, Character *);
	~Character();
};

#endif // !CHARACTER_H