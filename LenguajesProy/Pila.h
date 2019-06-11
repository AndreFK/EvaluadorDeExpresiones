#pragma once
#ifndef PILA_H
#define PILA_H
#include "Character.h"

using namespace std;

class Pila
{
private:
	Character * top;
public:
	void add(string v);
	void pop(string v);
	void search(string v);

	void addc(Character *);
	void popc(Character *);
	void searchc(Character *);

	Pila();
	Pila(Character *);
	~Pila();
};
#endif // !PILA_H
