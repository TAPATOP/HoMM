#include "stdafx.h"
#include "Unit.h"
#include <cmath>
#include <iostream>
#include<string>
#include<fstream>
using namespace std;


Unit::Unit()
{
	name = "Unit";
	range=0;
	hp=0;
	armor=0;
	attack=0;
	stamina=0;
	isFrozen=0;
	isStunned=0;
	isShielded=0;
	x=0;
	y=0;
	willBeDamaged=0;
	additionalDamage=0;
	price = 0;
	count = 0;
	totalhp = 0;
}
Unit::Unit(int range, int hp, int armor, int attack, int stamina, int price, int count)
{
	name = "Unit";
	this->range = range;
	this->hp = hp;
	this->armor = armor;
	this->attack = attack;
	this->stamina = stamina;
	setStun(0);
	setFreeze(0);
	setShield(0);
	this->price = price;
	this->count = count;
	totalhp = hp*count;
}

int Unit::gethp()
{
	return hp;
}
int Unit::getRange()
{
	return range;
}
int Unit::getArmor()
{
	return armor;
}
int Unit::getAttack()
{
	return attack;
}
int Unit::getStamina()
{
	return stamina;
}
int Unit::getX()
{
	return x;
}
int Unit::getY()
{
	return y;
}
string Unit::getName()
{
	return name;
}

void Unit::sethp(int hp)
{
	this->hp = hp;
}
void Unit::setRange(int range)
{
	this->range = range;
}
void Unit::setArmor(int armor)
{
	this->armor = armor;
}
void Unit::setAttack(int attack)
{
	this->attack = attack;
}
void Unit::setStamina(int stamina)
{
	this->stamina = stamina;
}
void Unit::setY(int y)
{
	this->y = y;
}
void Unit::setX(int x)
{
	this->x = x;
}

void Unit::setFreeze(int value)
{
	isFrozen = value;
}
void Unit::setStun(int value)
{
	isStunned = value;
}
void Unit::setShield(int value)
{
	isShielded = value;
}
void Unit::setFutureDamage(int value)
{
	willBeDamaged = value;
}
void Unit::setAdditionalDamage(int value)
{
	additionalDamage = value;
}
int Unit::move(int x1, int y1, vector<shared_ptr<Unit>> army1, vector<shared_ptr<Unit>> army2)
{
	//validate coords in main first=> sure
	if (isSpotFree(x1, y1, army1, army2))//make sure position is clear
	{
		if (abs(x - x1) == 1 && abs(y - y1) == 1 || sqrt(pow(abs(x - x1), 2) + pow(abs(y - y1), 2)) <= stamina)//stamina
		{
			setX(x1);
			setY(y1);
			return 2;//success
		}
		return 0;//no stamina
	}
	return 1;//spot taken
}
void Unit::setName(string name)
{
	this->name = name;
}

int Unit::checkIsFrozen()
{
	return isFrozen;
}
int Unit::checkIsStunned()
{
	return isStunned;
}
int Unit::checkIsShielded()
{
	return isShielded;
}
int Unit::checkWillBeDamaged()
{
	return willBeDamaged;
}
int Unit::getAdditionalDamage()
{
	return additionalDamage;
}
int Unit::getDamage()
{
	return getAttack() * count;
}
int Unit::getPrice()
{
	return price;
}
int Unit::getCount()
{
	return count;
}
int Unit::getTotalhp()
{
	return totalhp;
}


void Unit::setPrice(int price)
{
	this->price = price;
}
void Unit::setTotalhp(int value)
{
	totalhp = value;
}
void Unit::setCount(int count)
{
	this->count = count;
}


bool Unit::buy(int &budget, int number)
{

	if (number*getPrice() <= budget)
	{
		setCount(getCount() + number);
		budget -= number*getPrice();
		cout << "Purchase is successful! You now have " << getCount() << " units of this type! Treasury left: " << budget << " gold" << endl;
		totalhp = count*hp;
		return 1;
	}
	cout << "Your treasury is not enough!" << endl;
	return 0;
}
void Unit::load()
{
	cout << "Loading unit" << endl;
	string path = "Creatures\\" + getName() + ".txt";
	ifstream in;
	in.open(path);
	getline(in, path, ';');//cleares header
	int hp, armor, attack, range, stamina;
	in >> hp >> armor >> attack >> range >> stamina >> price;
	sethp(hp);
	setArmor(armor);
	setAttack(attack);
	setRange(range);
	setStamina(stamina);
	setStun(0);
	setFreeze(0);
	setShield(0);

	totalhp = count*gethp();
}
int Unit::getTotalDefence()
{
	return getArmor()*count;
}



