#include "stdafx.h"
#include "ArchDevil.h"


ArchDevil::ArchDevil()
{
	setName("Arch Devil");
}

int ArchDevil::move(int x1, int y1, vector<shared_ptr<Unit>> army1, vector<shared_ptr<Unit>> army2)
{
	if (isSpotFree(x1, y1, army1, army2))
	{
		return Unit::move(x1, y1, army1, army2);
	}
	
	cout << "Arch Devil special ability about to kick in!" << endl;
	int size = army2.size();
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (army2[i]->getX() == x1&&army2[i]->getY())
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		int x0 = getX(), y0 = getY();
		setX(x1);
		setY(y1);
		army2[index]->setX(x0);
		army2[index]->setY(y0);
		return 2;
	}

	size = army1.size();
	for (int i = 0; i < size; i++)
	{
		if (army1[i]->getX() == x1&&army1[i]->getY())
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		int x0 = getX(), y0 = getY();
		setX(x1);
		setY(y1);
		army1[index]->setX(x0);
		army1[index]->setY(y0);
		return 2;
	}
}

ArchDevil::~ArchDevil()
{
}
