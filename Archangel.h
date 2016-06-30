#pragma once
#include"Angel.h"
class Archangel:public Angel
{
public:
	Archangel();

	virtual int attackEnemy(vector <shared_ptr<Unit>>, int x, int y, vector <shared_ptr<Unit>> ownarmy);

	~Archangel();
};