int Unit::attackEnemy(vector <shared_ptr<Unit>> enemyarmy, int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	//checkIsStunned in main
		int size = enemyarmy.size();
		int index = -1;
		for (int i = 0; i < size; i++)
		{
			if (enemyarmy[i]->getX() == x && enemyarmy[i]->getY() == y)
			{
				index = i;
				break;
			}
		}
		//eventually found ID of enemy monster

		if (index == -1)
		{
			return 0;// 0 means no monster
		}

		if (abs(this->getX() - x) == 1 && abs(this->getY() - y) == 1 ||
			sqrt(pow(abs(this->getX() - x), 2) + pow(abs(this->getY() - y), 2)) <= getRange())
		{
			cout << endl << "Attack initiated by "<< getName()<<"!" << endl;
			if (getDamage() < enemyarmy[index]->getTotalDefence())
			{
				takeDamage(enemyarmy[index]->getTotalDefence() - getDamage(), ownarmy, enemyarmy);
			}
			else
			{
				enemyarmy[index]->takeDamage(getDamage() - enemyarmy[index]->getTotalDefence(), ownarmy, enemyarmy);
			}
			return 2;// 2 means success
		}
	return 1;// 1 means out of range

}
bool Unit::die(int dead)
{
	
	if (dead > 0)
	{
		cout << dead << " " << getName() << " have died!" << endl;
	}
	else
	{
		return 0;
	}

	if (totalhp <= 0)
	{
		setX(0);
		setY(0);
		cout << name << " have been removed from the field" << endl;
	}
	cout << endl;
	return 1;
}
string Unit::returnName()
{
	if (getName() == "Peasant") return "-Pe";
	if (getName() == "Brute") return "-Br";
	if (getName() == "Archer") return "-Ar";
	if (getName() == "Crossbowman") return "-Cr";
	if (getName() == "Angel") return "-An";
	if (getName() == "Archangel") return "-AA";
	if (getName() == "Imp") return "-Im";
	if (getName() == "Vermin") return "-Ve";
	if (getName() == "Horned Demon") return "-HD";
	if (getName() == "Horned Grunt") return "-HG";
	if (getName() == "Devil") return "-De";
	if (getName() == "Arch Devil") return "-AD";
	
}
bool Unit::isCreature(string name)
{
	if (name == "Peasant" || name == "Brute" || name == "Archer" || name == "Crossbowman" || name == "Angel" || name == "Archangel" || name == "Imp" || name == "Vermin" || name == "Horned Grunt" || name == "Horned Demon" || name == "Devil" || name == "Arch Devil") return 1;
	return 0;
}
void Unit::takeDamage(int damage, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	int start = getCount();
	cout << getName() << " just took " << damage << " damage!" << endl;
	totalhp -= damage;
	cout << getName()<< "'s total hp is now:" << totalhp << endl;
	if (totalhp > 0)
	{
		count = totalhp / gethp();
		if (totalhp%gethp() > 0 && totalhp > 0)
		{
			count++;
		}
	}
	else
	{
		count = 0;
	}
	if (start - getCount() > 0)
	{
		die(start - getCount());
	}
}

Unit::~Unit()
{
}

bool validateCoords(int x, int y)
{
	while (x <= 0 || y <= 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input, positive natural number expected... Retry input." << endl;
		return 0;

	}
	if (x > 0 && x <= maxsize && y > 0 && y <= maxsize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool isSpotFree(int x, int y, vector<shared_ptr<Unit>> army1, vector<shared_ptr<Unit>> army2)
{
	bool flag = 0;
	int counter = army1.size();
	if (validateCoords(x, y))//valid coords
	{
		int size = army1.size();
		for (int i = 0; i < size; i++)
		{
			if (x == army1[i]->getX() && y == army1[i]->getY()) return 0;
		}

		size = army2.size();
		for (int i = 0; i < size; i++)
		{
			if (x == army2[i]->getX() && y == army2[i]->getY()) return 0;
		}

		return 1;
	}
	return 0;
}
shared_ptr<Unit> getUnit(int x, int y, vector <shared_ptr<Unit>> ownarmy)
{
	int size = ownarmy.size();

	for (int i = 0; i < size; i++)
	{
		if (ownarmy[i]->getX() == x && ownarmy[i]->getY() == y)
		{
			return ownarmy[i];
		}
	}
	return 0;
}