#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "MainMenu.h"

using namespace std;

class innClass
{
private:
	char _name[32];
	int _level;
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
	int _money;
public:
	void innMenu(void);
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int exp, int totalExp, int money);
	innClass();
	~innClass();
};

