#include "stdafx.h"
#include "Brute.h"
#include"Unit.h"
#include<iostream>
#include<vector>

using namespace std;

Brute::Brute()
{
	setName("Brute");
}

int Brute::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	int functionReturn;
	double modifier = 0.25;
	functionReturn = Unit::attackEnemy(enemyarmy, x, y, ownarmy);

	if (functionReturn != 2) return functionReturn;

	int size = enemyarmy.size();
	bool heroTookDmg = 0;

	cout << "Brute ability kicks in!" << endl<<endl;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (x + i > 0 && x + i <= maxsize && y + j > 0 && y + j <= maxsize && !(i == 0 && j == 0))
			{
				//enemyarmy.getMonster(x + i, y + j)->takeDamage(this->getDamage()/4);
				for (int m = 0; m < size; m++)
				{
					if (enemyarmy[m]->getY() == y + j && enemyarmy[m]->getX() == x + i)
					{
						enemyarmy[m]->takeDamage(getDamage() * modifier, ownarmy,enemyarmy);
						break;
					}
				}
			}
		}
	}
	return 2;
}

Brute::~Brute()
{
}
