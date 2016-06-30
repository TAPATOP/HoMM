#include "stdafx.h"
#include "Vermin.h"


Vermin::Vermin()
{
	setName("Vermin");
}


int Vermin::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	int originalAttack = getDamage();
	int value = Unit::attackEnemy(enemyarmy, x, y, ownarmy);

	cout << "Time for Vemin's special:" << endl;
	if (value == 2)
	{
		int size = enemyarmy.size();
		for (int i = 0; i < size; i++)
		{
			if (enemyarmy[i]->getX() == x && enemyarmy[i]->getY() == y)
			{
				enemyarmy[i]->setFutureDamage(2);
				enemyarmy[i]->setAdditionalDamage(originalAttack / 4);
				cout << endl;
				break;
			}
		}
		return 2;
	}
	return value;

}

Vermin::~Vermin()
{
}
