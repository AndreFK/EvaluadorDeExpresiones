#include "stdafx.h"
#include "Pila.h"

void Pila::add(string v) {
	Character * n = new Character;
	n->valor = v;
	addc(n);
}

void Pila::addc(Character * n) {
	if (top == nullptr) {
		this->top = n;
		n->ant = nullptr;
	}
	else {
		n->ant = top;
		this->top = n;
	}
}

Pila::Pila(Character * n) {
	this->top = n;
}

Pila::Pila()
{
	this->top = nullptr;
}


Pila::~Pila()
{
}
