#include "stdafx.h"
#include "Archangel.h"


Archangel::Archangel()
{
	setName("Archangel");
}



int Archangel::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	int value = Unit::attackEnemy(enemyarmy, x, y,ownarmy);
	int changeX = x - getX();
	int changeY = y - getY();
	int size = enemyarmy.size();

	if (value == 2)
	{
		cout << "Archangel ability kicks in!" << endl;
		for (int i = 1, j = 1; (i*changeX + x > 0 && i*changeX + x < 11 && j*changeY + y > 0 && j*changeY + y < 11); i++, j++)
		{
			for (int m = 0; m < size; m++)
			{
				if (enemyarmy[m]->getX() == i*changeX + x && enemyarmy[m]->getY() == j*changeY + y)
				{
					enemyarmy[m]->takeDamage(getDamage() / 2, ownarmy,enemyarmy);
					break;
				}

			}
			//found which monster is on that square
		}
		return 2;
	}
	return value;
}



/*bool validateCoords(int x, int y)
{
	if (x>0 && x <= maxsize && y > 0 && y <= maxsize) return 1;
	else return 0;
}
*/
shared_ptr<Unit> getMonster(int x, int y, vector <shared_ptr<Unit>> army)
{
	int counter = army.size();
	for (int i = 0; i < counter; i++)
	{
		if (army[i]->getX() == x && army[i]->getY() == y) return army[i];
	}
	return shared_ptr<Unit>(new Unit());
}

Archangel::~Archangel()
{
}