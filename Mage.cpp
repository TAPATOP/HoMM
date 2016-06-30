#include "stdafx.h"
#include "Mage.h"

Mage::Mage()
{
}

Mage::Mage(Hero &another)
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

int Mage::cast(string magic, int x, int y, vector <shared_ptr<Unit>> enemyarmy, vector <shared_ptr<Unit>> ownarmy)
{
	if (getCurrentMana() >= 20)
	{
		if (getUnit(x, y, enemyarmy) != 0)
		{
			if (getUnit(x, y, enemyarmy)->checkIsShielded() == 0)
			{
				if (magic == "FireBall")
				{
					cout << getName() << " is casting a FireBall!" << endl;
					getUnit(x, y, enemyarmy)->takeDamage(this->getAttack()*(1 + getMana()*0.01), ownarmy, enemyarmy);
					setCurrentMana(getCurrentMana() - 20);
					return 2;//success
				}
				if (magic == "IceBall" && getCurrentMana()>=30)
				{
					cout << getName() << " is casting an IceBall!" << endl;
					cout << getUnit(x, y, enemyarmy)->getName() << " has been hit by IceBall!" << endl;
					getUnit(x, y, enemyarmy)->setFreeze(2);
					setCurrentMana(getCurrentMana() - 30);
					return 2;//success
				}
				return 3;//no such magic found
			}
			return 12;// is shielded
		}
		return 0;//no enemy at position
	}
	return 1;//no mana
}
void Mage::magicList()
{
	cout << getName() << " can cast the following magics:" << endl << "FireBall" << endl << "IceBall" << endl;
}

Mage::~Mage()
{
}
