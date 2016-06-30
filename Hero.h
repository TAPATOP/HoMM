#pragma once
#include<string>
#include<vector>

#include"Unit.h"
using namespace std;

enum Race
{
	Heaven,
	Inferno,
	UnknownRace
};
enum Type
{
	mage,
	warrior,
	UnknownType
};

class Hero: public Unit
{
public:

	Hero();
	Hero(Hero&);

	void setRace(Race);
	void setType(Type);
	void setCurrentMana(int);
	void setGold(int);
	void setExperience(int);
	void setNextLvlExp(int);
	void setLevel(int);
	void setMana(int);
	void setCrit(int);


	string getName();
	int getCount();
	int* getGold();
	int getgold();
	int getExperience();
	int getNextLvlExp();
	int getLevel();
	int getMana();
	int getCurrentMana();
	int getCrit();
	Race getRace();
	Type getType();
	virtual int getDamage();
	string displayType();

	bool load(string name);
	void save();
	void createHero(string name);
	string displayRace();
	virtual void die();
	virtual void takeDamage(int, vector <shared_ptr<Unit>>, vector <shared_ptr<Unit>> ownarmy);
	//virtual int attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y);
	virtual int cast(string magic, int x, int y, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);
	virtual void magicList();
	void postBattleEffects(int exp, bool isVictorious);
	~Hero();

private:
	int gold;
	int experience;
	int nextLvlExperience;
	int level;
	int mana;
	int currentMana;
	int crit;
	Race race;
	Type type;
	int count;

};

