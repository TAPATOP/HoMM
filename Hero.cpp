#include "stdafx.h"
#include "Hero.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

using namespace std;

Hero::Hero()
{
	setName("NoNameHero");
	gold=0;
	experience=0;
	nextLvlExperience=0;
	level=0;
	mana=0;
	crit=0;
	type = UnknownType;
	race = UnknownRace;
	currentMana = mana;
	count = 1;
}
Hero::Hero(Hero& another)
{
	this->setName(another.getName());
	this->setRange(another.getRange());
	this->sethp(another.gethp());
	this->setArmor(another.getArmor());
	this->setAttack(another.getAttack());
	this->setStamina(another.getStamina());
	this->setX(another.getX());
	this->setY(another.getY());
	this->setPrice(another.getPrice());
	this->setCount(another.getCount());
	this->setTotalhp(another.getTotalhp());
	this->setGold(another.gold);
	this->experience = another.getExperience();
	this->nextLvlExperience = another.getNextLvlExp();
	this->level = another.getLevel();
	this->mana = another.getMana();
	this->currentMana = another.getCurrentMana();
	this->crit = another.getCrit();
	this->race = another.getRace();
	this->type = another.getType();
	this->count = another.getCount();
}

void Hero::setRace(Race race)
{
	this->race = race;
}
void Hero::setType(Type type)
{
	this->type = type;
}
void Hero::setCurrentMana(int newmana)
{
	currentMana = newmana;
}
void Hero::setGold(int gold)
{
	this->gold = gold;
}
void Hero::setExperience(int exp)
{
	experience = exp;
}
void Hero::setNextLvlExp(int exp)
{
	nextLvlExperience = exp;
}
void Hero::setLevel(int level)
{
	this->level = level;
}
void Hero::setMana(int mana)
{
	this->mana = mana;
}
void Hero::setCrit(int crit)
{
	this->crit = crit;
}
Type Hero::getType()
{
	return type;
}
Race Hero::getRace()
{
	return race;
}
string Hero::getName()
{
	return Unit::getName();
}
int* Hero::getGold()
{
	return &gold;
}
int Hero::getgold()
{
	return gold;
}
int Hero::getExperience()
{
	return experience;
}
int Hero::getNextLvlExp()
{
	return nextLvlExperience;
}
int Hero::getLevel()
{
	return level;
}
int Hero::getMana()
{
	return mana;
}
int Hero::getCurrentMana()
{
	return currentMana;
}
int Hero::getCrit()
{
	return crit;
}
int Hero::getDamage()
{
	return getAttack()+getAttack()*(0.1*crit);
}
int Hero::getCount()
{
	return 1;
}
string Hero::displayType()
{
	switch (type)
	{
	case 0:
		return "Warrior";
		
	case 1:
		return "Mage";

	default:
		return "Some Random Type I guess";
	}
}

bool Hero::load(string name)
{
	setName(name);
	name = "Heroes\\" + name;
	name += ".txt";

	ifstream in;
	in.open(name);
	
	if (!in)
	{
		cout << "Error reading from file..." << endl;
		return 0;
	}
	
	string cleanHeader;
	getline(in, cleanHeader, ';');
	int hp, armor, attack, range, stamina;
	in >> level >> experience >> nextLvlExperience >> hp >> armor >> attack >> range >> crit >> mana >> stamina >> gold;
	sethp(hp);
	setArmor(armor);
	setAttack(attack);
	setRange(range);
	setStamina(stamina);
	in.close();
	setTotalhp(gethp());
	setCurrentMana(mana);
	count = 1;
	cout << "Hero loaded successfully!" << endl;
	return 1;
}
void Hero::save()
{
	ofstream out;
	out.open("Heroes\\" + getName() + ".txt");
	out << "level experience nextlvlexperience hp armor attack range crit mana stamina gold;"<<endl;
	out << level << " " << experience << " " << nextLvlExperience << " " << gethp() << " " << getArmor() << " " << getAttack() << " " << getRange() << " " << crit << " " << mana << " " << getStamina() << " " << gold;
}
void Hero::createHero(string name)
{
	setName(name);
	name = "Heroes\\" + name;
	name += ".txt";
	ofstream file;

	int hp, armor, attack, range, stamina;

	file.open(name);
	cout << "Input hero stats as follows:" << endl;
	cout << "Level:"; cin >> level;
	cout << "Exp:"; cin >> experience;
	cout << "Exp for next level:"; cin >> nextLvlExperience;
	cout << "HP:"; cin >> hp;
	cout << "Armor:"; cin >> armor;
	cout << "Attack:"; cin >> attack;
	cout << "Range:"; cin >> range;
	cout << "Crit:"; cin >> crit;
	cout << "Mana:"; cin >> mana;
	cout << "Stamina:"; cin >> stamina;
	cout << "Gold:"; cin >> gold;

	sethp(hp);
	setArmor(armor);
	setAttack(attack);
	setRange(range);
	setStamina(stamina);

	cout << endl << "Hero has been successfully created!" << endl;
	file << "name level experience nextlvlexperience hp armor attack range crit mana stamina gold;";
	file << endl << level << " " << experience << " " << nextLvlExperience << " " << hp << " " << armor << " " << attack << " " << range << " " << crit << " " << mana << " " << stamina << " " << gold;
	file.close();
	setTotalhp(gethp());
	setCurrentMana(mana);
}
string Hero::displayRace()
{
	if (race == 0) return "Heaven";
	if (race == 1) return "Inferno";

	return "Unknown";
}
void Hero::die()
{
	if (gethp() <= 0)
	{
		cout << getName() << " has died!" << endl;
		setX(0);
		setY(0);
		setCount(0);
	}

}

void Hero::takeDamage(int damage, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	sethp(gethp() - damage);
	cout << getName() << " has taken " << damage << " damage and has "<<gethp()<<" left!" << endl;
	die();
}
int Hero::cast(string magic, int x, int y, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	cout << "This shouldn't even appear tbh" << endl;
	return 0;
}
void Hero::magicList()
{
	cout << "Just inherit me already" << endl;
}
void Hero::postBattleEffects(int exp, bool isVictorious)
{
	setExperience(getExperience() + exp);

	while(experience >= nextLvlExperience)
	{
		cout << getName() << " has leveled up!" << endl;
		nextLvlExperience *= 1.5;
		level++;
		cout << "Choose whether " << getName() << " would gain another point of mana or crit( 0 for mana, 1 for crit): " << endl;
		bool up;
		cin >> up;
		if (up)
		{
			crit++;
		}
		else
		{
			mana += 10;
		}
	}

	if (isVictorious)
	{
		gold += 500;
	}
	else
	{
		gold += 200;
	}
}

Hero::~Hero()
{
}