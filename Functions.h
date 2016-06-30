#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<memory>

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

#include<vector>


void setPosition(Unit& monster, Army& army1, Army& army2, Hero& P1, Hero& P2);
void setPosition(Unit& monster, Army& army1, Army& army2, Hero& P1, Hero& P2, int ylimit, bool oneMeansToTheRight);
shared_ptr<Unit> createACreature(Hero &hero, string type);
bool buyFunct(Hero &player, string input, Army &army);
bool unitIsInArmy(int x, int y, Army &army);
void displayBattlefield(Hero& P1, Hero& P2, Army& army1, Army& army2);
void endTurnThings(Army& army, Army& enemyarmy, Hero& thisHero);
bool attackFunction(int& x1, int& y1, int& x2, int& y2, Army &army1, Army &army2);
bool moveFunction(int& x1, int& y1, int& x2, int& y2, Army &army1, Army &army2, shared_ptr<Hero>thisArmyHero);
int castMagic(int x, int y, Army army1, Army army2, string magic, shared_ptr<Hero>currentPlayerHero);
bool actionFunction(Army &army1, Army &army2, string input, shared_ptr<Hero>currentPlayerHero);
shared_ptr<Hero> chooseHeroClass(shared_ptr<Hero>&player);
bool loadHero(shared_ptr<Hero> P1, string player1);
bool setRace(shared_ptr<Hero> P1);
