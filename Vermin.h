#pragma once
#include"Imp.h"
class Vermin:public Imp
{
public:
	Vermin();

	virtual int attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy);

	~Vermin();
};

