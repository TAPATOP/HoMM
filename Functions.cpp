#include"stdafx.h"
#include "Functions.h"


void setPosition(Unit& monster, Army& army1, Army& army2, Hero& P1, Hero& P2)
{
	while (true)
	{
		int x, y;
		bool flag = 0;
		int counter = army1.getSize();
		cout << "Insert the coordinates where you'll place your creature in the following order:" << endl << "X:";
		cin >> x;
		cout << "Y:"; cin >> y;

		if (validateCoords(x, y))//valid coords
		{
			if ((P1.getX() != x || P1.getY() != y) && (P2.getX() != x || P2.getY() != y))
			{
				for (int i = 0; i < counter; i++)
				{
					if (army1.getMonster(i)->getX() == x && army1.getMonster(i)->getY() == y)
					{
						cout << "These coordinates have alredy been taken by Player 1's creature..." << endl;//empty slot function plox
						flag = 1;
						break;
					}
				}
				counter = army2.getSize();
				for (int i = 0; i < counter && flag == 0; i++)
				if (army2.getMonster(i)->getX() == x && army2.getMonster(i)->getY() == y)
				{
					cout << "These coordinates have alredy been taken by Player 2's creature..." << endl;
					flag = 1;
					break;
				}
			}
			else
			{
				cout << "There is a Hero on this position..." << endl;
				flag = 1;
			}
		}
		else
		{
			cout << "The coordinates you've entered do not belong to the battlefield..." << endl;
			flag = 1;
		}


		if (flag == 1) continue;
		else
		{
			monster.setX(x);
			monster.setY(y);
			cout << "Unit coordinates successfully set!" << endl;
			break;
		}

	}

}
void setPosition(Unit& monster, Army& army1, Army& army2, Hero& P1, Hero& P2,int ylimit, bool oneMeansToTheRight)
{
	while (true)
	{
		int x, y;
		bool flag = 0;
		int counter = army1.getSize();
		cout << "Insert the coordinates where you'll place your creature in the following order:" << endl << "X:";
		cin >> x;
		cout << "Y:"; cin >> y;
		if (oneMeansToTheRight)
		{
			if (y < ylimit)
			{
				cout << "This player can only position creatures to the right of y=" << ylimit << endl;
				continue;
			}
		}
		else
		{
			if (y>ylimit)
			{
				cout << "This player can only position creatures to the left of y="<< ylimit << endl;
				continue;
			}
		}
		if (validateCoords(x, y))//valid coords
		{
			if ((P1.getX() != x || P1.getY() != y) && (P2.getX() != x || P2.getY() != y))
			{
				for (int i = 0; i < counter; i++)
				{
					if (army1.getMonster(i)->getX() == x && army1.getMonster(i)->getY() == y)
					{
						cout << "These coordinates have alredy been taken by Player 1's creature..." << endl;//empty slot function plox
						flag = 1;
						break;
					}
				}
				counter = army2.getSize();
				for (int i = 0; i < counter && flag == 0; i++)
				if (army2.getMonster(i)->getX() == x && army2.getMonster(i)->getY() == y)
				{
					cout << "These coordinates have alredy been taken by Player 2's creature..." << endl;
					flag = 1;
					break;
				}
			}
			else
			{
				cout << "There is a Hero on this position..." << endl;
				flag = 1;
			}
		}
		else
		{
			cout << "The coordinates you've entered do not belong to the battlefield..." << endl;
			flag = 1;
		}


		if (flag == 1) continue;
		else
		{
			monster.setX(x);
			monster.setY(y);
			cout << "Unit coordinates successfully set!" << endl;
			break;
		}

	}

}
shared_ptr<Unit> createACreature(Hero &hero, string type)
{
	if (hero.getRace() == Heaven)
	if (type == "Peasant")
	{
		return shared_ptr<Peasant>(new Peasant());
	}
	else if (type == "Brute")
	{
		return shared_ptr<Brute>(new Brute());
	}
	else if (type == "Archer")
	{
		return shared_ptr<Archer>(new Archer());
	}
	else if (type == "Crossbowman")
	{
		return shared_ptr<Crossbowman>(new Crossbowman());
	}
	else if (type == "Angel")
	{
		return shared_ptr<Angel>(new Angel());
	}
	else if (type == "Archangel")
	{
		return shared_ptr<Archangel>(new Archangel());
	}
	else
	{
		cout << "The current hero's race is " << hero.displayRace() << ", which doesn't have a creature with the name \"" << type << "\"... Did you forget to capitalize the first letter?" << endl;
		{
			return shared_ptr<Unit>(new Unit());
		}
	}
	else
	if (hero.getRace() == Inferno)
	if (type == "Imp")
	{
		return shared_ptr<Imp>(new Imp());
	}
	else if (type == "Vermin")
	{
		return shared_ptr<Vermin>(new Vermin());
	}
	else if (type == "Horned Demon")
	{
		return shared_ptr<HornedDemon>(new HornedDemon());
	}
	else if (type == "Horned Grunt")
	{
		return shared_ptr<HornedGrunt>(new HornedGrunt());
	}
	else if (type == "Devil")
	{
		return shared_ptr<Devil>(new Devil());
	}
	else if (type == "Arch Devil")
	{
		return shared_ptr<ArchDevil>(new ArchDevil());
	}
	{
		cout << "The current hero's race is " << hero.displayRace() << ", which doesn't have a creature with the name \"" << type << "\"... Did you forget to capitalize the first letter?" << endl;

		{
			return shared_ptr<Unit>(new Unit());
		}
	}

}
bool buyFunct(Hero &player, string input, Army &army)
{
	shared_ptr<Unit> monster(new Unit());
	int amount = 0;
	cout << "Enter amount of creatures:" << endl;
	cin >> amount;

	while (amount <= 0)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input, positive natural number expected... Retry input." << endl;
		cin >> amount;
	}

	cout << "Enter type of creatures:" << endl;

	cin.clear(); cin.ignore(10, '\n');

	getline(cin, input, '\n');

	cin.clear(); cin.ignore(0, '\n');

	monster = createACreature(player, input);
	if (monster->getName() != "Unit")
	{
		int* budget = player.getGold();
		monster->load();

		if (monster->buy(*budget, amount))
		if (army.addUnit(monster))
		{
			cout << endl;
			cout << "Current " << player.getName() << " army:" << endl;
			for (int i = 0; i < army.getSize(); i++)
			if (army.getMonster(i)->getName() != player.getName())
			{
				cout << army.getMonster(i)->getCount() << " " << army.getMonster(i)->getName() << "s" << endl;
			}
			return 1;
		}
	}

	return 0;
}
bool unitIsInArmy(int x, int y, Army &army)
{
	if (validateCoords(x, y) && army.getMonster(x, y)->getName() != "Unit")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void displayBattlefield(Hero& P1, Hero& P2, Army& army1, Army& army2)
{
	cout << endl;
	for (int i = 1; i <= maxsize; i++)
	{
		for (int j = 1; j <= maxsize; j++)
		{
			if (P1.getX() == i && P1.getY() == j) cout << "hero001" << "(" << P1.getX() << "," << P1.getY() << ")";
			else
			{
				if (P2.getX() == i && P2.getY() == j) cout << "hero002" << "(" << P2.getX() << "," << P2.getY() << ")";
				else
				{
					if (army1.getMonster(i, j)->getName() != "Unit")
					{
						int count = army1.getMonster(i, j)->getCount();
						if (count < 10) cout << "00";
						else if (count < 100) cout << "0";
						cout << count;
						cout << army1.getMonster(i, j)->returnName() << "1";
						cout << "(" << army1.getMonster(i, j)->getX() << "," << army1.getMonster(i, j)->getY() << ")";
					}
					else
					if (army2.getMonster(i, j)->getName() != "Unit")
					{
						int count = army2.getMonster(i, j)->getCount();
						if (count < 10) cout << "00";
						else if (count < 100) cout << "0";
						cout << count;
						cout << army2.getMonster(i, j)->returnName() << "2";
						cout << "(" << army2.getMonster(i, j)->getX() << "," << army2.getMonster(i, j)->getY() << ")";
					}
					else cout << "------------";
				}
			}
			cout << " ";
		}
		cout << endl;
	}
}
void endTurnThings(Army& army, Army& enemyarmy, Hero& thisHero)
{
	int size = army.getSize();

	//army.eraseKilled();

	if (thisHero.getMana() > thisHero.getCurrentMana() && thisHero.gethp()>0)
	{
		thisHero.setCurrentMana(thisHero.getCurrentMana() + 10);
		cout << thisHero.getName() << " mana has been restored to:" << thisHero.getCurrentMana() << endl;
	}
	for (int i = 0; i < size; i++)
	{
		if (army.getMonster(i)->checkWillBeDamaged()>0)
		{
			cout << army.getMonster(i)->getName() << " will now take additional damage because of Vermin's ability!" << endl;
			army.getMonster(i)->takeDamage(army.getMonster(i)->getAdditionalDamage(), enemyarmy.exportVector(), enemyarmy.exportVector());
			army.getMonster(i)->setFutureDamage(army.getMonster(i)->checkWillBeDamaged() - 1);
		}
		if (army.getMonster(i)->checkIsShielded() > 0)
		{
			army.getMonster(i)->setShield(army.getMonster(i)->checkIsShielded() - 1);
		}

		if (army.getMonster(i)->checkIsFrozen() > 0)
		{
			army.getMonster(i)->setFreeze(army.getMonster(i)->checkIsFrozen() - 1);
		}

		if (army.getMonster(i)->checkIsStunned() > 0)
		{
			army.getMonster(i)->setStun(army.getMonster(i)->checkIsStunned() - 1);
		}
	}
}
bool attackFunction(int& x1, int& y1, int& x2, int& y2, Army &army1, Army &army2)
{
	if (validateCoords(x1, y1) && validateCoords(x2, y2) && unitIsInArmy(x1, y1, army1))
	{
		if (army1.getMonster(x1, y1)->checkIsStunned() > 0)
		{
			cout << "Unit cannot attack because it is stunned!" << endl;
			return 0;
		}

		if (army2.getMonster(x2, y2)->checkIsShielded() > 0)
		{
			cout << "Unit cannot be attacked because it is shielded!" << endl;
			return 0;
		}
		int feedback = army1.getMonster(x1, y1)->attackEnemy(army2.exportVector(), x2, y2, army1.exportVector());
		if (feedback == 1)
		{
			cout << "Target is out of range..." << endl;
			return 0;
		}
		if (feedback == 0)
		{
			cout << "Target doesn't really exist..." << endl;
			return 0;
		}
		return 1;
	}
	return 0;
}
bool moveFunction(int& x1, int& y1, int& x2, int& y2, Army &army1, Army &army2, shared_ptr<Hero>thisArmyHero)
{
	if (validateCoords(x1, y1) && validateCoords(x2, y2))
	{
		if (unitIsInArmy(x1, y1, army1))
		{
			if (army1.getMonster(x1, y1)->checkIsFrozen() > 0)
			{
				cout << "Unit cannot move because it is frozen!" << endl;
				return 0;
			}
			if (army1.getMonster(x1, y1)->checkIsStunned() > 0)
			{
				cout << "Unit cannot move because it is stunned!" << endl;
				return 0;
			}
			int feedback = army1.getMonster(x1, y1)->move(x2, y2, army1.exportVector(), army2.exportVector());

			if (feedback == 0)
			{
				cout << "Insufficient stamina..." << endl;
				return 0;
			}
			if (feedback == 1)
			{
				cout << "Position already taken..." << endl;
				return 0;
			}
			cout << "You have moved your " << army1.getMonster(x2, y2)->getName() << " from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ") !" << endl;
			return 1;
		}
		else
		{
			cout << "No unit in " << thisArmyHero->getName() << "'s army on the " << "(" << x1 << ", " << y1 << ") position" << endl;
			return 0;
		}
	}

	return 0;
}
int castMagic(int x, int y, Army army1, Army army2, string magic, shared_ptr<Hero>currentPlayerHero)
{
	if (currentPlayerHero->gethp() > 0)
	{
		if (currentPlayerHero->checkIsStunned() == 0)
		{
			return currentPlayerHero->cast(magic, x, y, army2.exportVector(), army1.exportVector());
		}
		return 11;// hero is stunned
	}
	return 10;//hero is dead
}
bool actionFunction(Army &army1, Army &army2, string input, shared_ptr<Hero>currentPlayerHero)
{
	if (input == "wait")
	{
		return 1;
	}
	if (input == "move")
	{
		int x1, x2, y1, y2;

		cout << "Coords of unit to be moved:" << endl;
		cout << "X:"; cin >> x1;
		cout << "Y:"; cin >> y1;
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			return 0;
		}
		cout << getUnit(x1, y1, army1.exportVector())->getName() << "'s stamina is:" << getUnit(x1, y1, army1.exportVector())->getStamina() << endl;
		cout << "Destination coords:" << endl;
		cout << "X:"; cin >> x2;
		cout << "Y:"; cin >> y2;
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			return 0;
		}

		if (!moveFunction(x1, y1, x2, y2, army1, army2, currentPlayerHero))
		{
			return 0;
		}

		return 1;


	}
	//------------------------------------------------------------------------------------------------------------------------------------------
	//moving finishes here
	if (input == "attack")
	{
		int x1, x2, y1, y2;

		cout << "Coords of attacking unit:" << endl;
		cout << "X:"; cin >> x1;
		cout << "Y:"; cin >> y1;
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			return 0;
		}


		cout << getUnit(x1, y1, army1.exportVector())->getName() << " range is: " << getUnit(x1, y1, army1.exportVector())->getRange() << endl;

		cout << "Victim coords:" << endl;
		cout << "X:"; cin >> x2;
		cout << "Y:"; cin >> y2;
		if (!cin)
		{
			cin.clear();
			cin.ignore();
			return 0;
		}
		//cin hasn't been blown

		if (!attackFunction(x1, y1, x2, y2, army1, army2))
		{
			return 0;
		}
		else
		{
			return 1;
		}
		//attack might just be over or something
		//-------------------------------------------------------------------------------------------------------------
	}
	if (input == "cast")
	{
		currentPlayerHero->magicList();
		cout << "Which magic would you like to cast?" << endl; cin >> input;

		int x, y;
		cout << "Input target coordinates:" << endl;
		cout << "X:"; cin >> x;
		cout << "Y:"; cin >> y;
		if (validateCoords(x, y))
		{
			int value = castMagic(x, y, army1, army2, input, currentPlayerHero);
			if (value == 10)
			{
				cout << "Dead heroes can't really cast spells..." << endl;
				return 0;
			}
			if (value == 0)
			{
				cout << "Invalid target..." << endl;
				return 0;
			}
			if (value == 1)
			{
				cout << "Insufficient mana..." << endl;
				return 0;
			}
			if (value == 11)
			{
				cout << "Hero is stunned..." << endl;
				return 0;
			}
			if (value == 12)
			{
				cout << "Target is protected..." << endl;
				return 0;
			}
			if (value == 3)
			{
				cout << currentPlayerHero->getName() << " cannot perform this magic..." << endl;
			}
			return 1;
		}
		else
		{
			cout << "Incorrect coordinates, retry input..." << endl;
			return 0;
		}

	}
	cout << "Unrecognized command..." << endl;
	return 0;

}
shared_ptr<Hero> chooseHeroClass(shared_ptr<Hero>&player)
{
	while (true)
	{
		cout << "What type of hero is " << player->getName() << " going to be? Insert 0 for \"Warrior\" and 1 for \"Mage\"" << endl;
		//shared_ptr<Hero> temp(new Hero());
		unsigned int inType;
		cin >> inType;
		while (!cin)
		{
			cin.clear();
			cin.ignore();
			cout << "Retry type input" << endl;
			continue;
		}
		if (inType >= Type::UnknownType)
		{
			cout << "Retry type input" << endl;
			continue;
		}
		else
		{
			if (inType == 0)
			{
				player->setType((Type)inType);
				shared_ptr <Warrior> temp(new Warrior(*player));
				//player = temp;
				return temp;
			}
			if (inType == 1)
			{
				player->setType((Type)inType);
				shared_ptr <Mage> temp(new Mage(*player));
				//player = temp;
				return temp;
			}
		}
	}
}
bool loadHero(shared_ptr<Hero> P1, string player1)
{
	string selection;
	if (P1->load(player1))
	{
		cout << "Player 1 loaded!" << endl;
		return 1;
	}

	cout << "Player not found! Would you like to add your own character with the given name? Select 'Y' for \"Yes\" and anything else for \"No\"." << endl;
	cin >> selection;

	if (selection == "Y")
	{
		P1->createHero(player1);
		cin.clear();
		cin.ignore();
		return 1;
	}
	cin.clear();
	cin.ignore();
	return 0;
}
bool setRace(shared_ptr<Hero> P1)
{

	unsigned int inrace;
	cout << "Choose " << P1->getName() << " race( 0 = Heaven, 1 = Inferno):" << endl;
	cin >> inrace;
	while (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "Retry race input" << endl;
		return 0;
	}
	if (inrace >= Race::UnknownRace)
	{
		cout << "Retry race input" << endl;
		return 0;
	}
	else
	{
		P1->setRace((Race)inrace);
	}
	return 1;
}
