#include "stdafx.h"
#include "HornedDemon.h"


HornedDemon::HornedDemon()
{
	setName("Horned Demon");
}


int HornedDemon::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	int value = Unit::attackEnemy(enemyarmy, x, y, ownarmy);

	
	if (value == 2 && getUnit(x, y, enemyarmy)->gethp()>0 && gethp()>0)
	{
		cout << "Horned Demon ability incoming!" << endl;
		int v1, v2 = 0;
		int start = getCount();
		srand(time(NULL));
		v1 = rand() % 100;

		if (v1 % 2 == 0)
		{
			Unit::attackEnemy(enemyarmy, x, y,ownarmy);
		}
		else
		{
			cout << "Horned Demon's ability failed to activate!" << endl;
		}
	}
	return value;
}

HornedDemon::~HornedDemon()
{
}
