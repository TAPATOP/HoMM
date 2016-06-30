#pragma once
#include"Unit.h"
class Peasant:public Unit
{
public:
	Peasant();
	Peasant(int range, int hp, int armor, int attack, int stamina, int price, int count) : Unit(range, hp, armor, attack, stamina, price, count)
	{}

	~Peasant();
};

