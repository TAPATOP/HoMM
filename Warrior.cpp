#include "stdafx.h"
#include "Warrior.h"


Warrior::Warrior()
{
}

Warrior::Warrior(Hero &another)
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
	this->setGold(another.getgold());
	this->setExperience(another.getExperience());
	this->setNextLvlExp(another.getNextLvlExp());
	this->setLevel(another.getLevel());
	this->setMana(another.getMana());
	this->setCurrentMana(another.getCurrentMana());
	this->setCrit(another.getCrit());
	this->setRace(another.getRace());
	this->setType(another.getType());
	this->setCount(another.getCount());
}

int Warrior::cast(string magic, int x, int y, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	if (getCurrentMana() >= 30 && checkIsStunned()==0)
	{

		if (magic == "Stun")
		{
			if (getUnit(x, y, enemyarmy) != 0)
			{
				if (getUnit(x, y, enemyarmy)->checkIsShielded() == 0)
				{
					getUnit(x, y, enemyarmy)->setStun(2);
					cout << getUnit(x, y, enemyarmy)->getName() << " has been stunned!" << endl;
					setCurrentMana(getCurrentMana() - 30);
					cout << getName() << "'s remaining mana:" << getCurrentMana() << endl;
					return 2;//success
				}
				return 12;// is shielded
			}
			return 0;//no unit
		}
		if (magic == "Shield")
		{
			if (getUnit(x, y, ownarmy) != 0)
			{
				getUnit(x, y, ownarmy)->setShield(2);
				setCurrentMana(getCurrentMana() - 30);
				cout << getName() << "'s remaining mana:" << getCurrentMana() << endl;
				cout << getUnit(x, y, ownarmy)->getName() << " has been shielded!" << endl;
				return 2;// success
			}
			return 0;//no unit
		}
		return 3;// no such magic found
	}
	return 1;//no mana
}
void Warrior::magicList()
{
	cout << getName() << " can cast the following magics:" << endl << "Stun" << endl << "Shield" << endl;
}
Warrior::~Warrior()
{
}
