#pragma once
#include"Unit.h"
#include <ctime>
class HornedDemon:public Unit
{
public:
	HornedDemon();

	virtual int attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy);

	
	~HornedDemon();
};

