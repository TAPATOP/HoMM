	#pragma once
#include<vector>

#include"Archer.h"

class Crossbowman: public Archer
{
public:
	Crossbowman();
	Crossbowman(int range, int hp, int armor, int attack, int stamina, int price, int count) : Archer(range, hp, armor, attack, stamina, price, count)
	{
	}

	virtual int attackEnemy(vector <shared_ptr<Unit>>, int x, int y, vector <shared_ptr<Unit>> ownarmy);

	~Crossbowman();
};

