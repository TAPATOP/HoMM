#pragma once
#include"Unit.h"
#include"Hero.h"
#include<string>
#include<vector>
#include<memory>
using namespace std;

class Army
{
public:
	Army();
	Army(vector <shared_ptr<Unit>> army);

	bool isDestroyed();
	bool addUnit(shared_ptr<Unit> newOne);
	shared_ptr<Unit> getMonster(int i);
	shared_ptr<Unit> getMonster(int x, int y);
	int getSize();
	vector <shared_ptr<Unit>> exportVector();
	//void displayMonsters(Hero &hero);
	//void buyMonsters(int budget);
	int getArmySize();
	void eraseKilled();
	~Army();
	
private:
	vector <shared_ptr <Unit>> army;
};

//void loadHeaven(Peasant&, Brute&, Archer&, Crossbowman&, Angel&, Archangel&);
