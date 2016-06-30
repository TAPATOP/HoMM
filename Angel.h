#pragma once
#include"Unit.h"
class Angel:public Unit
{
public:
	Angel();
	Angel(int range, int hp, int armor, int attack, int stamina, int price, int count) : Unit(range, hp, armor, attack, stamina, price, count)
	{

	}

	~Angel();
	virtual bool die(int);
	virtual void takeDamage(int, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);
};

