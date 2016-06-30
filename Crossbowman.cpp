#include "stdafx.h"
#include<vector>
#include<iostream>

#include "Crossbowman.h"
#include"Unit.h"
#include "Hero.h"

using namespace std;

Crossbowman::Crossbowman()
{
	setName("Crossbowman");
}

int Crossbowman::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	if (abs(this->getX() - x) == 1 && abs(this->getY() - y) == 1 ||
		sqrt(pow(abs(this->getX() - x), 2) + pow(abs(this->getY() - y), 2)) <= getRange())
	{
		cout << "Crossbowman firing a volley!" << endl;

		int size = enemyarmy.size();
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (x + i > 0 && x + i <= maxsize && y + j > 0 && y + j <= maxsize)
				{
					//enemyarmy.getMonster(x + i, y + j)->takeDamage(this->getDamage()/4);
					for (int m = 0; m < size; m++)
					{
						if (enemyarmy[m]->getY() == y + j && enemyarmy[m]->getX() == x + i)
						{
							enemyarmy[m]->takeDamage(getDamage(), ownarmy, enemyarmy);
							break;
						}
					}
				}
			}
		}
		return 2;//success
	}
	return 1;// out of range
}

Crossbowman::~Crossbowman()
{
}
