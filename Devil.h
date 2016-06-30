#pragma once
#include"Unit.h"
class Devil:public Unit
{
public:
	Devil();

	virtual void takeDamage(int damage, vector<shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);
	virtual bool die(int x, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);

	~Devil();
};

