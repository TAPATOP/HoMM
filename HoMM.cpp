// HoMM.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<memory>
#include<vector>
#include<windows.h>

#include"Hero.h"
#include"Unit.h"
#include"Peasant.h"
#include"Brute.h"
#include"Imp.h"
#include"Vermin.h"
#include"Archangel.h"
#include"Angel.h"
#include"Archer.h"
#include"Crossbowman.h"
#include"HornedDemon.h"
#include"HornedGrunt.h"
#include"Devil.h"
#include"ArchDevil.h"
#include"Army.h"
#include"Warrior.h"
#include"Mage.h"
#include"Functions.h"


using namespace std;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE);

	string input;
	do
	{
		do
		{
			string player1, player2;
			int startingGold1;
			int startingGold2;
			shared_ptr<Hero>P1(new Hero());
			shared_ptr <Hero>P2(new Hero());
			string selection;
			Army army1, army2;
			string waste;
			int startingHp1=0;
			int startingHp2=0;
			//vvvvvvvvvvvvvvvvv  hero adding vvvvvvvvvvvvvvvvvvvvv//

			cout << "Input player 1 name:"; getline(cin, player1);
			
			while (!loadHero(P1, player1));
			setPosition(*P1, army1, army2, *P1, *P2,3,0);
			startingHp1 = P1->gethp();
			//^^^^^^^^^^^^^^^^^^^^^^^^ P1 set ^^^^^^^^^^^^^^^^^^^^^^^^^^

			getline(cin, waste);
			cout << "Input player 2 name:"; getline(cin, player2);
			
			while (!loadHero(P2, player2));
			setPosition(*P2, army2, army1, *P1, *P2,7,1);
			startingHp2 = P2->gethp();
			//^^^^^^^^^^^^^^^^^^^^^^^ P2 set ^^^^^^^^^^^^^^^^^^^^^^^^^^^^

			while (!setRace(P1));
			while (!setRace(P2));

			//^^^^^^^^^^^^^^^^^^^^ Races set ^^^^^^^^^^^^^^^^^^^^^^^^^^

			//^^^^^^^^^^^^^^^^Race and Hero^^^^^^^^^^^^^^^^^^^^^^
			while (!(P1 = chooseHeroClass(P1)))
			{
				cout << "Unrecognized class!" << endl;
			}
			cout << P1->getName() << " is now a " << P1->displayType() << endl;
			army1.addUnit(P1);

			while (!(P2 = chooseHeroClass(P2)))
			{
				cout << "Unrecognized class!" << endl;
			}
			cout << P2->getName() << " is now a " << P2->displayType() << endl;
			army2.addUnit(P2);
			//^^^^^^^^^^^^^^^^^^^^^^^^ choosing type ^^^^^^^^^^^^^^^^^^^^^^

			getline(cin, waste);
			bool flush = 0;//removes bad input
			cout << "Player 1 turn to purchase:" << endl;

			startingGold1 = P1->getgold();
			startingGold2 = P2->getgold();

			while (true)//P1 purchase
			{
				if (flush)
				{
					getline(cin, waste);
					flush = 0;
				}
				cout << "Enter command:( \"buy\" or \"stop\")" << endl;

				getline(cin, input, '\n');
				if (input == "buy")
				{
					if (buyFunct(*P1, input, army1))
					{
						setPosition(*army1.getMonster(army1.getSize() - 1), army1, army2, *P1, *P2, 3, 0);
						flush = 1;
					}
				}
				else if (input == "stop") break;
				else cout << "Unrecognized command..." << endl;
			}

			flush = 0;// removes bad input
			cout << "Player 2 turn to purchase:" << endl;

			while (true)//P2 purchase
			{
				if (flush)
				{
					getline(cin, waste);
					flush = 0;
				}

				cout << "Enter command:( \"buy\" or \"stop\")" << endl;

				getline(cin, input, '\n');
				if (input == "buy")
				{
					if (buyFunct(*P2, input, army2))
					{
						setPosition(*army2.getMonster(army2.getSize() - 1), army1, army2, *P1, *P2, 7, 1);
						flush = 1;
					}
				}
				else if (input == "stop") break;
				else cout << "Unrecognized command..." << endl;
			}
			//------------------------------buying--------------------------------
			int startingSize1 = army1.getArmySize();
			int startingSize2 = army2.getArmySize();

			cout << endl;
			cout << P1->getName() << "'s army size:" << startingSize1 << endl;
			cout << P2->getName() << "'s army size:" << startingSize2 << endl;
			cout << endl;


			cout << "Battle begins!" << endl;
			flush = 0;
			//---------------------------------------------------------------------------------------------------------------
			while (!army1.isDestroyed() && !army2.isDestroyed())//battle cycle
			{
				while (true)
				{
					displayBattlefield(*P1, *P2, army1, army2);
					cout << "It's Player1's turn!" << endl << "Input your command( move, attack, cast or wait): "; cin >> input;
					if (!actionFunction(army1, army2, input, P1))
					{
						cout << "Try again..." << endl;
						continue;
					}
					cout << "End of Player 1's turn" << endl<<endl;
					break;
				}
				//-----------------P1 action--------------------------
				while (!army1.isDestroyed() && !army2.isDestroyed())
				{
					displayBattlefield(*P1, *P2, army1, army2);
					cout << "It's Player2's turn!" << endl << "Input your command( move, attack, cast or wait): "; cin >> input;
					if (!actionFunction(army2, army1, input, P2))
					{
						cout << "Try again..." << endl;
						continue;
					}
					cout << "End of Player 2's turn" << endl << endl;
					break;
				}
				//-----------P2 action----------------------
				endTurnThings(army1, army2, *P1);
				endTurnThings(army2, army1, *P2);
			}
			cout << endl << endl << "Battle is over! ";

			P1->setGold(startingGold1);
			P2->setGold(startingGold2);

			P1->sethp(startingHp1);
			P2->sethp(startingHp2);

			cout << P1->getName() << " has gained " << startingSize2 - army2.getArmySize() << " exp!" << endl;
			cout << P2->getName() << " has gained " << startingSize1 - army1.getArmySize() << " exp!" << endl;

			if (army1.isDestroyed())
			{
				cout << P2->getName() << "'s army is victorious!" << endl;
				P1->postBattleEffects(startingSize2 - army2.getArmySize(), 0);
				P2->postBattleEffects(startingSize1 - (army1.getArmySize()), 1);
			}
			else
			{
				cout << P1->getName() << "'s army is victorious!" << endl;
				P1->postBattleEffects(startingSize2 - army2.getArmySize(), 1);
				P2->postBattleEffects(startingSize1 - army1.getArmySize(), 0);
			}
			cout << endl;
			P1->save();
			P2->save();

			cout<<"Would you like to fight another battle ? Input \"stop\" for \"No\" or anything else for \"Yes\":" << endl;
			cin >> input;
			 getline(cin, waste);
			 if (input == "stop")
			 {
				 break;
			 }
		}while (true);
	}
	while (input != "stop");//end of menu
	return 0;
}