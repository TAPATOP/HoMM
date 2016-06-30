#include "stdafx.h"
#include "Army.h"

#include"Peasant.h"
#include"Brute.h"
#include"Imp.h"
#include"Vermin.h"
#include"Archangel.h"
#include"Angel.h"
#include"Archer.h"
#include"Crossbowman.h"
#include"HornedDemon.h"
#include"HornedGrunt.h"
#include"Devil.h"
#include"ArchDevil.h"

#include<iostream>
#include<string>
using namespace std;

Army::Army()
{
}
Army::Army(vector <shared_ptr<Unit>> army)
{
	this->army = army;
}

bool Army::isDestroyed()
{
	int size = army.size();
	for (int i = 0; i < size; i++)
	{
		if (army[i]->getCount() > 0) return 0;
	}
	return 1;
}
bool Army::addUnit(shared_ptr<Unit> newOne)
{
	shared_ptr<Unit> addMe(newOne);

	if (newOne->getName() != "Unit")
	{
		army.push_back(addMe);
		cout << "Unit added to the army!" << endl;
		return 1;
	}
	return 0;
}
shared_ptr<Unit> Army::getMonster(int index)
{
	return army[index];
}
shared_ptr<Unit> Army::getMonster(int x, int y)
{
	int counter = army.size();
	for (int i = 0; i < counter; i++)
	{
		if (army[i]->getX() == x && army[i]->getY() == y)
		{
			return army[i];
		}
	}
	return shared_ptr<Unit>(new Unit());
}
vector <shared_ptr<Unit>> Army::exportVector()
{
	return army;
}
int Army::getSize()
{
	return army.size();
}
int Army::getArmySize()
{
	int number=0;
	int size = army.size();

	for (int i = 0; i < size; i++)
	{
		number += army[i]->getCount();
	}
	return number;
}
void Army::eraseKilled()
{
	int size = army.size();
	for (int i = 0; i < size; i++)
	{
		if (army[i]->getCount() <= 0)
		{
			army.erase(army.begin() + i);
		}
	}
}

Army::~Army()
{
	army.clear();
}

