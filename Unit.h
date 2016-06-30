#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<memory>

using namespace std;

const int maxsize = 9;
const int maxWillBeDamaged = 2;
class Unit
{
public:
	Unit();
	Unit(int range, int hp, int armor, int attack, int stamina, int price, int count);

	int gethp();
	int getRange();
	int getArmor();
	int getAttack();
	int getStamina();
	int getX();
	int getY();
	int checkIsFrozen();
	int checkIsStunned();
	int checkIsShielded();
	int checkWillBeDamaged();
	int getAdditionalDamage();
	virtual int getDamage();
	int getPrice();
	int getCount();
	int getTotalhp();
	int getTotalDefence();

	string getName();
	//да не забравиш да оправиш конструктора, че си е .... 
	void sethp(int);
	void setRange(int);
	void setArmor(int);
	void setAttack(int);
	void setStamina(int);
	void setX(int x);
	void setY(int y);//
	void setFreeze(int);
	void setStun(int);
	void setShield(int);
	void setFutureDamage(int);
	void setAdditionalDamage(int);
	void setName(string);
	void setPrice(int price);
	void setTotalhp(int);
	void setCount(int);

	virtual int move(int x1, int y1, vector<shared_ptr<Unit>> army1, vector<shared_ptr<Unit>> army2);
	virtual void load();
	bool buy(int &budget, int number);
	virtual int attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy);
	virtual bool die(int);
	string returnName();
	bool isCreature(string name);
	virtual void takeDamage(int, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy);

	virtual ~Unit();
private:
	string name;
	int range;
	int hp;
	int armor;
	int attack;
	int stamina;
	int isFrozen;
	int isStunned;
	int isShielded;
	int x;
	int y;
	int willBeDamaged;
	int additionalDamage;
	int price;
	int count;
	int totalhp;
};

bool isSpotFree(int x, int y, vector<shared_ptr<Unit>> army1, vector<shared_ptr<Unit>> army2);
bool validateCoords(int x, int y); 
shared_ptr<Unit> getUnit(int x, int y, vector <shared_ptr<Unit>> ownarmy);
