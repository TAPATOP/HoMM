#pragma once
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include"Hero.h"
#include"Unit.h"
#include"Monster.h"
#include"Peasant.h"

using namespace std;

int ChooseHeroes()
{
	cout << "Input player 1 name:"; getline(cin, player1);

	if (P1.loadHero(player1)) cout << "Player 1 loaded!" << endl;
	else
	{
		cout << "Player 1 not found! Would you like to add your own character with the given name? Select 'Y' for \"Yes\" and anything else for \"No\"." << endl;
		cin >> selection;
		if (selection == "Y")
		{
			P1.createHero(player1);
			cin.clear();
			cin.ignore();
		}
		else
		{
			cin.clear();
			cin.ignore();
			continue;
		}
	}
	cout << "Input player 2 name:"; getline(cin, player2);
	if (P2.loadHero(player2)) cout << "Player 2 loaded!" << endl;
	else
	{
		cout << "Player 2 not found! Would you like to add your own character with the given name? Select 'Y' for \"Yes\" and anything else for \"No\"." << endl;
		cin >> selection;
		if (selection == "Y")
		{
			P2.createHero(player2);
			cin.clear();
			cin.ignore();
		}
		else
		{
			cin.clear();
			cin.ignore();
			continue;

		}
	}
}
