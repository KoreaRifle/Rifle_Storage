#pragma once
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

class userStats
{
private:
	int _level;
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
	int _money;
public:
	void charactorStatus(int roleNum, char name[32], int level, int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel, int exp, int totalExp, int money);
	void userInfo(void);
	void userInfo_pageNum(int pageNum, int totalPageNum);
	void levelUp(int exp);
	userStats();
	~userStats();
};

