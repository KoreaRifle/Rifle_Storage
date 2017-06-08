#pragma once
#include<iostream>
#include<time.h>
#include<Windows.h>
#include<vector>

using namespace std;

enum DUNGEONLIST
{
	TEMP1 = 1,
	TEMP2,
	TEMP3,
	TEMP4,
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
public:
	void enterDungeon(int dungeonNum, char dungeonName[32]);
	void setMonster(void);
	dungeonClass();
	~dungeonClass();
};

