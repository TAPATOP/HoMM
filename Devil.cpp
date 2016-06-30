#include "stdafx.h"
#include "Devil.h"
#include<iostream>

using namespace std;

Devil::Devil()
{
	setName("Devil");
}

void Devil::takeDamage(int damage, vector<shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	int start = getCount();
	cout << getName() << " just took " << damage << " damage!" << endl;
	setTotalhp(getTotalhp()-damage);
	cout << "Total hp is now:" << getTotalhp() << endl;
	if (getTotalhp() > 0)
	{
		setCount(getTotalhp() / gethp());
		if (getTotalhp()%gethp() > 0 && getTotalhp() > 0)
		{
			setCount(getCount()+1);
		}
	}
	else
	{
		setCount(0);
	}
	if (start - getCount() > 0)
	{
		die(start - getCount(),enemyarmy, ownarmy);
	}
}
bool Devil::die(int dead, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	bool value = Unit::die(dead);
	if (value&&getTotalhp()>0)
	{
		cout << "Devil special ability kicks in!" << endl;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				int size = enemyarmy.size();
				for (int m = 0; m < size; m++)
				{
					if (enemyarmy[m]->getX() == i + getX() && enemyarmy[m]->getY() == j + getY())
					{
						if (getUnit(i + getX(), j + getY(),enemyarmy)->checkIsShielded() == 0)
						{
							attackEnemy(enemyarmy, enemyarmy[m]->getX(), enemyarmy[m]->getY(), ownarmy);
						}
						else
						{
							cout << getUnit(i + getX(), j + getY(),enemyarmy)->getName() << " has been protected from " << getName() << "'s special attack by a Shield!" << endl;
						}
						//enemyarmy[m]->takeDamage(getDamage(), enemyarmy, ownarmy);
					}
				}
			}
		}
	}
	return value;
}

Devil::~Devil()
{
}
