#include "stdafx.h"
#include <time.h> 

#include "Angel.h"

using namespace std;

Angel::Angel()
{
	setName("Angel");
}

void Angel::takeDamage(int damage, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	int start = getCount();
	cout << getName() << " just took " << damage << " damage!" << endl;
	setTotalhp(getTotalhp()-damage);
	if (getTotalhp() > 0)
	{
		setCount(getTotalhp() / gethp());
		if (getTotalhp() % gethp() > 0 && getTotalhp() > 0)
		{
			setCount(getCount() + 1);
		}

	}
	else
	{
		setCount(0);
	}
	die(start - getCount());
	cout << "Total hp is now:" << getTotalhp() << endl;
}
bool Angel::die(int dead)
{
	if (dead > 0)
	{
		cout << "Initially, " << dead << " " << getName() << " have died!" << endl;
	}
	else
	{
		return 0;
	}

	int v1, v2 = 0;
	int start = getCount();
	srand(time(NULL));
	v1 = rand() % 100;
	if (getCount() == 0)
	{
		setTotalhp(0);
	}
	if (dead > 0)
	{
		if (v1 % 2 == 0)
		{
			v2 = rand() % (dead)+1;
			setCount(getCount() + v2);
			setTotalhp(getTotalhp() + v2*gethp());
			cout << v2 << " " << getName() << " have been resurrected!" << endl;
		}
		else
		{
			cout << getName() << " have failed to resurrect!" << endl;
		}
	}
	cout << "In the end, ";
	Unit::die(dead-v2);
	return 1;
}

Angel::~Angel()
{
}
