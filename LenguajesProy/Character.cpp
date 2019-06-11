#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	this->valor = "";
	this->ant = nullptr;
}

Character::Character(string v, Character * a) {
	this->valor = v;
	this->ant = a;
}

Character::~Character()
{
}
