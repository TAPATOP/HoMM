#include "stdafx.h"
#include "Archer.h"


Archer::Archer()
{
	setName("Archer");
}
int Archer::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	return Unit::attackEnemy(enemyarmy, x, y, ownarmy);
}

Archer::~Archer()
{
}
