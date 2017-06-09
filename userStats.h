#pragma once
#include <iostream>
#include<time.h>
#include<Windows.h>

using namespace std;

class userStats
{
private:
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
public:
	void charactorStatus(int roleNum, char name[32], int max_hp, int hp, int max_mp, int mp, int pwr, int dex, int intel);
	void userInfo(void);
	void userInterface(void);
	userStats();
	~userStats();
};

