#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<vector>
#include "MainMenu.h"
#include "userStats.h"

using namespace std;

enum DUNGEONLIST
{
	DUNGEON1 = 1,
	DUNGEON2,
	DUNGEON3,
	DUNGEON4,
	LISTEND
};

struct tagMONSTERSTATS
{
	DUNGEONLIST dl;
	int callNum;
	char name[32];
	int hp;
	int pwr;
	int dex;
	int exp;
	int money;
};

class dungeonClass
{
private:
	vector<tagMONSTERSTATS> _monster;
	vector<tagMONSTERSTATS>::iterator _vMonster;
	MainMenu mm;
	userStats us;
	char _dungeonName[32];
	char _name[32];
	int _roleNum;
	char _roleName[32];
	int _max_hp;
	int _hp;
	int _max_mp;
	int _mp;
	int _pwr;
	int _dex;
	int _intel;
	int _exp;
	int _totalExp;
public:
	void dungeonMain(void);
	void enterDungeon(int dungeonNum, char dungeonName[32]);
	void setMonster(void);
	void charactorStatus(int roleNum, char name[32], int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int totalExp);
	void monsterAttack(void);
	void userInterface(void);
	void attackPoint(void);
	dungeonClass();
	~dungeonClass();
};