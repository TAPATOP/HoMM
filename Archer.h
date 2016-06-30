#pragma once
#include"Unit.h"
class Archer:public Unit
{
public:
	Archer();
	Archer(int range, int hp, int armor, int attack, int stamina, int price, int count) : Unit(range, hp, armor, attack, stamina, price, count)
	{}
	
	virtual int attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy);
	~Archer();
};

