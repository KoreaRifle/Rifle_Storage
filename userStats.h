#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>
#include "dungeonClass.h"

using namespace std;

class userStats
{
private:
	int _level = 1;
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
	dungeonClass dg;
public:
	void charactorStatus(int roleNum, char name[32], int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int totalExp);
	void userInfo(void);
	void levelUp(int exp);
	userStats();
	~userStats();
};

