#pragma once
#include"Peasant.h"
#include"Unit.h"
#include"Army.h"
#include<vector>

class Brute: public Peasant
{
public:
	Brute();
	Brute(int range, int hp, int armor, int attack, int stamina, int price, int count) : Peasant(range, hp, armor, attack, stamina, price, count)
	{
	}

	virtual int attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy);
	~Brute();
	//virtual void attackEnemy(Unit&, vector<shared_ptr<Unit>> enemyarmy);
};