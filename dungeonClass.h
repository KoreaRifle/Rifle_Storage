#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<vector>
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
	char _dungeonName[32];
	char _name[32];
	int _roleNum;
	char _roleName[32];
	int _hp;
	int _mp;
	int _pwr;
	int _dex;
	int _intel;
public:
	void dungeonMain(void);
	void enterDungeon(int dungeonNum, char dungeonName[32]);
	void setMonster(void);
	void charactorStatus(int roleNum, char name[32], int hp, int mp, int pwr, int dex, int intel);
	void userInterface(void);
	dungeonClass();
	~dungeonClass();
};