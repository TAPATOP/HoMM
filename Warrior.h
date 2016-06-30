#pragma once
#include"Hero.h"
class Warrior: public Hero
{
public:
	Warrior();
	Warrior(Hero& another);

	virtual int cast(string magic, int x, int y, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);
	virtual void magicList();

	~Warrior();

};

