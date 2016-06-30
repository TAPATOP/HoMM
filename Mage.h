#pragma once
#include"Hero.h"
class Mage: public Hero
{
public:
	Mage();
	Mage(Hero& another);

	virtual int cast(string magic, int x, int y, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);
	virtual void magicList();

	~Mage();
};

