#pragma once
#include"Devil.h"
class ArchDevil:public Devil
{
public:
	ArchDevil();

	int move(int x1, int y1, vector<shared_ptr<Unit>> army1, vector<shared_ptr<Unit>> army2);

	~ArchDevil();
};

